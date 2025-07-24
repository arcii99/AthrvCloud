//FormAI DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
   int data[10] = {2, 7, 3, 8, 1, 4, 6, 9, 5, 0};
   int i, j, temp;

   // Displaying the original data
   printf("Original Data: ");
   for(i = 0; i < 10; i++) {
      printf("%d ", data[i]);
   }

   printf("\n\n");

   // Sorting the data using Bubble Sort
   for(i = 0; i < 10; i++) {
      for(j = 0; j < 9 - i; j++) {
         if(data[j] > data[j+1]) {
            temp = data[j+1];
            data[j+1] = data[j];
            data[j] = temp;
         }
      }
   }

   // Displaying the sorted data
   printf("Sorted Data: ");
   for(i = 0; i < 10; i++) {
      printf("%d ", data[i]);
   }

   printf("\n\n");

   // Data Mining to find the minimum and maximum values
   int min = data[0];
   int max = data[9];
   for(i = 1; i < 10; i++) {
      if(data[i] < min) {
         min = data[i];
      }
      if(data[i] > max) {
         max = data[i];
      }
   }

   // Displaying the data mining results
   printf("Min Value: %d\n", min);
   printf("Max Value: %d\n", max);

   return 0;
}