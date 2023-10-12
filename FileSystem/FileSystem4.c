/*
	Write a program which accepts file name from user and print all information about that file.
*/

#include<time.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

void displayFileInfo(struct stat *statBuf)
{	
	printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*- Information Of File -*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
		
	printf("\nFile type			: ");
	
	switch(statBuf->st_mode & S_IFMT)
	{
		case(S_IFREG):
		{
			printf("regular file\n");
			break;
		}
		case(S_IFDIR):
		{
			printf("directory file\n");
			break;	
		}
		case(S_IFLNK):
		{
			printf("symbolic link\n");
			break;
		}
		case(S_IFCHR):
		{
			printf("character special file\n");
			break;
		}
		case(S_IFBLK):
		{
			printf("block special file\n");
			break;
		}
		case(S_IFIFO):
		{
			printf("FIFO\n");
			break;
		}
		case(S_IFSOCK):
		{
			printf("socket file\n");
			break;
		}
		default: 
		{
			printf("unkown file type?\n");
			break;
		}
	}
	
	printf("Inode number 			: %ld\n",(long)statBuf->st_ino);
	printf("File Size			: %ld bytes\n",(long)statBuf->st_size);
	printf("Total block size		: %d\n",statBuf->st_blksize);
	printf("Blocks allocated to file	: %d\n",statBuf->st_blocks);
	printf("Ownership			: UID=%ld	GID=%ld\n",(long)statBuf->st_uid,statBuf->st_gid);
	printf("Time of last file access	: %s",ctime(&statBuf->st_atime));
	printf("Time of last file modification	: %s",ctime(&statBuf->st_mtime));
	printf("Last status changed of file	: %s",ctime(&statBuf->st_ctime));
}

int main(int argc,char *argv[])
{
	struct stat *sObj;
		
	if(argc != 2)
	{
		fprintf(stderr,"Error : Invalid number of arguments!\n");
		fprintf(stderr,"\nPress --h or --H for Help\n");
		fprintf(stderr,"Press --u or --U for Usage\n");
		exit(EXIT_FAILURE);
	}	
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to print all information about the file.\n");
		exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s  FileName\n",argv[0]);
		exit(1);
	}
	
	if(stat(argv[1],&sObj) == -1)
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}	
		
	displayFileInfo(&sObj);	

	exit(EXIT_SUCCESS);

}
