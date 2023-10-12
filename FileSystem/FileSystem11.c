/*
	Write a program which accept directory name from user and file name from user and check whether that file 
	is present in that directory or not.
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<stdbool.h>

bool checkFilePresent(char *argv[])
{
	auto bool bCheck = false;
	auto DIR *dirPtr = NULL;
	auto struct dirent *dP = NULL;
	
	dirPtr = opendir(argv[1]);
	if(dirPtr == NULL)
	{
		perror("dirPtr");
		_exit(EXIT_FAILURE);
	}
	
	while((dP = readdir(dirPtr)) != NULL)
	{
		if((strcmp(argv[2],dP->d_name) == 0))
		{
			bCheck = true;
			break;
		}	
	}
	if(bCheck == true)
	{
		return true;
	}
	else 
	{
		return false;
	}
	
	if(closedir(dirPtr) == -1)
	{
		perror("closedir");
		_exit(EXIT_FAILURE);
	}

}

int main(int argc,char *argv[])
{

	bool checkFilePresent(char **);
	
	auto bool bRet = false;

	if((argc == 1) || (argc > 3))
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);	
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to check whether the file is present in directory or not\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s Dir_Name File_Name\n",argv[0]);
		_exit(1);
	}
	
	bRet = checkFilePresent(argv);
	if(bRet == true)
	{
		printf("%s is present in directory\n",argv[2]);
	}
	else
	{
		printf("%s is not present in directory\n",argv[2]);	
	}
	
	exit(EXIT_SUCCESS);

}
