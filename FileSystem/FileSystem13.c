/*
	Write a program which accept directory name from user and delete all empty files from that directory.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

#define BUF_SIZE 1024

void deleteAllEmptyFiles(char *argv[])
{
	auto int createFd = 0;
	auto mode_t fPermissions = 0;
	
	auto struct stat sObj;
	auto DIR *dirPtr = NULL;
	auto struct dirent *dP = NULL;
	
	auto char fileNm[BUF_SIZE] = {'\0'};
	
	fPermissions = S_IRUSR  | S_IWUSR  | S_IRGRP  |  S_IWGRP  | S_IROTH  | S_IWOTH;
		
	dirPtr = opendir(argv[1]);
	if(dirPtr == NULL)
	{
		perror("opendir");
		_exit(EXIT_FAILURE);
	}
	
	createFd = creat("DeletedFiles.log",fPermissions);
	if(createFd == -1)
	{
		perror("creat");
		_exit(EXIT_FAILURE);
	}
	
	while((dP = readdir(dirPtr)) != NULL)
	{
		sprintf(fileNm,"%s/%s",argv[1],dP->d_name);	
		stat(fileNm,&sObj);
		if(S_ISREG(sObj.st_mode))
		{
			if(sObj.st_size == 0)
			{
				unlink(fileNm);
				write(createFd,fileNm,sizeof(fileNm));
			}
		}	
		
	}
	
	if(closedir(dirPtr) == -1)
	{
		perror("closedir");
		_exit(EXIT_FAILURE);
	}

}

int main(int argc,char *argv[])
{

	void deleteAllEmptyFiles(char **);

	if(argc != 2)
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to delete all the empty files from the given directory\n");
		_exit(1);
	}	
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s Dir_Name\n",argv[0]);
		_exit(1);
	}
	
	deleteAllEmptyFiles(argv);
	
	exit(EXIT_SUCCESS);

}
