/*
	Write a program which writes structure in file. Structure should contains information of student.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#pragma pack(1)
struct studentInfo
{
	int 	iRollNo;
	int 	iAge;
	float 	fMarks;
	char 	sName[30];
	
};	

void writeStructureInFile(char *argv[])
{
	auto int createFd = 0,fPermissions = 0;
	auto struct studentInfo sObj;
	
	sObj.iRollNo = 11;
	sObj.iAge    = 25;
	sObj.fMarks  = 89.98f;		
	strcpy(sObj.sName,"Ronak");
	
	fPermissions = 	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	
	createFd = creat(argv[1],fPermissions);
	if(createFd == -1)
	{
		perror("creat");
		_exit(EXIT_FAILURE);
	}
	
	if((write(createFd,&sObj,sizeof(sObj))) == -1)
	{
		perror("write");
		_exit(EXIT_FAILURE);	
	}
	else 
	{
		fprintf(stdout,"Structure written in file\n");
	}
	
}

int main(int argc,char *argv[])
{

	void writeStructureInFile(char **);

	if(argc != 2)
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to write a structure inside a file\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s File_Name\n",argv[0]);
		_exit(1);
	}
	
	
	writeStructureInFile(argv);
	
	exit(EXIT_SUCCESS);

}
