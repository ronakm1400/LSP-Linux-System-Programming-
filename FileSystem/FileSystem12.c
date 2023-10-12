/*
	Write a program which accepts two directory name from user and move all files from source directory to
	destination directory.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

void moveFilesFromSrcToDest(char *argv[])
{

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
		rename(argv[1],argv[2]);
	}
	
	if(closedir(dirPtr) == -1)
	{
		perror("closedir");
		_exit(EXIT_FAILURE);		
	}
		
}

int main(int argc,char *argv[])
{
	void moveFilesFromSrcToDest(char **);

	if((argc == 1) || (argc > 3))
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);	
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to move all files from source directory to destination directory\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s Source_Directory Destination_Directory\n",argv[0]);
		_exit(1);
	}
	
	moveFilesFromSrcToDest(argv);
	
	exit(EXIT_SUCCESS);

}
