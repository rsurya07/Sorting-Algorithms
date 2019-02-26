#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
	int n = atoi(argv[1]); //🤣
	int * arr = malloc(n*sizeof(int));
	int temp;
	_Bool sorted;
	
	for(int i = 0; i < n; i++)
	{
		srand(i+1);
		arr[i] = rand() % (n+1); 
		printf("%d ", arr[i]);
	}
	
	printf("\n\n");
	
	for(int i = 0; i < n; i++)
	{
		sorted = 1;
		
		for(int j = 0; j < n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				sorted = 0;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				//printf("switched %d %d\n", arr[j], arr[j+1]);
			}
		}
		
		if(sorted)
			break;
	}
	
	printf("\n\n");
	
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	printf("\n\nsorted\n\n");
	
	return 0;
	
}
