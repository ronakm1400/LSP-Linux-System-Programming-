/*
	Write a program which accepts directory name from user and copy all filenames of all regular files and 
	writes into newly created file named as Demo.txt.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct fileInfo
{
	int fileSize;
	char fileName[BUFSIZ];
};

void cpAllFileNamesInDir(char *argv[])
{
	auto struct stat sObj;
	auto struct fileInfo fObj;
		
	auto DIR *dirPtr = NULL;
	auto struct dirent *dEntry = NULL;
	
	auto char fileNm[BUFSIZ] = {'\0'};	
	auto int createFd = 0,filePermissions = 0;
	
	filePermissions = S_IRUSR  | S_IWUSR  | S_IRGRP  |  S_IWGRP  | S_IROTH  | S_IWOTH;

	dirPtr = opendir(argv[1]);
	if(dirPtr == NULL)
	{
		perror("opendir");
		_exit(EXIT_FAILURE);
	}	
	
	createFd = creat("Demo.txt",filePermissions);
	if(createFd == -1)
	{
		perror("creat");
		_exit(EXIT_FAILURE);		
	}
	
	while((dEntry = readdir(dirPtr)) != NULL)
	{
		sprintf(fileNm,"%s/%s",argv[1],dEntry->d_name);
		
		stat(fileNm,&sObj);
				
		if(S_ISREG(sObj.st_mode))
		{
			fObj.fileSize = sObj.st_size;
			strcpy(fObj.fileName,dEntry->d_name);	
			write(createFd,&fObj,sizeof(fObj));
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
	
	void cpAllFileNamesInDir(char **);
	
	if((argc <= 1) || (argc > 3))
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to copy the file-names in directory and write all the file-names inside newly created file named as 'Demo.txt'\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s Dir_Name\n",argv[0]);
		_exit(1);
	}
	
	cpAllFileNamesInDir(argv);
	
	exit(EXIT_SUCCESS);
	
}
