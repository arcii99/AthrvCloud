//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>

int main() {
   int arr[5] = {54, 23, 59, 12, 7};
   int i, j, temp;

   printf("Before sorting: ");
   for(i=0; i<5; i++) {
      printf("%d ", arr[i]);
   }

   for(i=0; i<4; i++) {
      for(j=0; j<4-i; j++) {
         if(arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }

   printf("\nAfter sorting: ");
   for(i=0; i<5; i++) {
      printf("%d ", arr[i]);
   }

   return 0;
}