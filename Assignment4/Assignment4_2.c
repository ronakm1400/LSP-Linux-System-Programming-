////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement  :  Write a application which accept directory name from user and create new directory
//				of that name.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

void createDir(char *argv[])
{
	fflush(stdin);
	
	auto int fd = 0;
	
	fd = mkdir(argv[1],0777);
	if(fd == FAILURE)
	{
		printf("Cannot create directory\n");
		printf("Directory already exists\n");
		exit(FAILURE);
	}	
	
}

int main(int argc,char *argv[])
{

	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		printf("Press --h or --H for Help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);	
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help 	: This application is used to create a new directory file\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable  Directory_Name\n");
		exit(SUCCESS);
	}
	
	createDir(argv);	
	
	exit(EXIT_SUCCESS);	

}
