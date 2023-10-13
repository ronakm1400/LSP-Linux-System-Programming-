/*
	Write a program which accepts two file names from user and check whether contents of that two files 
	are equal or not.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sys/stat.h>

bool checkFilesAreEqual(char *argv[])
{
	auto struct stat sObj1,sObj2;
	
	auto int fileFd1 = 0,fileFd2 = 0,readRet = 0,iCount = 0;

	auto char localBuf1[BUFSIZ] = {'\0'},localBuf2[BUFSIZ] = {'\0'};
	
	fileFd1 = open(argv[1],O_RDONLY);
	if(fileFd1 == -1)
	{
		perror("open(fileFd1)");
		_exit(EXIT_FAILURE);
	}	

	fileFd2 = open(argv[2],O_RDONLY);
	if(fileFd2 == -1)
	{
		perror("open(fileFd2)");
		_exit(EXIT_FAILURE);
	}	
	
	if(fstat(fileFd1,&sObj1) == -1)
	{
		perror("fstat(fileFd1)");
		_exit(EXIT_FAILURE);
	}
	
	if(fstat(fileFd2,&sObj2) == -1)
	{
		perror("fstat(fileFd2)");
		_exit(EXIT_FAILURE);
	}
	
	if(sObj1.st_size != sObj2.st_size)
	{
		fprintf(stdout,"As file sizes are not same the files are not equal\n");
		_exit(EXIT_FAILURE);
	}
	
	while((readRet = read(fileFd1,localBuf1,BUFSIZ)) != 0)
	{
		iCount++;
		
		readRet = read(fileFd2,localBuf2,BUFSIZ);
		
		if(memcmp(localBuf1,localBuf2,readRet) != 0)
		{
			break;
		}
		
	}
	
	if(readRet == 0)
	{
		return true;
	}
	else
	{
		return false;
	}		
	
	if(close(fileFd1) == -1)
	{
		perror("close(fileFd1)");
		_exit(EXIT_FAILURE);	
	}
	
	if(close(fileFd2) == -1)
	{
		perror("close(fileFd1)");
		_exit(EXIT_FAILURE);	
	}

}

int main(int argc,char *argv[])
{
	
	bool checkFilesAreEqual(char **);
	
	auto bool bRet = false;

	if((argc <= 1) || (argc > 3))
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"Press %s --h or %s --H for Help\n",argv[0],argv[0]);
		fprintf(stderr,"Press %s --u or %s --U for Usage\n",argv[0],argv[0]);
		_exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to check the contents of the two files.\n");
		_exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s First_File Second_File\n",argv[0]);
		_exit(1);
	}
	
	bRet = checkFilesAreEqual(argv);
	if(bRet == true)
	{
		printf("Files are same\n");
	}
	else
	{
		printf("Files are not same\n");
	}
	
	exit(EXIT_SUCCESS);
	
}
