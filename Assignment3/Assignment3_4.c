/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement  : Write a application which accept directory name from user and delete all empty files 
//			     from that directory.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

#define SUCCESS 1
#define FAILURE -1

#define BUF_SIZE 1024

#define EXIT_SUCCESS 0

void deleteEmptyFiles(char *argv[])
{
	auto char fileNm[BUF_SIZE] = {'\0'};
	auto int iRet = 0;
	auto DIR *dPtr  = NULL;
	auto struct dirent *dEntry = NULL;
	auto struct stat sObj;
	
	dPtr = opendir(argv[1]);
	if(dPtr == NULL)
	{
		printf("Cannot open directory\n");
		exit(FAILURE);
	}
	
	while((dEntry = readdir(dPtr)) != NULL)
	{
		sprintf(fileNm,"%s/%s",argv[1],dEntry->d_name);
		stat(fileNm,&sObj); 
		if(S_ISREG(sObj.st_mode))
		{
			if((sObj.st_size) == 0)
			{
				printf("%s empty file deleted\n",fileNm);
				remove(fileNm);
			}
		}	
	}
	
	closedir(dPtr);

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
		printf("Help	: This application is used to delete empty files from directory\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable  Directory_Name\n");
		exit(SUCCESS);
	}
	
	deleteEmptyFiles(argv);
	
	exit(EXIT_SUCCESS);
	
}
