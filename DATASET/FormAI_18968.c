//FormAI DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>

int main() {
   int numbers[10];
   int sum = 0, average;
   int i;

   // prompt user to enter 10 integers
   printf("Enter 10 integers: ");

   for(i = 0; i < 10; i++) {
      scanf("%d", &numbers[i]);
      sum += numbers[i];
   }

   // calculate average of 10 integers
   average = sum / 10;

   // display the results
   printf("\nSum of the 10 integers = %d\n", sum);
   printf("Average of the 10 integers = %d\n", average);

   // find numbers larger than the average
   printf("\nNumbers larger than the average are: ");
   for(i = 0; i < 10; i++) {
      if(numbers[i] > average) {
         printf("%d ", numbers[i]);
      }
   }

   // find numbers smaller than the average
   printf("\nNumbers smaller than the average are: ");
   for(i = 0; i < 10; i++) {
      if(numbers[i] < average) {
         printf("%d ", numbers[i]);
      }
   }

   return 0;
}