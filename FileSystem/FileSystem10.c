/*
	Write a program which accept file names from user and copy the contents of an existing file into newly 
	created file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

void copyFileContents(char *argv[])
{
	auto struct stat sObj;
	auto mode_t fPermissions = 0;
	auto int openFd = 0,readRet = 0,createFd = 0;
	auto char localBuf[BUFSIZ] = {'\0'};
	
	fPermissions = S_IRUSR  | S_IWUSR  | S_IRGRP  |  S_IWGRP  | S_IROTH  | S_IWOTH;
	
	openFd = open(argv[1],O_RDONLY);
	if(openFd == -1)
	{
		perror("open");
		_exit(EXIT_FAILURE);
	}
	
	stat(argv[1],&sObj);
	if(sObj.st_size == 0)
	{
		fprintf(stderr,"File %s is empty\n",argv[1]);
		_exit(EXIT_FAILURE);
	}
	
	createFd = creat(argv[2],fPermissions);
	if(createFd == -1)
	{
		perror("creat");
		_exit(EXIT_FAILURE);
	}
	
	while((readRet = read(openFd,localBuf,BUFSIZ)) > 0)
	{
		if((write(createFd,localBuf,readRet)) != readRet)
		{
			break;
		}
	}
	if(readRet < 0) 
	{
		perror("read");
		_exit(EXIT_FAILURE);
	}

	if(close(openFd) == -1)
	{
		perror("close");
		_exit(EXIT_FAILURE);
	}
	
}

int main(int argc,char *argv[])
{
	void copyFileContents(char **);

	if((argc == 1) || (argc > 3))
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);	
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to copy contents of an existing file into newly created file\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s Source_File Destination_File\n",argv[0]);
		_exit(1);
	}
	
	copyFileContents(argv);
	
	exit(EXIT_SUCCESS);

}
