////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement	: Write a program which accepts file name from user and mode from user and open 
//						  that file in specified mode.	
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

int main(int argc,char *argv[])
{
	
	auto signed int fd = 0,fMode = 0; 
	
	if( (argc == 1) || (argc > 3))
	{
		printf("Invalid Input!\n");
		printf("Press --h or --H for Help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help : This application is used to open an existing file\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage 		: Name_Of_Executable   File_Name   File_Mode\n");
		printf("File Modes	: Read,Write,Read_Write\n");	
		exit(SUCCESS);
	}
	
	if(strcmp(argv[2],"Read")==0) 
	{
		fMode = O_RDONLY;
	} 
	else if(strcmp(argv[2],"Write")==0)
	{
		fMode = O_WRONLY;
	}
	else
	{
		fMode = O_RDWR;
	}
	
	fd = open(argv[1],fMode);
	
	if(fd == FAILURE)
	{
		printf("Unable to open file\n");
		exit(FAILURE);
	}
	else
	{
		printf("File opened with file descriptor : %d\n",fd);
		exit(SUCCESS);
	}
	
	exit(EXIT_SUCCESS);

}
