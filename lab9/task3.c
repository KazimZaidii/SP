#include<stdio.h>
#include<signal.h>

void myhandler(int signum)
{ 
	switch(signum)
	{ 
		case 2: 
			printf("SIGINT HANDLER: %d\n",signum); 
			break; 
		case 3: 
			printf("SIGQUIT HANDLER: %d\n",signum); 
			break; 
		case 8: 
			printf("SIGFPE HANDLER: %d\n",signum); 
			break; 
		case 9: 
			printf("SIGKILL HANDLER: %d\n",signum); 
			break; 
		case 19: 
			printf("SIGHUP HANDLER: %d\n",signum); 
			break;
		case 20:
			printf("SIGTSTP HANDLER: %d\n",signum); 
			break; 	 
	}
}

int main() 
{ 	
	signal(SIGINT, myhandler); 
	signal(SIGHUP, myhandler); 
	signal(SIGQUIT, myhandler); 
	signal(SIGTSTP, myhandler); 
	signal(SIGFPE, myhandler); 
	signal(SIGKILL, myhandler); 
 
	while(1) 
	{ 
		printf("Infinite loop...\n"); 
		sleep(1); 
	} 
	return 0;
}
