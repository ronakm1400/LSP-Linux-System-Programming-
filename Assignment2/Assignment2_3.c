////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement : Write a program which accept directory name from user and print all file names from 
//			    directory.	
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

void directoryListDisplay(char *argv[])
{
	auto DIR *dPtr = NULL;
	auto struct dirent *dEntry = NULL;
	
	dPtr = opendir(argv[1]);
	
	if(dPtr == NULL)
	{
		printf("Cannot open directory!\n");
		printf("No such directory!\n");
		exit(FAILURE);
	}
	else
	{
		printf("----------------------------------------------------------\n");
		printf("Entries in directory file are : \n");
		printf("----------------------------------------------------------\n");
		while((dEntry = readdir(dPtr)) != NULL)
		{
			printf("File Name : %s\n",dEntry->d_name);
		}
		printf("\n");
	}
	closedir(dPtr);
}

int main(int argc,char *argv[])
{	
	if(argc != 2)
	{
		printf("Invalid number of arguments!\n");
		printf("Press --h or --H for help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help	: This application is used to print all file names in directory\n");
		exit(SUCCESS);
	}	
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable 	Directory_Name\n");
		exit(SUCCESS);
	}
	
	directoryListDisplay(argv);
	
	exit(EXIT_SUCCESS);

}
