/*
	Write a program which accept file name and mode from user and then open that file in specified mode.
*/

#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define errExit(msg) do { perror(msg); exit(EXIT_FAILURE); } while(0)

void File_Open_Mode(char **);

void File_Open_Mode(char *argv[])
{
	auto signed int openFd = 0;
	auto mode_t fileMode = 0,filePerms = 0;
		
	if(strcmp(argv[2],"Read") == 0)
	{
		fileMode = O_RDONLY;
	}	
	else if(strcmp(argv[2],"Write") == 0)
	{
		fileMode = O_WRONLY;
	}
	else if(strcmp(argv[2],"R+W") == 0)
	{
		fileMode = O_RDWR;
	}
	else
	{
		errExit("Please enter valid mode\n");
	}
	
	openFd = open(argv[1],fileMode);
	
	if(openFd == -1)
	{
		errExit("Open system call");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("File opened with fd : %d\n",openFd);
	}
	
	if(close(openFd) == -1)
	{
		errExit("Close system call");
		exit(EXIT_FAILURE);
	}
}
	
int main(int argc,char *argv[])
{

	if((argc <= 1) || (argc > 3))
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or --H for Help\n",argv[0]);
		fprintf(stderr,"Press %s --u or --U for Usage\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help	: This application is used to open file programatically in user specified mode\n1.Press 'Read' to open file in read mode\n2.Press 'Write' to open file in write mode\n3.Press 'R+W' to open file in Read-Write mode.\n");
		exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage	: %s 	File_Name 	File_Mode\n",argv[0]);
		exit(1);
	}
	
	File_Open_Mode(argv);
	
	exit(EXIT_SUCCESS);	

}
