////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement : Write a application which accept directory name from user and print name of such a file
//			    having largest file size.		
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>

#define SUCCESS 1
#define FAILURE -1

#define BUF_SIZE 1024

#define EXIT_SUCCESS 0


void displayFileMax_Size(char *argv[])
{
	auto int iMax = 0;
	auto char Name[BUF_SIZE] = {'\0'};
	auto char cpName[BUF_SIZE] = {'\0'};
	
	auto struct stat sObj;
	auto DIR *dPtr = NULL;
	auto struct dirent *dEntry = NULL;
	
	dPtr = opendir(argv[1]);
	
	if(dPtr == NULL)
	{
		printf("Cannot open file\n");
		printf("No such directory\n");
		exit(FAILURE);	
	}
	
	while((dEntry = readdir(dPtr)) != NULL)
	{
		sprintf(Name,"%s/%s",argv[1],dEntry->d_name);
		stat(Name,&sObj);
		if(S_ISREG(sObj.st_mode))
		{
			if(iMax < sObj.st_size)
			{
				iMax = sObj.st_size;
				strcpy(cpName,Name);
			}
		}
			
	}
	printf("File name = %s \nSize 	  = %d bytes\n",cpName,iMax);
	closedir(dPtr);
}

int main(int argc,char *argv[])
{

	if(argc != 2)
	{
		printf("Invalid number of arguments!\n");
		printf("Press --h or --H for Help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help	: This application is used to print name of file having maximum file size\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable	Directory_Name\n");
		exit(SUCCESS);	
	}
	
	displayFileMax_Size(argv);

	exit(EXIT_SUCCESS);	

}
