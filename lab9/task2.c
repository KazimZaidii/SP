#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{ 
	pid_t cpid = fork(); 
	if (cpid ==0)
	{ 
		while(1)
		{ 
			printf("child in a loop\n"); 
			sleep(1); 
		} 
	} 
	else
	{ 
		sleep(5); 
		kill(cpid,SIGINT); 
		printf("child killed by parent...\n"); 
		_exit(0); 
	}
 
	return 0;
}
