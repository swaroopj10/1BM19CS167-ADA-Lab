#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
int n,i;
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
    clock_t start, end;
    double t;
	for(int n=100;n<601;n=n+100)
	{
	    int array[n];
        for (i = 0; i < n; i++)
        {
           array[i]= rand ()%1000;
        }
      
        start = clock();
	    insertionSort(array, n);
        end = clock();
        t = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\nTime taken by Linear Search for %d elements : %lf\n",n,t);
	    
	}
    

	return 0;
}
