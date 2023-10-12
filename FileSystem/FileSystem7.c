/*
	Write a program which accepts directory name from user and print all file names from that directory.
	Implementation of ls command.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>

void displayDirectoryFileNames(char *argv[])
{	
	auto DIR *dirPtr = NULL;
	auto struct dirent *dp = NULL;
	
	dirPtr = opendir(argv[1]);	
	if(dirPtr == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	
	while((dp = readdir(dirPtr)) != NULL)
	{
		printf("%s\n",dp->d_name);
	}
	printf("\n");
	
	if((closedir(dirPtr)) == -1)
	{
		perror("closedir");
		exit(EXIT_FAILURE);
	}
	
}

int main(int argc,char *argv[])
{
	
	void displayDirectoryFileNames(char **);

	if(argc != 2)
	{
		fprintf(stdout,"Error : Invalid number of arguments\n");
		fprintf(stdout,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stdout,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to display the file names inside directory file\n");
		exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s Directory_Name\n",argv[0]);
		exit(1);
	}
	
	displayDirectoryFileNames(argv);	
		
	exit(EXIT_SUCCESS);

}
