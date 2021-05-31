#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int low, int high) 
{
  
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) 
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
  if (low < high) 
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}



int main() 
{
  clock_t start, end;
    double t;
	for(int n=100;n<601;n=n+100)
	{
	    int array[n];
        for (int i = 0; i < n; i++)
        {
           array[i]= rand ()%1000;
        }
      
        start = clock();
        quickSort(array, 0, n - 1);
        end = clock();
        t = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\nTime taken by Quick Sort for %d elements : %lf\n",n,t);
	    
	}
}