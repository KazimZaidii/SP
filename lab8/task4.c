#include <fcntl.h> 
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{  
	struct stat buff; 
	if(argc != 2)
	{ 
		fprintf(stderr, "Invalid no of arguments given");
		printf("\n"); 
		exit(1); 
	} 
	if (lstat(argv[1], &buff) < 0)
	{ 
		perror("error in lstat"); 
		exit(1); 
	}  
	if (S_ISREG(buff.st_mode)) 
	{
		printf("%s  is a regular file",argv[1]);
		printf("\n");
		printf("INODE : %d\n", buff.st_ino);
		printf("Access Time : %d\n",buff.st_atime );
		printf("Modified Time : %d\n",buff.st_mtime );
		printf("Size  : %d\n",buff.st_size );  
	}
	else if (S_ISDIR(buf.st_mode)) 
	{
		printf("%s  is a directory",argv[1]);
		printf("\n");		
		printf("User_ID : %d\n",buff.st_uid );
	}
	else 
		printf("%s  is not defined",argv[1]);
		printf("\n"); 
	
	return 0;
} 
