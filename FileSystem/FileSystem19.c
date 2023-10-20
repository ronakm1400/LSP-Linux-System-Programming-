/*
	Write a program which accept directory name from user and write information of all regular files in a file 
	and read all the contents from that file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#define BUFSIZE 1024

#pragma pack(1)
struct fileInfo
{
	
	int 	fileSize;
	int 	fileLinks;
	int 	fileSysNum;
	int 	iNodeNumber;
	int 	noOfBlocks;
	char	fileName[BUFSIZE];
	
};

void writeFileInfoOfRegFiles(char *argv[])
{

	auto int createFd = 0,filePerms = 0;

	auto struct stat sObj;
	auto struct fileInfo fObj;
	
	auto DIR *dPtr = NULL;
	auto struct dirent *dEntry = NULL;
	
	auto char fName[BUFSIZE] = {'\0'};
	
	filePerms = S_IRUSR  | S_IWUSR  | S_IRGRP  |  S_IWGRP  | S_IROTH  | S_IWOTH;
	
	dPtr = opendir(argv[1]);
	if(dPtr == NULL)
	{
		perror("opendir");
		_exit(EXIT_FAILURE);
	}
	
	createFd = creat("RegInfo.txt",filePerms);
	if(createFd == -1)
	{
		perror("creat");
		_exit(EXIT_FAILURE);
	}
			
	while((dEntry = readdir(dPtr)) != NULL)
	{
		sprintf(fName,"%s/%s",argv[1],dEntry->d_name);
		stat(fName,&sObj);
		if(S_ISREG(sObj.st_mode))
		{
			strcpy(fObj.fileName,dEntry->d_name);
			fObj.fileSize 		= sObj.st_size;
			fObj.fileSysNum 	= sObj.st_dev;
			fObj.fileLinks		= sObj.st_nlink;
			fObj.iNodeNumber	= sObj.st_ino;
			fObj.noOfBlocks		= sObj.st_blocks;
			
			if((write(createFd,&fObj,sizeof(fObj))) == -1)
			{
				perror("write");
				_exit(EXIT_FAILURE);
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
	
	void writeInfoOfRegFiles(char **);

	if(argc != 2)
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application accepts directory name and writes all information of all regular files in a file and read all the contents from that newly created file\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"%s Name_Of_Directory\n",argv[0]);
		_exit(1);
	}
	
	writeFileInfoOfRegFiles(argv);	
		
	exit(EXIT_SUCCESS);

}
