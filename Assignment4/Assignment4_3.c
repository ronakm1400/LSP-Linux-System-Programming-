//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement  : Write a application which accept two file names from user and check whether contents
//			       of that two files are equal or not.	
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 1
#define FAILURE -1

#define BUF_SIZE 1024

#define EXIT_SUCCESS 0

typedef signed int BOOL;
#define TRUE 1
#define FALSE 0

BOOL checkContentsOfFiles(char *argv[])
{
	auto char localBuf1[BUF_SIZE] = {'\0'};
	auto char localBuf2[BUF_SIZE] = {'\0'};
	
	register int iCnt = 0;
	auto int fileFD1 = 0,fileFD2 = 0,ireadRet = 0;
	
	auto struct stat sObj1,sObj2;	
	
	fileFD1 = open(argv[1],O_RDONLY);
	fileFD2 = open(argv[2],O_RDONLY);
	
	if((fileFD1 == FAILURE) || (fileFD1 == FAILURE))
	{
		printf("Cannot open file\n");
		exit(FAILURE);
	}
	
	fstat(fileFD1,&sObj1);
	fstat(fileFD2,&sObj2);
	
	if(sObj1.st_size != sObj2.st_size)
	{
		printf("Files are different as sizes as different\n");
		exit(FAILURE);
	}
	
	while((ireadRet = read(fileFD1,localBuf1,BUF_SIZE)) != 0)
	{
		iCnt++;

		ireadRet = read(fileFD2,localBuf2,BUF_SIZE);

		if(memcmp(localBuf1,localBuf2,ireadRet) != 0)
		{
			break;
		}

	}
	if(ireadRet == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

int main(int argc,char *argv[])
{

	auto BOOL bRet = FALSE;

	if((argc == 1) || (argc > 3))
	{
		printf("Invalid number of arguments\n");
		printf("Press --h or --H for Help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help	: This application is used to compare the data between two files\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable  File_Name1  File_Name2\n");
		exit(SUCCESS);
	}
	
	bRet = checkContentsOfFiles(argv);		
	if(bRet == TRUE)
	{
		printf("Files are identical\n");
		exit(SUCCESS);
	}
	else
	{
		printf("Files are different\n");
		exit(FAILURE);
	}
	exit(EXIT_SUCCESS);

}
