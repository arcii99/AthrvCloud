//FormAI DATASET v1.0 Category: Random ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, n;
   time_t t;
   
   srand((unsigned) time(&t)); // initializing random number generator
   
   printf("Generating 10 random numbers between 0 and 99:\n");
   
   for (i = 0; i < 10; i++) {
      n = rand() % 100; // generating random number between 0 and 99
      printf("%d\n", n);
   }

   return 0;
}