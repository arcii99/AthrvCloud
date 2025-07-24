//FormAI DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>

void selection_sort(int arr[], int n) {
   int i, j, min_idx;

   for (i = 0; i < n-1; i++) {
      min_idx = i;
      for (j = i+1; j < n; j++) {
         if (arr[j] < arr[min_idx])
            min_idx = j;
      }
      int temp = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = temp;
   }
}

int main() {
   int arr[] = {10, 7, 8, 9, 1, 5};
   int n = sizeof(arr)/sizeof(arr[0]);
   int i;
   printf("Before sorting:\n");
   for (i = 0; i < n; i++)
      printf("%d ", arr[i]);

   selection_sort(arr, n);

   printf("\nAfter sorting:\n");
   for (i = 0; i < n; i++)
      printf("%d ", arr[i]);

   return 0;
}