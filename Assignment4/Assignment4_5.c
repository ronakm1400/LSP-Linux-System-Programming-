///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement  :  Write a application which accept file name and position from user and read 20 bytes 
//			      from that position.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<fcntl.h>

#define SUCCESS 1
#define FAILURE -1

#define BUF_SIZE 1024

#define EXIT_SUCCESS 0

void readBytes(char *argv[])
{

	auto int fd = 0,iRet = 0;
	auto char cArr[BUF_SIZE] = {'\0'};
	
	fd = open(argv[1],O_RDONLY);
	
	if(fd == FAILURE)
	{
		printf("Cannot open file\n");
		printf("File doesn't exists\n");
		exit(FAILURE);
	}
	
	iRet = lseek(fd,atoi(argv[2]),0);
	if(iRet == FAILURE)
	{
		printf("lseek\n");
		exit(FAILURE);
	}
	
	read(fd,cArr,20);
	
	printf("Data from file is : \n");
	printf("%s\n",cArr);
	
	close(fd);

}

int main(int argc,char *argv[])
{
	
	if((argc == 1) || (argc > 3))
	{
		printf("Invalid number of arguments\n");
		printf("Press --h or --H for Help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);
	}	
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))	
	{
		printf("Help	: This application is used to read 20 bytes of data from an existing file\n");
		exit(FAILURE);
	}	
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable  File_Name  OffSet_Position\n");
		exit(FAILURE);
	}
	
	readBytes(argv);
	
	exit(EXIT_SUCCESS);

}
