///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Problem Statement	: Write a program which accept file name and mode from user and check 
//					  whether calling process can access that file in accepted mode or not.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0


typedef signed int SINT;

int main(int argc,char *argv[])
{
	fflush(stdin);

	auto SINT fMode = 0;
	
	if((argc == 1) || (argc > 3))
	{
		printf("Invalid number of arguments!\n");
		printf("Press --h or --H for help\n");
		printf("Press --u or --U for usage\n");
		exit(FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help	: This application is used to check the mode of file\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage 		: Name_Of_Executable	File_Name	Mode_Of_File\n");
		printf("File Modes	: Read,Write,Read_Write\n");	
		exit(SUCCESS);
	}
	
	if(strcmp(argv[2],"Read")==0)
	{
		mode = R_OK;
	}
	else if(strcmp(argv[2],"Write")==0)
	{
		mode = W_OK;
	}
	else if(strcmp(argv[2],"Execute")==0)
	{
		mode = X_OK;
	}
	
	if(access(argv[1],mode) < 0)
	{
		printf("Unable to access %s file in %s mode\n",argv[1],argv[2]);
	}
	else
	{
		printf("You can access %s file in %s mode\n",argv[1],argv[2]);
	}

	exit(EXIT_SUCCESS);

}
