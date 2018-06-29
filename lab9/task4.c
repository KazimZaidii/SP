#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{ 
	sigset_t newset, oldset; 
	sigemptyset(&newset); 
	sigaddset(&newset, SIGINT); 
	sigaddset(&newset, SIGQUIT); 
	sigaddset(&newset, SIGALRM);
	sigaddset(&newset, SIGHUP); 
	sigaddset(&newset, SIGILL);
 	sigprocmask(SIG_SETMASK, &newset, &oldset); 

	int i = 0; 
	for(i=1; i<=30; i++)
	{ 
		printf("Signal Blocked...\n"); 
		sleep(1); 
	} 

	sigprocmask(SIG_SETMASK, &oldset, NULL); 

	for(i=1; i<=10; i++)
	{ 
		printf("Signal Unblocked\n"); 
		sleep(1); 
	}
 
	return 0;
}
