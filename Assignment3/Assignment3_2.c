////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement  : Write a program which accept directory name and file name from user and check whether	
//			     that file is present in that directory or not.	
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


void checkFilePresent(char *argv[])
{	
	char pathNm[BUFSIZE] = {'\0'};

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
		if(strcmp(argv[2],dEntry->d_name) == 0)
		{
			printf("File is present in directory\n");
			break;
		}
	}
	if(dEntry == NULL)
	{
		printf("There is no such file\n");
		exit(FAILURE);
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
		printf("Help	: This application is used to check whether the file is present in directory or not\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable  Directory_Name  Name_Of_File\n");
		exit(SUCCESS);	
	}
	
	checkFilePresent(argv);
	
	exit(EXIT_SUCCESS);	

}
