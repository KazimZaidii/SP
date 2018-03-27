#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

int counter=0;
static jmp_buf buff;

void Havefun()
{ 
	printf("In HaveFun()\n"); 
	printf("Counter: %d\n", counter);
	counter++; 
}
void firstSetJump()
{ 
	printf("In firstSetJump()\n"); 
	printf("Counter: %d\n", counter);
	counter++; 
}

int main()
{ 
	for(int i = 0; i < 5; i++)
	{
		if (counter == 0 && (i = setjmp(buff)) == 0)
		{ 
			firstSetJump(); 
		}

		Havefun();
	 
	}
	return 0;  
}

