/*
	Write a program which accept file name and on mode and that program check whether our process can access 
	that file in accepted mode or not.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
#include<unistd.h>	// for access() systemcall

typedef signed int BOOL;

#define TRUE 1
#define FALSE 0

BOOL checkFileMode(char *argv[])
{
	
	auto int accessMode = 0;
	
	if(strcmp(argv[2],"Read") == 0)
	{
		accessMode = R_OK;		// Can the file be read?
	}
	else if(strcmp(argv[2],"Write") == 0)
	{
		accessMode = W_OK;		// Can the file be written?
	}
	else if(strcmp(argv[2],"Execute"))	
	{
		accessMode = X_OK;		// Can the file be executed?
	}
	else
	{
		accessMode = F_OK;		// Does the file exist?
	}
	
	if(access(argv[1],accessMode) == -1)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}				

}

int main(int argc,char *argv[])
{	
	
	BOOL checkFileMode(char **);

	if((argc <= 1) || (argc > 3))
	{
		fprintf(stderr,"Error : Invalid number of arguments\n");
		fprintf(stderr,"\nPress --h or --H for Help\n");
		fprintf(stderr,"Press --u or --U for Usage\n");
		exit(EXIT_FAILURE);
	}
	
	if((strcmp(argv[1],"--h") == 0) || (strcmp(argv[1],"--H") == 0))
	{
		fprintf(stdout,"Help : This application is used to accept file name and ON mode of the file and checks whether the process can access that file in accepted mode or not.\n");
		fprintf(stdout,"\nFile Modes: \n1.Read\n2.Write\n3.Execute\n");
		exit(1);
	}
	else if((strcmp(argv[1],"--u") == 0) || (strcmp(argv[1],"--U") == 0))
	{
		fprintf(stdout,"Usage : %s  File_Name  File_Mode\nNote  :'Please enter any one file mode described in help section'.\nIf the file name is symbolic link the code will generate error.\n",argv[0]);
		exit(1);
	}
	
	auto BOOL bRet = FALSE;
		
	bRet = checkFileMode(argv);
	if(bRet == TRUE)
	{
		printf("%s have permission to access %s file in %s mode\n",argv[0],argv[1],argv[2]);
	}
	else
	{
		printf("%s do not have permission to access %s file in %s mode\n",argv[0],argv[1],argv[2]);	
	}
	
	exit(EXIT_SUCCESS);

}

/*       access() checks whether the calling process can access the file
       pathname.  If pathname is a symbolic link, it is dereferenced.

       The mode specifies the accessibility check(s) to be performed,
       and is either the value F_OK, or a mask consisting of the bitwise
       OR of one or more of R_OK, W_OK, and X_OK.  F_OK tests for the
       existence of the file.  R_OK, W_OK, and X_OK test whether the
       file exists and grants read, write, and execute permissions,
       respectively.

       The check is done using the calling process's real UID and GID,
       rather than the effective IDs as is done when actually attempting
       an operation (e.g., open(2)) on the file.  Similarly, for the
       root user, the check uses the set of permitted capabilities
       rather than the set of effective capabilities; and for non-root
       users, the check uses an empty set of capabilities.

       This allows set-user-ID programs and capability-endowed programs
       to easily determine the invoking user's authority.  In other
       words, access() does not answer the "can I read/write/execute
       this file?" question.  It answers a slightly different question:
       "(assuming I'm a setuid binary) can the user who invoked me
       read/write/execute this file?", which gives set-user-ID programs
       the possibility to prevent malicious users from causing them to
       read files which users shouldn't be able to read.

       If the calling process is privileged (i.e., its real UID is
       zero), then an X_OK check is successful for a regular file if
       execute permission is enabled for any of the file owner, group,
       or other.
*/

