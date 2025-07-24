//FormAI DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>

int main() {

   int arr[5] = {5, 3, 4, 2, 1};
   int i, j, temp;

   printf("Before sorting:\n");
   for(i=0; i<5; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   for(i=0; i<5-1; i++) {
      for(j=0; j<5-i-1; j++) {
         if(arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }

   printf("After sorting in ascending order:\n");
   for(i=0; i<5; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");

   return 0;
}