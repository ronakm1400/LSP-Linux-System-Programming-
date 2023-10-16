/*
	Write a program which accept file name from user and position from user and read 20 bytes from that position.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

void readDataFromPos(char *argv[])
{
	auto off_t file_offset = 0;
	auto int openFd = 0,readRet = 0;
	
	auto char localBuf[BUFSIZ] = {'\0'};
	
	openFd = open(argv[1],O_RDONLY);
	if(openFd == -1)
	{
		perror("open");
		_exit(EXIT_FAILURE);
	}	
	
	file_offset = lseek(openFd,atoi(argv[2]),SEEK_CUR);
	if(file_offset == -1)
	{
		perror("lseek");
		_exit(EXIT_FAILURE);
	}
	
	readRet = read(openFd,localBuf,20);
	if(readRet == -1)
	{
		perror("read");
		_exit(EXIT_FAILURE);
	}
	
	printf("20 bytes data read from file is : \n");
	
	if(write(1,localBuf,sizeof(localBuf)) == -1)
	{
		perror("write");
		_exit(EXIT_FAILURE);
	}
	
	printf("\n");
	
	if(close(openFd) == -1)
	{
		perror("close");
		_exit(EXIT_FAILURE);
	}
	
}

int main(int argc,char *argv[])
{
	
	void readDataFromPos(char **);	

	if((argc <= 1) || (argc > 3))
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to read data from the position user wants\nNote : This application reads only 20 bytes of data from the given position\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s File_Name Position_To_Read_Data\n",argv[0]);
	}

	readDataFromPos(argv);

	exit(EXIT_SUCCESS);

}
