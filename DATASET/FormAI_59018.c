//FormAI DATASET v1.0 Category: Random ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, n;
   time_t t;

   srand((unsigned) time(&t)); // Initialize random number generator

   printf("Enter number of random numbers to generate: ");
   scanf("%d", &n);

   printf("The random numbers are:\n");

   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50); // Generate a random number between 0-49
   }

   return 0;
}