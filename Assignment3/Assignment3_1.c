///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement : Write a application which accept two files from user and copy the contents of an 
//			    existing file into new created file.	
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define SUCCESS 1
#define FAILURE -1

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

#define EXIT_SUCCESS 0

typedef signed int SINT;

void copyFileContents(char *argv[])
{
	auto SINT inputFd = 0,outputFd = 0,fOpenFlags = 0;
	auto mode_t fPermissions = 0;
	auto ssize_t numRead = 0;
	auto char Buffer[BUF_SIZE] = {'\0'}; 
	
	inputFd = open(argv[1],O_RDONLY);
	if(inputFd == FAILURE)
	{
		printf("Cannot open file\n");
		exit(FAILURE);	
	}
	
	fOpenFlags = O_CREAT | O_WRONLY | O_TRUNC;
	
	fPermissions = S_IRUSR  | S_IWUSR  | S_IRGRP  |  S_IWGRP  | S_IROTH  | S_IWOTH;
	
	outputFd = open(argv[2],fOpenFlags,fPermissions);
	if(outputFd == FAILURE)
	{
		printf("Cannot open file\n");
		exit(FAILURE);	
	}
	
	while((numRead = read(inputFd,Buffer,BUF_SIZE)) > 0)
	{		
		if(write(outputFd,Buffer,numRead) != numRead)
		{
			break;
		}
		
	}
	if(numRead == FAILURE)
	{
		printf("Couldn't write whole buffer\n");
		exit(FAILURE);		
	}
	
	if(close(inputFd) == FAILURE)
	{
		printf("Close input\n");
		exit(FAILURE);
	}	
	if(close(outputFd) == FAILURE)
	{
		printf("Close output\n");
		exit(FAILURE);
	}	
}

int main(int argc,char *argv[])
{

	if((argc == 1) || (argc > 3))
	{
		printf("Invalid number of arguments!\n");
		printf("Press --h or --H for Help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help	: This application is used to copy data from an existing file to another file\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable  Name_Of_Existing_File  Name_Of_Copy_File\n");
		exit(SUCCESS);	
	}
	
	copyFileContents(argv);

	exit(EXIT_SUCCESS);	

}
