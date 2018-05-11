#include <fcntl.h> 
#include <stdlib.h>
#include <stdio.h>

int main()
{ 
	char buff[1024]; 
	close(2);
	int fd1 = open ("srap", O_RDONLY); 
	int fd2 = dup(fd1); 
	int fd3 = open("errorAndoutput.txt", O_CREAT|O_WRONLY, 0777);
	if(fd2 < 0)
	{
		close(fd1);
		close(fd2);
		dup2(2,fd3);
		perror("Error!");
		return 0;
	}
		int n; 	
		while(1)
		{ 
			n = read (fd2, buff, 1023); 
			if (n <= 0)
			{ 
				close(fd1); 
				close(fd2); 
				return 0; 
			} 
			write(fd3, buff, n); 
		}
	return 0;
} 
