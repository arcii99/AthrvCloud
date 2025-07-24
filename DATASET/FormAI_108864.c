//FormAI DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
   int numbers[10] = {2, 5, 1, 4, 3, 8, 6, 7, 9, 10};
   int i, j, temp;

   printf("Input Array: ");
   for(i = 0; i < 10; i++) {
      printf("%d ",numbers[i]);
   }

   for(i = 0; i < 10; i++) {
      for(j = i+1; j < 10; j++) {
         if(numbers[i] > numbers[j]) {
            temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
         }
      }
   }

   printf("\n\nData mining is done!\n\n");

   printf("Sorted Array: ");
   for(i = 0; i < 10; i++) {
      printf("%d ",numbers[i]);
   }
   return 0;
}