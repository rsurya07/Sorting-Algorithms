#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* merge(int * arr1, int * arr2, int n1);
int* mergesort(int * arr, int n1);
	
int main(int argc, char * argv[])
{
	int n = atoi(argv[1]); //🤣
	int * arr = malloc(n*sizeof(int));
	
	for(int i = 0; i < n; i++)
	{
		srand(i+1);
		arr[i] = rand() % (n+1); 
		//printf("%d ", arr[i]);
	}
	

	memcpy(arr, mergesort(arr, n), n*sizeof(int));
	//printf("\n\n");
	
	//for(int i = 0; i < n; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	printf("\n\nsorted\n\n");
	
	free(arr);
	
	return 0;
	
}

int* mergesort(int * arr, int n1)
{	
	if(n1 == 1)
		return arr;		
		
	//int * arr1 = malloc((n1/2)*sizeof(int));
	//int * arr2 = malloc((n1 - n1/2)*sizeof(int));
	
	int arr1[n1/2];
	int arr2[n1 - n1/2];
	
	memcpy(arr1, arr, (n1/2)*sizeof(int));
	memcpy(arr2, &(*(arr+n1/2)), (n1 - (n1/2))*sizeof(int));
	
	/*
	printf("\n\n");
	
	for(int i = 0; i < n1/2; i++)
		printf("%d ", arr1[i]);
		
	printf("\n\n");
	
	for(int i = 0; i < n1 - n1/2; i++)
		printf("%d ", arr2[i]);
	
	*/
	
	memcpy(arr1, mergesort(arr1, n1/2), (n1/2)*sizeof(int));
	memcpy(arr2, mergesort(arr2, n1 - n1/2), (n1 - n1/2)*sizeof(int));
	
	return merge(arr1, arr2, n1);
		
}


int* merge(int * arr1, int * arr2, int n1)
{
	//printf("\n\n");
	
	int * arr = malloc(n1*sizeof(int));
	
	int i1 = 0, i2 = 0, i3 = 0;
	
	while(i3 < n1)
	{
		if(i1 == n1/2)
			arr[i3++] = arr2[i2++];
			
		else if(i2 == (n1 - n1/2))
			arr[i3++] = arr1[i1++];
			
		else if(arr1[i1] <= arr2[i2])
			arr[i3++] = arr1[i1++];
			
		else if(arr2[i2] <= arr1[i1])
			arr[i3++] = arr2[i2++];
			
		//printf("%d ", arr[i3-1]);
	}
	
	
	
	return arr;
			
		 
		
}
		
	
	
