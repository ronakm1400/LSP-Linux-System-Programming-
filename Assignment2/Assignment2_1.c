//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement	: Write a program which accept file name from user and read whole file.	
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0
#define BUFFERSIZE 1024

typedef signed int SINT;

int main(int argc,char *argv[])
{
	fflush(stdin);
	
	auto SINT fd = 0,iRet = 0;
	auto char Buffer[BUFFERSIZE] = {'\0'};
	
	if(argc != 2)
	{
		printf("Invalid number of arguments!\n");
		printf("Press --h or --H for Help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--h") == 0))
	{
		printf("Help	: This application is used to read data from file\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable	FileName\n");
		exit(SUCCESS);
	}
	
	fd = open(argv[1],O_RDONLY);
	if(fd == FAILURE)
	{
		printf("Cannot open file\n");
		exit(FAILURE);
	}	
	
	printf("Data from file is : \n\n");
	while( (iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
	{
		printf("%s\t",Buffer);
		memset(Buffer,0,sizeof(Buffer));
	}
	close(fd);

	exit(EXIT_SUCCESS);

}
