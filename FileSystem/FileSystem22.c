/*
	Write a program which accepts directory name and file name from user and creates file in that directory.
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

#define BUFSIZE 1024

void createFileInDir(char *argv[])
{
	printf("createFileInDir\n");
	
	auto int createFd = 0,filePerms = 0;
	
	auto DIR *dPtr = NULL;
	auto struct dirent *dEntry = NULL;
	
	auto char filePath[BUFSIZE] = {'\0'};
	
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

	dPtr = opendir(argv[1]);
	if(dPtr == NULL)
	{
		perror("opendir");
		_exit(EXIT_FAILURE);
	}
	
	createFd = creat()	
	
	if((closedir(dPtr)) == -1)	
	{
		perror("closedir");
		_exit(EXIT_FAILURE);
	}
}

int main(int argc,char *argv[])
{
	void createFileInDir(char **);
	
	printf("Inside main\n");
	
	if((argc <= 1) || (argc > 3))
	{	
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application accepts directory name and file name from user and creates the file in that directory.\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s DirName FileName\n",argv[0]);
		_exit(1);
	}
	
	createFileInDir(argv);	

	exit(EXIT_SUCCESS);

}
