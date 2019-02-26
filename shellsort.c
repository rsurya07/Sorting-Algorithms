#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
	int n  = atoi(argv[1]);
	int * arr = malloc(n * sizeof(int));
	int temp;

	for(int i = 0; i < n; i++)
	{
		srand(i+1);
		arr[i] = rand() % 101;
		//printf("%d ", arr[i]);
	}
	
	int k = n;
	int sorted;
	
	while(k > 1)
	{
		k = k/2;
		
		sorted = 1;
		
		for(int i = 0; i < n - k; i++)
		{
			if(arr[i] > arr[i+k])
			{
				temp = arr[i];
				arr[i] = arr[i+k];
				arr[i+k] = temp;
				sorted = 0;
			}	
		}
		
		if(sorted)
			break;
	}
	
	//printf("\n\n");
	
	//for(int i = 0; i < n; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	
	if(!sorted)
	{		
		for(int i = 0; i < n-1; i++)
		{			
			for(int j = i+1; j > 0; j--)
			{
				sorted = 1;
				
				if(arr[j] < arr[j-1])
				{
					temp = arr[j];
					arr[j] = arr[j-1];
					arr[j-1] = temp;
					sorted = 0;
				}
				
				if(sorted)
					break;
			}
		}
	}
	
	//printf("\n\n");
	
	//for(int i = 0; i < n; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	printf("\n\nsorted\n\n");
	
	free(arr);
	
	return 0;
	
}
			
	
	
