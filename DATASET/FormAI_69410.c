//FormAI DATASET v1.0 Category: Sorting ; Style: Claude Shannon
#include <stdio.h>

int main() {
   int arr[10] = {13, 3, 25, 7, 1, 18, 23, 5, 12, 2}; // An array of 10 elements initialized randomly
   int n = 10; // Total number of elements in the array
   int i, j; // Loop variables
   
   // Printing unsorted array
   printf("Unsorted array:\n");
   for(i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   
   // Sorting the array using bubble sort
   for(i = 0; i < n-1; i++) {
      for(j = 0; j < n-i-1; j++) {
         // Comparing adjacent elements and swapping if they are in wrong order
         if(arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
   
   // Printing sorted array
   printf("\n\nSorted array:\n");
   for(i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   
   return 0;
}