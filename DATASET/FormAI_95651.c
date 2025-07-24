//FormAI DATASET v1.0 Category: Random ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i;
   int n = 10; // the number of random numbers to generate

   printf("Generating %d random numbers:\n", n);

   // use the current time as a seed for the random number generator
   srand(time(NULL));

   // generate and print out n random numbers
   for(i = 0; i < n; ++i) {
      printf("%d ", rand());
   }

   printf("\n");

   return 0;
}