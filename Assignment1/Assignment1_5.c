//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		Problem Statement	: Write a program which accept file name and number of bytes from user and
//					  read that number of bytes from file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

typedef signed int SINT;

int main(int argc,char *argv[])
{
	fflush(stdin);
	
	auto SINT fd = 0,iRet = 0,iSize = 0;
	auto char *Buf = NULL;
	
	if( (argc == 1) || (argc > 3))
	{
		printf("Invalid Input!\n");
		printf("Press --h or --H for Help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help : This application is used to read data from an existing file\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage 		: Name_Of_Executable   File_Name   Number_Of_Bytes\n");
		exit(SUCCESS);
	}
	
	fd = open(argv[1],O_RDONLY);
	
	if(fd == FAILURE)
	{
		printf("Cannot open file\n");
		exit(FAILURE);
	}
	
	iSize = atoi(argv[2]);
	
	Buf = (char *)malloc(sizeof(iSize));
	
	iRet = read(fd,Buf,atoi(argv[2]));
	if(iRet == 0)
	{
		printf("Unable to read data from file");
		exit(FAILURE);
	}
	
	printf("Data from file is : \n");
	write(1,Buf,iRet);
	printf("\n");
	
	exit(EXIT_SUCCESS);

}
