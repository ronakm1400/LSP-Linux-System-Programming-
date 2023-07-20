/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement	: Write a program which accept file name from user and write a string in that file.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 1
#define FAILURE -1

#define CHAR_SIZE 50
#define BUF_SIZE 100 

#define EXIT_SUCCESS 0


typedef signed int SINT;

int main(int argc,char *argv[])
{
	fflush(stdin);

	auto SINT fd = 0,iRet = 0;
	auto char fName[CHAR_SIZE] = {'\0'};
	auto char Buffer[BUF_SIZE] = {'\0'};
	
	printf("Enter file name in which you want to write data : ");
	scanf("%s",fName);
		
	fd = open(fName,O_RDWR);
	
	if(fd == FAILURE)
	{
		printf("Cannot open file!\n");
		exit(FAILURE);
	}
	else
	{
		printf("File opened with file descriptor : %d\n",fd);
	}
	
	printf("Enter string that you want to write  : ");
	scanf(" %[^\n]s",Buffer);
	
	iRet = write(fd,Buffer,strlen(Buffer));
	printf("%d bytes gets successfully written in the file\n",iRet);
	
	close(fd);

	exit(EXIT_SUCCESS);
	
}
