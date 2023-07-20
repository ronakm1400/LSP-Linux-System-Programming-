////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Problem Statement : Write a program which accept directory name from user and print all file names and its
//			    types from that directory.	
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#define SUCCESS 1
#define FAILURE -1
#define EXIT_SUCCESS 0

void displayFileName_Types(char *argv[])
{
	auto DIR *dPtr = NULL;
	auto struct dirent *dEntry = NULL;
	auto struct stat sObj;
	
	dPtr = opendir(argv[1]);
	
	if(dPtr == NULL)
	{
		printf("Cannot open file\n");
		printf("No such directory\n");
		exit(FAILURE);	
	}
	
	printf("-----------------------------------\n");
	printf("File_Type\tFileName\n");
	printf("-----------------------------------\n");
	while((dEntry = readdir(dPtr)) != NULL)
	{
		if((dEntry->d_type) != DT_DIR)
		{
			printf("%s\t%s\n","Regular_File",dEntry->d_name);
		}
		else if(((dEntry->d_type == DT_DIR) &&((strcmp(dEntry->d_name,".") != 0) && (strcmp(dEntry->d_name,"..") != 0))))
		{
			printf("%s\t%s\n","Directory_File",dEntry->d_name);
		}	
	}
	printf("\n");	
	
	closedir(dPtr);
}

int main(int argc,char *argv[])
{

	if(argc != 2)
	{
		printf("Invalid number of arguments!\n");
		printf("Press --h or --H for Help\n");
		printf("Press --u or --U for Usage\n");
		exit(FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		printf("Help	: This application is used to print all the file names and its types from directory\n");
		exit(SUCCESS);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		printf("Usage	: Name_Of_Executable	Directory_Name\n");
		exit(SUCCESS);
	}
	
	displayFileName_Types(argv);

	exit(EXIT_SUCCESS);	

}
