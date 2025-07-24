//FormAI DATASET v1.0 Category: Random ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, n;
   int random_number;

   // Initialize random seed
   srand(time(0));

   // Ask for input
   printf("Enter the number of random numbers you want to generate: ");
   scanf("%d", &n);

   // Generate and print random numbers
   for (i = 1; i <= n; i++) {
      random_number = rand();
      printf("Random number %d: %d\n", i, random_number);
   }

   return 0;
}