#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int i=0, j=0, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 

    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) 
    { 
        arr[k] = L[i];
        i++;
        k++;
    }
 

    while (j < n2)
     { 
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        
        int m = l + (r - l) / 2;
 
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r); 
    }
}


void main()
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
	    mergeSort(array,0, n-1);
        end = clock();
        t = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\nTime taken by Merge Sort for %d elements : %lf\n",n,t);
	    
	}

 
}
