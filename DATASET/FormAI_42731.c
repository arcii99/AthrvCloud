//FormAI DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   /* an array with 5 elements */
   int arr[] = {4, 3, 6, 2, 8};
   int n = sizeof(arr)/sizeof(arr[0]);

   /* printing the original array */
   printf("The original array is: \n");
   for (int i=0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   /* sorting the array */
   int temp;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n-i-1; j++) {
         if (arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }

   /* printing the sorted array */
   printf("The sorted array is: \n");
   for (int i=0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return 0;
}