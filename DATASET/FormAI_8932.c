//FormAI DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>

void selectionSort(int arr[], int n);

int main()
{
   int arr[] = {5, 4, 1, 3, 2};
   int n = sizeof(arr)/sizeof(arr[0]);
   int i;

   printf("Unsorted Array: ");
   for(i = 0;i < n;i++)
      printf("%d ",arr[i]);

   selectionSort(arr, n);

   printf("\nSorted Array: ");
   for(i = 0;i < n;i++)
      printf("%d ",arr[i]);

   return 0;
}

void selectionSort(int arr[], int n)
{
   int i, j, min_idx, temp;

   for (i = 0; i < n-1; i++)
   {
       min_idx = i;
       for (j = i+1; j < n; j++)
         if (arr[j] < arr[min_idx])
            min_idx = j;

       temp = arr[min_idx];
       arr[min_idx] = arr[i];
       arr[i] = temp;
   }
}