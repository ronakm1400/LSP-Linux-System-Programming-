/*
	Write a program which accept directory name from user and print name of such a regular file having largest 
	file size.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

void displayNameOfLargestFileSize(char *argv[])
{
	auto int maxSize = 0;
	auto char cpName[BUFSIZ] = {'\0'};

	auto struct stat sObj;
	auto DIR *dirPtr = NULL;
	auto struct dirent *dP = NULL;
		
	dirPtr = opendir(argv[1]);
	if(dirPtr == NULL)
	{
		perror("opendir");
		_exit(EXIT_FAILURE);
	}
	
	while((dP = readdir(dirPtr)) != NULL)
	{	
		stat(dP->d_name,&sObj);
		if(S_ISREG(sObj.st_mode))
		{
			if(maxSize < sObj.st_size)
			{
				maxSize = sObj.st_size;
				strcpy(cpName,dP->d_name);
			}
		}			
	}
	
	printf("File name = %s \nSize = %d bytes\n",cpName,maxSize);

	if(closedir(dirPtr) == -1)
	{
		perror("closedir");
		_exit(EXIT_FAILURE);
	}

}

int main(int argc,char *argv[])
{

	void displayNameOfLargestFileSize(char **);

	if(argc != 2)
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to display the name of regular file having largest file size in a directory\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s Dir_Name\n",argv[0]);
		_exit(1);
	}
	
	displayNameOfLargestFileSize(argv);
	
	exit(EXIT_FAILURE);

}
