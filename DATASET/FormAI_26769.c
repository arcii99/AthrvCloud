//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: paranoid
#include <stdio.h>

int main() {
   int n, i, j, temp;
   int arr[] = {17, 9, 11, 13, 5, 23, 21, 7, 4, 1};
   int len = sizeof(arr)/sizeof(arr[0]);

   printf("Initial array: ");
   for (i = 0; i < len; i++) {
      printf("%d ", arr[i]);
   }

   // Sorting the array using Bubble Sort
   for (i = 0; i < len - 1; i++) {
      for (j = 0; j < len - i - 1; j++) {
         if (arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }

   printf("\nSorted array: ");
   for (i = 0; i < len; i++) {
      printf("%d ", arr[i]);
   }

   // Finding the maximum sum using Greedy Algorithm
   int sum = 0;
   for (i = len-1; i > len-4; i--) {
      sum += arr[i];
   }

   printf("\nLargest sum of 3 numbers: %d", sum);
   return 0;
}