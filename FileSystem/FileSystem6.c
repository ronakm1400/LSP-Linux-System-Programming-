/*
	Write a program which accepts file name from user and read whole file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define BUF_SIZE 1024

void readWholeFile(char *argv[])
{

	auto int openFd = 0;
	auto ssize_t readRet = 0;
	auto char localBuf[BUF_SIZE] = {'\0'};
	
	openFd = open(argv[1],O_RDONLY);
	if(openFd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}	
	
	printf("\n----------------------------------------------------------------------------------------\n");	
	while((readRet = read(openFd,localBuf,BUF_SIZE)) != 0)
	{
		write(1,localBuf,readRet);
		memset(localBuf,0,BUF_SIZE);
	}
	printf("----------------------------------------------------------------------------------------\n");
	
	if(readRet == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	
	if(close(openFd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}

}

int main(int argc,char *argv[])
{
	void readWholeFile(char **);
	
	if(argc != 2)
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		exit(EXIT_FAILURE);			
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to read the whole data from the file\n");
		exit(1);	
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s File_Name\n",argv[0]);
		exit(1);		
	}
	
	readWholeFile(argv);		
	
	exit(EXIT_SUCCESS);

}
