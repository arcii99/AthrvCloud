//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, n;
   time_t t;

   printf("> This is a random program using C <\n");
   printf("Generating 10 random numbers:\n");

   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Generates random numbers from 0 to 99 */
   for( i = 0 ; i < 10 ; i++ ) {
      n = rand() % 100;
      printf("%d ", n);
   }

   printf("\n\nGenerating 20 random numbers from 200 to 299:\n");

   /* Generates random numbers from 200 to 299 */
   for( i = 0 ; i < 20 ; i++ ) {
      n = (rand() % 100) + 200;
      printf("%d ", n);
   }

   printf("\n");
   return 0;
}