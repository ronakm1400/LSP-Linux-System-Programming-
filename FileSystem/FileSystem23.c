/*
	Write a program which accept directory name from user and delete all such files whose size is greater than
	100 bytes.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#define BUFSIZE 1024

void deleteFile(char *argv[])
{
	auto signed int createFd = 0,filePerms = 0;
	
	auto struct stat sObj;
	auto DIR *dPtr = NULL;
	auto struct dirent *dEntry = NULL;
	
	auto char fileName[BUFSIZE] = {'\0'};
	
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

	dPtr = opendir(argv[1]);
	if(dPtr == NULL)
	{
		perror("opendir");
		_exit(EXIT_FAILURE);
	}
	
	createFd = creat("DeletedFiles.log",filePerms);
	if(createFd == -1)
	{
		perror("creat");
		_exit(EXIT_FAILURE);
	}	
	
	while((dEntry = readdir(dPtr)) != NULL)
	{
		sprintf(fileName,"%s/%s",argv[1],dEntry->d_name);
		stat(fileName,&sObj);
		
		if(S_ISREG(sObj.st_mode))
		{
			if(sObj.st_size > 100)
			{
				unlink(fileName);
				if((write(createFd,fileName,sizeof(fileName))) == -1)
				{
					break;
				}
			}
		}
	
	}
	
	if(closedir(dPtr) == -1)
	{
		perror("closedir");
		_exit(EXIT_FAILURE);
	}


}

int main(int argc,char *argv[])
{

	void deleteFile(char **);

	if(argc != 2)
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application accepts directory name and deletes all such regular files which are greater than 100 bytes.\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s DirName\n",argv[0]);
		_exit(1);
	}

	deleteFile(argv);

	exit(EXIT_SUCCESS);

}
