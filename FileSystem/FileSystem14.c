/*
	Write a program which accepts directory name from user and create a new directory of that name.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

void createDir(char *argv[])
{
	auto int createFd = 0;
	auto mode_t dMode = 0;
	
	dMode =  S_IRUSR  | S_IWUSR  | S_IRGRP  |  S_IWGRP  | S_IROTH  | S_IWOTH;
	
	createFd = mkdir(argv[1],dMode);
	if(createFd == -1)
	{
		perror("mkdir");
		_exit(EXIT_FAILURE);
	}

}

int main(int argc,char *argv[])
{
	
	void createDir(char **);
	
	if(argc != 2)
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to create a new directory\n");
		_exit(1);
	}	
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s Dir_Name\n",argv[0]);
		_exit(1);
	}
	
	createDir(argv);
	
	exit(EXIT_SUCCESS);

}
