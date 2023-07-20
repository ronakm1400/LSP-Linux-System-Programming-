//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement : Write a program which accepts two directory names from user and move all files	
//			    from one source directory to destination directory.	
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>

#define SUCCESS 1
#define FAILURE -1

#define BUFSIZE 1024

#define EXIT_SUCCESS 0


void mvFilesFromSourceToDest(char *argv[])
{	
	
	char oldPath[BUFSIZE] = {'\0'};
	char newPath[BUFSIZE] = {'\0'};
	
	auto DIR *dPtr = NULL;
	struct dirent *dEntry = NULL;
	
	dPtr = opendir(argv[1]);
	if(dPtr == NULL)
	{
		printf("Cannot open directory\n");
		exit(FAILURE);
	}
	
	while((dEntry = readdir(dPtr)) != NULL)
	{
		sprintf(oldPath,"%s/%s",argv[1],dEntry->d_name);
		sprintf(newPath,"%s/%s",argv[2],dEntry->d_name);
		
		rename(oldPath,newPath);
	}
	closedir(dPtr);	
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
		printf("Help	: This application is used to move all files from source directory to destination directory\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable  Source_Directory_Name  Destination_Directory_Name\n");
		exit(SUCCESS);	
	}
	
	mvFilesFromSourceToDest(argv);
	
	exit(EXIT_SUCCESS);	

}
