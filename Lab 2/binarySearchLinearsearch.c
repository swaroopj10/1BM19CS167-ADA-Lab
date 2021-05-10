#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int  first, last, mid, n, search1,search2,i;


int main()
{

  int choice;
  double rl,rb;
  clock_t start, end;
  printf("Enter the number of elements of the array\n");
  scanf("%d",&n);
  int array[n];
  for (i = 0; i < n; i++)
  {
      array[i]= rand ()%200;
      printf("%d ", array[i]);
  }
  printf("\n");
  printf("1.Linear Search\n2.Binary Search\n3.Exit\n");
  while (1)
  {
    printf("Enter your option :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter value to find :");
                scanf("%d", &search1);
                start = clock();
                linearSearch(array,search1);
                end = clock();
                rl = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("\nTime taken by Linear Search : %lf\n", rl);
                break;

        case 2: printf("Enter value to find :");
                scanf("%d", &search2);
                bubbleSort(array, 100);
                start = clock();
                binarySearch(array,0,n-1,search2);
                end = clock();
                rb = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("\nTime taken by Binary Search : %lf\n", rb);
                break;
        
        case 3:exit(1);

        default:printf("Invalid Input\n");
    }
    
  }
}

int binarySearch(int arr[], int first,int last, int ele) 
{
    
    if( first<= last) {
        int mid = first + (last-first)/2;
        if(arr[mid]==ele) {
            return mid;
        }
        else if(arr[mid]>ele)
            return binarySearch(arr,first,mid-1,ele);
        else
            return binarySearch(arr,mid+1,last,ele);
    }
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int arr[], int n)
{
  int i, j;
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void linearSearch(int arr[],int ele)
{
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        printf("%d found at location %d.\n",ele,i+1);
    }
    else
    {
        printf("Not found! %d isn't present in the list.\n", ele);
    }
}
