/*
	Write a program which creates hole of size 1kb at the end of file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#define BUFSIZE 1024
#define FILE_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH

char localBuf1[BUFSIZE] = {"abcdefghijklmno"};
char localBuf2[BUFSIZE] = {"ABCDEFGHIJKLMNO"};	

void createHoleInFile(void)
{

	auto int createFd = 0;
		
	createFd = creat("file.hole",FILE_MODE);
	if(createFd == -1)
	{
		perror("creat");
		_exit(EXIT_FAILURE);
	}	
	
	if((write(createFd,localBuf1,sizeof(localBuf1))) != sizeof(localBuf1))
	{
		perror("write localBuf1");
		_exit(EXIT_FAILURE);
	}
	
	if((lseek(createFd,0,SEEK_END)) == -1)
	{
		perror("lseek");
		_exit(EXIT_FAILURE);
	}

	if((write(createFd,localBuf2,sizeof(localBuf2))) != sizeof(localBuf2))
	{
		perror("write localBuf2");
		_exit(EXIT_FAILURE);
	}
	
}

int main(void)
{
	void createHoleInFile(void);

	createHoleInFile();

	exit(EXIT_SUCCESS);
	
}
