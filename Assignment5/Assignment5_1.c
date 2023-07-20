//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem statement	: Write a application which writes structure in file. Structure should contains
//				  information student. 
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
struct Student 
{
	int RollNo;
	char Sname[BUF_SIZE];
	float Marks;
	int Age;
};

void writeStructure(char *argv[])
{
	auto int fd = 0;		
	auto struct Student sObj;
	
	sObj.RollNo = 11;
	sObj.Marks  = 89.99f;
	sObj.Age    = 25;
	strcpy(sObj.Sname,"Ronak");
	
	fd = creat(argv[1],0777);
	if(fd == FAILURE)
	{
		printf("Cannot create file\n");
		printf("File already exists\n");
		exit(FAILURE);
	} 	
	
	write(fd,&sObj,sizeof(sObj));
	printf("Structure added successfully!\n");
	
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

	writeStructure(argv);	
	
	exit(EXIT_SUCCESS);

}	
