///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement  : Write a application which accept directory name from user and write information of all
//			     regular files in a file then read the contents from that file. 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#define SUCCESS 1
#define FAILURE -1

#define BUF_SIZE 1024

#define EXIT_SUCESS 0

#pragma pack(1)
struct FileInfo
{
	int fSize;
	int fLink;
	int fsNum;
	int iNodenum;
	int no_of_blocks;
	char fName[BUF_SIZE];

};

void readWriteInfo(char *argv[])
{
	auto int fd = 0;
	auto char pathNm[BUF_SIZE] = {'\0'};
	auto char Buffer[BUF_SIZE] = {'\0'};
	
	auto struct stat sObj;
	auto struct FileInfo fObj;

	auto DIR *dPtr = NULL;
	auto struct dirent *dEntry = NULL;
	
	dPtr = opendir(argv[1]);

	if(dPtr == NULL)
	{
		printf("Cannot open directory\n");
		printf("No such directory\n");
		exit(FAILURE);
	}
	
	fd = creat("FileInfo.txt",0777);
	if(fd == FAILURE)
	{
		printf("Cannot create file\n");
		exit(FAILURE);
	}
	
	while((dEntry = (readdir(dPtr))) != NULL)
	{
		sprintf(pathNm,"%s/%s",argv[1],dEntry->d_name);
		stat(pathNm,&sObj);
		if(S_ISREG(sObj.st_mode))
		{
			strcpy(fObj.fName,dEntry->d_name);
			fObj.fSize = sObj.st_size;
			fObj.fLink = sObj.st_nlink;
			fObj.fsNum = sObj.st_dev;
			fObj.iNodenum = sObj.st_ino;
			fObj.no_of_blocks = sObj.st_blocks;
			write(fd,&fObj,sizeof(fObj));
		}
	}	
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
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--h") == 0))
	{
		printf("Help	: This application is used to store information of all regular files into a text file and read the contents of text file\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable  Directory_Name\n");
		exit(SUCCESS);
	}
	
	readWriteInfo(argv);

	exit(EXIT_SUCESS);
}
