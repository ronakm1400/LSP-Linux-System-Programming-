/*
	Write a program which accept directory name from user and print all file names and its types from that 
	directory.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

void displayFileNamesAndTypes(char *argv[])
{
	
	auto DIR *dirPtr = NULL;
	auto struct dirent *dP = NULL;
	
	dirPtr = opendir(argv[1]);
	if(dirPtr == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	
	printf("------------------------------------------------------------\n");
	printf("File_Type\t\tFile_Name\n");
	printf("------------------------------------------------------------\n");
	
	while((dP = readdir(dirPtr)) != NULL)
	{
		if((dP->d_type) == DT_BLK)
		{
			printf("Block file\t\t%s\n",dP->d_name);
		}
		else if((dP->d_type) == DT_CHR)
		{
			printf("Character special file\t%s\n",dP->d_name);
		}
		else if((dP->d_type) == DT_DIR)
		{
			printf("Directory file\t\t%s\n",dP->d_name);
		}
		else if((dP->d_type) == DT_FIFO)
		{
			printf("Named pipe(FIFO)\t\t%s\n",dP->d_name);
		}
		else if((dP->d_type) == DT_SOCK)
		{
			printf("Socket\t\t%s\n",dP->d_name);
		}
		else if((dP->d_type) == DT_REG)
		{
			printf("Regular file\t\t%s\n",dP->d_name);
		}
		else
		{
			printf("Unknown file type\t%s\n",dP->d_name);
		}
	}
	
	if(closedir(dirPtr) == -1)
	{
		perror("closedir");
		exit(EXIT_FAILURE);
	}
	
}

int main(int argc,char *argv[])
{

	void displayFileNamesAndTypes(char **);

	if(argc != 2)
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		exit(EXIT_FAILURE);	
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to display the all file names and their types of directory\n");
		exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s Dir_Name\n",argv[0]);
		exit(1);
	}
	
	displayFileNamesAndTypes(argv);
	
	exit(EXIT_FAILURE);

}
