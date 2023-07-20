////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement	: Write a program which accepts file name from user and open that file	
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

int main(int argc,char *argv[])
{
	fflush(stdin);
	
	auto signed int fd = 0;
	
	if(argc != 2)
	{
		printf("Invalid Input!\n");
		printf("Press --h or --H for help\n");
		printf("Press --u or --U for usage\n");
		exit(FAILURE);
	}
	
	if( (strcmp(argv[1],"--h")==0) || (strcmp(argv[1],"--H")==0) )
	{
		printf("Help : This application is used to open an existing file\n");
		exit(SUCCESS);
	}
	else if( (strcmp(argv[1],"--u")==0) || (strcmp(argv[1],"--U")==0) )
	{
		printf("Usage : Name_Of_Executable 	File_Name\n");
		exit(SUCCESS);
	}
		
	fd = open(argv[1],O_RDONLY);	
	
	if(fd == FAILURE)
	{
		printf("Cannot open file!\n");
		exit(FAILURE);
	}
	else
	{
		printf("File opened successfully with file descriptor : %d\n",fd);
	}
	
	close(fd);
	
	exit(EXIT_SUCCESS);

}
