//FormAI DATASET v1.0 Category: Sorting ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n);

int main() {
   int arr[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
   int i;

   printf("Before sorting: ");
   for (i = 0; i < 10; i++) {
      printf("%d ", arr[i]);
   }

   bubble_sort(arr, 10);

   printf("\nAfter sorting: ");
   for (i = 0; i < 10; i++) {
      printf("%d ", arr[i]);
   }

   return 0;
}

void bubble_sort(int arr[], int n) {
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