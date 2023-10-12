/*
	Write a program which accepts file name from user and number of bytes from user and read that number 
	of bytes from file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void readDataFromFile(char *argv[])
{	
	auto int openFd = 0;
	auto ssize_t readRet = 0;
	auto char *localBuf = NULL;
	
	openFd = open(argv[1],O_RDONLY);
	if(openFd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}		
	
	localBuf = (char *)malloc(sizeof(atoi(argv[2])));
	if(localBuf == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
		
	readRet = read(openFd,localBuf,atoi(argv[2]));	
	if(readRet == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	
	if(write(1,localBuf,readRet) == -1)
	{
		perror("write");
	}
	printf("\n");		
	
	if(localBuf)
	{
		free(localBuf);
	}
	
	if(close(openFd) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}	
	
}

int main(int argc,char *argv[])
{
	void readDataFromFile(char **);	

	if((argc <= 1) || (argc > 3))
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press --h or --H for Help\n");
		fprintf(stderr,"Press --u or --U for Usage\n");
		exit(EXIT_FAILURE);
	}	
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help : This application is used to open an existing file and read the amount of data that user wants to read.\n");
		exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage : %s  File_Name  Number_Of_Bytes\n",argv[0]);
		exit(1);
	}
	
	readDataFromFile(argv);	
		
	exit(EXIT_SUCCESS);

}
