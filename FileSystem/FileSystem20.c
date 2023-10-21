/*
	Write a program which accept directory name from user and combine all contents of file from that directory
	into one file named as AllCombine.txt
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#define BUFSIZE 1024

void combineAllContents(char *argv[])
{
	auto int createFd = 0,filePerms = 0,readRet = 0,openFd = 0;
	
	auto struct stat sObj;
	auto DIR *dPtr = NULL;
	auto struct dirent *dEntry = NULL;
	
	auto char fileName[BUFSIZE] = {'\0'};
	auto char localBuf[BUFSIZ]  = {'\0'};
	
	filePerms = S_IRUSR | S_IWUSR  | S_IRGRP  |  S_IWGRP  | S_IROTH  | S_IWOTH;
	
	dPtr =  opendir(argv[1]);
	if(dPtr == NULL)
	{
		perror("opendir");
		_exit(EXIT_FAILURE);
	}
	
	createFd = creat("AllCombine.txt",filePerms);
	if(createFd == -1)
	{
		perror("creat");
		_exit(EXIT_FAILURE);
	}
		
	while((dEntry = readdir(dPtr)) != NULL)
	{
		sprintf(fileName,"%s/%s",argv[1],dEntry->d_name);
		stat(fileName,&sObj);
		
		openFd = open(fileName,O_RDONLY);
		if(openFd == -1)
		{
			perror("");
			break;
		}
		
		if(S_ISREG(sObj.st_mode))
		{
			while(readRet = read(openFd,localBuf,sizeof(localBuf)) > 0)
			{
				if((write(createFd,localBuf,sizeof(localBuf))) != readRet)
				{
					break;
				}
			}
		
		}
	}

	if(readRet < 0)
	{
		perror("read");
		_exit(EXIT_FAILURE);
	}
	
	if(closedir(dPtr) == -1)
	{
		perror("closedir");
		_exit(EXIT_FAILURE);
	}

}

int main(int argc,char *argv[])
{
	void combineAllContents(char **);

	if(argc != 2)
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application accepts directory name from user and combines all the data from regular files into one newly created file named 'AllCombine.txt'\n");
		_exit(1);
		
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s DirName\n",argv[0]);
		_exit(1);
	}

	combineAllContents(argv);

	exit(EXIT_SUCCESS);

}
