//FormAI DATASET v1.0 Category: Random ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int numbers[10];
   int i,sum=0,product=1;

   srand(time(NULL)); // To get different random numbers each time

   printf("Generating 10 Random Numbers: \n");

   for(i=0; i<10; i++) {
      numbers[i] = rand() % 20; // Random numbers between 0 and 19
      printf("%d ", numbers[i]);
   }

   printf("\n\nFinding Sum and Product of the Random Numbers: \n");

   for(i=0; i<10; i++) {
      sum += numbers[i]; // Adding each number to previous sum
      product *= numbers[i]; // Multiplying each number to previous product
   }

   printf("The Sum of the Random Numbers is: %d \n", sum);
   printf("The Product of the Random Numbers is: %d \n", product);

   return 0;
}