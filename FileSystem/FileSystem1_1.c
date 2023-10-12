/*
	Write a program which accept file name from user and open that file.
*/

// Using openat() syscall 

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int File_Open(char **);

int File_Open(char *argv[])
{
	auto ssize_t 	openFd 		= 0;
	auto ssize_t 	openFlags 	= 0;
	auto mode_t 	filePerms 	= 0;
	
	openFlags = O_RDONLY | O_RDWR  | O_WRONLY;
	filePerms = S_IRUSR  | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; 
	
	/* 
	
	With openat(), the first argument, fd, should be the file descriptor for a directory — such as the one you
	obtained from opening "." — or the special value AT_FDCWD (which means open relative paths relative the
	current directory). Note that the O_PATH option you use is a Linux-only extension to 
	
	*/

	openFd = openat(AT_FDCWD,argv[1],openFlags,filePerms);
	if(openFd == -1)
	{
		perror("Error open syscall");
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stdout,"File opened with file descriptor : %ld\n",openFd);
	}
	
	if(close(openFd) == -1)
	{
		return -1;
	}
	else
	{
		return 0;
	}
	
}

int main(int argc,char *argv[])
{

	if(argc != 2)
	{
		fprintf(stderr,"Error 	: Invalid number of arguments\n");
		fprintf(stdout,"Help 	: Press ./EXE_NAME --h or ./EXE_NAME --H for Help\n");
		fprintf(stdout,"Usage 	: Press ./EXE_NAME --h or ./EXE_NAME --H for Help\n");
		exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help 	: This application is used to open an existing file programatically\nThis application uses openat() system call to open a file\n");
		exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage 	: ./EXE_NAME File_Name_To_Open\n");
		exit(1);	
	}
	
	auto signed int iRet = 0;
		
	iRet = File_Open(argv);
	
	if(iRet == -1)
	{
		printf("Unable to close file\n");
	}
	else
	{
		printf("File closed successfully\n");
	}

	exit(EXIT_SUCCESS);

}	
