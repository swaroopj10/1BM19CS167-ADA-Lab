#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i, first, last, mid, n, search1,search2, array[100];

int linearSearch(int);
int binarySearch(int);


int main()
{
  int choice,li,bi;
  double resl,resb;
  clock_t start, end;
  for (i = 0; i < 100; i++)
  {
      array[i]= rand ()%120;
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
                li=linearSearch(search1);
                end = clock();
                resl = ((double) (end - start)) / CLOCKS_PER_SEC;
                if(li==1)
                {
                    printf("\nTime taken by linear search : %lf\n", resl);
                }
                break;

        case 2: printf("Enter value to find :");
                scanf("%d", &search2);
                bubbleSort(array, 100);
                start = clock();
                bi=binarySearch(search2);
                end = clock();
                resb = ((double) (end - start)) / CLOCKS_PER_SEC;
                if(bi==1)
                {
                    printf("\nTime taken by linear search : %lf\n", resb);
                }
                break;
        
        case 3:exit(1);

        default:printf("Invalid Input\n");
    }
    
  }
}

int binarySearch(int ele)
{
  first = 0;
  last = 99;
  mid = (first+last-1)/2;

  while (first <= last) {
    if (array[mid] < ele)
      first = mid + 1;
    else if (array[mid] == ele) {
      printf("\n\n%d found at location %d.\n", ele, mid+1);
      return 1;
      break;
    }
    else
      last = mid - 1;

    mid = (first + last)/2;
  }
  if (first > last)
  {
    printf("Not found! %d isn't present in the list.\n", ele);
    return 0;
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

int linearSearch(int ele)
{
    int flag=0;
    for(i=0;i<100;i++)
    {
        if(array[i]==ele)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        printf("%d found at location %d.\n",ele,i+1);
        return 1;
    }
    else
    {
        printf("Not found! %d isn't present in the list.\n", ele);
        return 0;
    }
}