//FormAI DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>

int main() {
   int n, i, j, temp;
   printf("Enter number of elements in the array: ");
   scanf("%d", &n);
   int arr[n];
   printf("Enter %d elements: ", n);
   for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   // Visionary Code Starts Here

   printf("\nUnsorted Array: ");
   for (i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n - i - 1; j++) {
         if (arr[j] > arr[j + 1]) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }

   printf("\nSorted Array: ");
   for (i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }

   // Visionary Code Ends Here

   return 0;
}