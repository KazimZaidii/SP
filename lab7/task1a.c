#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<libgen.h>
#include<string.h>

//requires absolute path of source and destination
//eg(./a.out /home/kazim/file.txt /home/Desktop/ )
int main(int argc, char *argv[])
{
	printf("No of arguments passed are: %d", argc);
	printf("\n");
	char buff [256];
	int n = 0;
	int i = 1;
	int count = argc-1;
	
	while(i < count)
	{
		printf("i: %d", i);
		printf("\n");
		int fd = open(argv[i], O_RDONLY,0777);
		n = read(fd,buff,255);	
		if(n<1)
		{
			printf("empty file...\n");
			continue;
		}		
		char* filename = basename(argv[i]);
		printf("filename: %s", filename);
		printf("\n");
		
		char* addr = argv[count];
		char* dname = strcat(addr, filename);

		printf("destinationName: %s", dname);
		printf("\n");

		int fd2 = open(dname, O_WRONLY|O_CREAT,0777);
		printf("fd2: %d", fd2);
		printf("\n");

		write(fd2,buff,n);
		n = 0;
		unlink(argv[i]);
		i = i + 1;
		buff[0] = 0;		
		printf("\n");
		
	}
	
	return 0;

}
