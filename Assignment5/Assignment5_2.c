//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem statement	: Write a application which writes structure in file. Structure should contains
//				  information Employee. 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define SUCCESS 1
#define FAILURE -1

#define BUF_SIZE 1024

#define EXIT_SUCCESS 0

#pragma pack(1)
struct Employee 
{
	int employeeId;
	char employeeNm[BUF_SIZE];
	char place[BUF_SIZE];
	int employeeAge;
};

void readStructure(char *argv[])
{
	auto int fd = 0;		
	auto struct Employee eObj;
	
	fd = open(argv[1],O_RDONLY);
	if(fd == FAILURE)
	{
		printf("Cannot create file\n");
		printf("File already exists\n");
		exit(FAILURE);
	} 	
	
	read(fd,&eObj,sizeof(eObj));
	
	printf("Employee Id	: %d\n",eObj.employeeId);
	printf("Employee Name	: %s\n",eObj.employeeNm);
	printf("Employee Age	: %d\n",eObj.employeeAge);
	printf("City		: %s\n",eObj.place);

	close(fd);
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
		printf("Help	: This application is used to write a structure into a file\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable  File_Name\n");
		exit(SUCCESS);
	}

	readStructure(argv);	
	
	exit(EXIT_SUCCESS);

}


