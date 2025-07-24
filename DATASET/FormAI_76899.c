//FormAI DATASET v1.0 Category: Sorting ; Style: Claude Shannon
#include <stdio.h>

void bubbleSort(int arr[], int n) {
   int i, j, temp;
   for (i = 0; i < n-1; i++) { 
       for (j = 0; j < n-i-1; j++) { 
           if (arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

int main()
{
   int n, i;
   int arr[] = {64, 34, 25, 12, 22, 11, 90};

   n = sizeof(arr)/sizeof(arr[0]);

   printf("Unsorted array: ");
   for(i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   bubbleSort(arr, n);

   printf("\nSorted array: ");
   for(i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   return 0;
}