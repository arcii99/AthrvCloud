//FormAI DATASET v1.0 Category: Random ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, n;
   time_t t;

   /* Intializes random number generator */
   srand((unsigned) time(&t));

   /* Print 10 random numbers from 0 to 49 */
   printf("Ten random numbers from 0 to 49\n");
   for( i = 0 ; i < 10 ; i++ ) {
      n = rand() % 50;
      printf("%d\n", n);
   }

   /* Print 10 random numbers from 1 to 6 (simulating a die) */
   printf("\nTen random numbers from 1 to 6 (simulating a die)\n");
   for( i = 0 ; i < 10 ; i++ ) {
      n = (rand() % 6) + 1;
      printf("%d\n", n);
   }

   return 0;
}