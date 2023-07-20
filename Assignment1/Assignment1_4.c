///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement  :  Write a program which accept file name from user and print all information about
//				that file. 
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

void displayFileStatistics(char *argv[])
{
	
	auto int fd = 0;
	
	auto struct stat sObj;
	
	fd = open(argv[1],O_RDONLY);
	if(fd == FAILURE)
	{
		printf("Cannot open file\n");
		exit(FAILURE);
	}
	
	stat(arvg[1],&sObj);
	
	printf("File name : %s\n",argv[1]);
	printf("File size is : %d\n",sObj.st_size);
	printf("Number of links : %d\n",sObj.st_nlink);
	printf("Inode number : %d\n",sObj.st_ino);
	printf("File system number : %d\n",sObj.st_dev);
	printf("Number of blocks : %d\n",sObj.st_blocks);

	close(fd);

}

int main(int argc,char *argv[])
{

	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		printf("Press --h or --H for Help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help	: This application is used display statistical information about file \n");
		exit(SUCCESS);
	}
	else((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable   File_Name\n");
		exit(SUCCESS);
	}
	
	displayFileStatistics(argv);
	
}	
