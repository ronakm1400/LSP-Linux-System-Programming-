//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement	: Write a program which accept directory name from user and copy first 10 bytes 
//				  from all regular files into newly created file named as Demo.txt
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define SUCCESS 1
#define FAILURE -1

#define BUF_SIZE 1024

#define EXIT_SUCCESS 0


#pragma pack(1)
struct FileInfo
{
	char fName[BUF_SIZE];
	int fSize;
};

void copyFirstTenBytes(char *argv[])
{
	auto signed int fd = 0,iMax = 0;
	
	auto char name[BUF_SIZE] = {'\0'};
	auto char copyNm[BUF_SIZE] = {'\0'};
	
	auto DIR *dPtr = NULL;

	auto struct dirent *dEntry = NULL;
	auto struct stat sObj;
	auto struct FileInfo fObj;	
	
	dPtr = opendir(argv[1]);
	if(dPtr == NULL)
	{
		printf("Cannot open directory\n");
		printf("Directory doesn't exists!\n");
		exit(FAILURE);
	}
	
	fd = creat("Demo.txt",0777);
	if(fd == FAILURE)
	{
		printf("Failed to create file\n");
		exit(FAILURE);
	}
	
	while((dEntry = readdir(dPtr)) != NULL)
	{
		sprintf(name,"%s/%s",argv[1],dEntry->d_name);
		
		stat(name,&sObj);
		
		if(S_ISREG(sObj.st_mode))
		{
			fObj.fSize = sObj.st_size;
			strcpy(fObj.fName,dEntry->d_name);
			write(fd,&fObj,sizeof(fObj));
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
		printf("Help	: This application is used to copy first 10 bytes from all regular files into newly created file named as Demo.txt\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable  Directory_Name\n");
		exit(SUCCESS);
	}
	
	copyFirstTenBytes(argv);
	
	exit(EXIT_SUCCESS);

}
