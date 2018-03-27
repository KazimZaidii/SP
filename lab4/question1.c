#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size = 10;
	int *arr = (int*) malloc (sizeof(int) * size);
	int i = 0;

	for(i;i<10;i++)
	{
		arr[i] = i;
	}

	for(i=0;i<10;i++)
	{
		printf("value at %d is: %d \n", i, arr[i]);
	}

	int newsize = 2*size;
	int *newarray = (int*) realloc (arr, sizeof(int) * newsize);
	
	for(i=0;i<newsize;i++)
	{
		newarray[i] = i;
	}
	
	printf("new array \n");

	for(i = 0;i<newsize;i++)
	{
		printf("value at %d is: %d \n", i, newarray[i]);
	}
	//free(arr);
	//free(newarray);
	return 0;
}
