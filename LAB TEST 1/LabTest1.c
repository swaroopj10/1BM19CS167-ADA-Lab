#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int status;

int linearSearch(int arr[], int n, int key, int i) 
{
    status = -1;
    if(arr[i] == key) 
    {
        status=0;
        return i;
    }
    else 
    {
        return linearSearch(arr,n,key,(i+1));
    }
}

void sortArray(int arr[], int n) 
{
    for(int b=0;b<n;b++) {
        for(int e=b+1;e<n;e++) 
        {
            if(arr[b]>arr[e]){
                arr[b] = arr[b]+arr[e];
                arr[e] = arr[b]-arr[e];
                arr[b] = arr[b]-arr[e];
            }
        }
    }
}

int binarySearch(int arr[], int b,int e, int key) 
{
    status=-1;
    
    if( b<= e) {
        int m = b + (e-b)/2;
        if(arr[m]==key) 
        {
            status=0;
            return m;
        }
        else if(arr[m]>key)
            return binarySearch(arr,b,m-1,key);
        else
            return binarySearch(arr,m+1,e,key);
    }
}

int Mode(int arr[], int nn, int k)
{
    int i = binarySearch(arr, 0, nn - 1, k);
 
    if (i == -1)
        return 0;
    int count = 1;
    int left = i - 1;
    while (left >= 0 && arr[left] == k)
        count++, left--;
    int right = i + 1;
    while (right < nn && arr[right] == k)
        count++, right++;
    return count;
}

int main() 
{
    srand(time(NULL));
    int l,key;
    printf("Enter length of array : ");
    scanf("%d",&l);
    int arr[l];
    printf("Enter the key element :");
    scanf("%d",&key);
    for(int i = 0;i<l;i++) 
    {
        arr[i] = (rand()%1000);
    }
    double resl,resb;
    clock_t start, end;

    start = clock();
    int li = linearSearch(arr, l, key, 0);
    end = clock();
    resl = ((double) (end - start)) / CLOCKS_PER_SEC;

    

    start = clock();
    sortArray(arr,l);
    int bi = binarySearch(arr, 0,l-1, key);
    end = clock();
    resb = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nKey : %d\n",key);

    printf("\n--LINEAR SEARCH---\n");
    if(status==0) {
        printf("\n%d found at index %d\n", key,li);
    }
    else {
        printf("\n%d not found in array\n",key);
    }
    printf("\nTime taken by linear search : %lf\n", resl);
    
    printf("\n---BINARY SEARCH---\n");  
    if(status==0) {
        printf("\n%d found at index %d\n", key,bi);
    }
    else {
        printf("\n%d not found in array\n",key);
    }
    printf("\nTime taken by binary search : %lf\n", resb);
    
    printf("\n---MODE OF KEY ELEMENT---\n");
    int no;
    printf("Enter the number of elements of the array\n");
    scanf("%d",&no);
    int arr1[no];
    printf("Enter the elements of the array\n");
    for(int i=0;i<no;i++)
    {
      scanf("%d",&arr1[i]);
    }
    int nn = sizeof(arr1) / sizeof(arr1[0]);
    int k = 3;
    int x;
    x = Mode(arr1, nn, k);
    printf("Mode of the key element is: %d",x);
}