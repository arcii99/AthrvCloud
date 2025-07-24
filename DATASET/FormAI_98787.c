//FormAI DATASET v1.0 Category: Random ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, n;
   time_t t;
   
   srand((unsigned) time(&t));
   
   printf("Generating 10 random numbers between 1 and 100:\n");
   
   for(i = 0; i < 10; i++) {
       n = rand() % 100 + 1;
       printf("%d ", n);
   }
   
   printf("\nGenerating 10 random characters:\n");
   
   for(i = 0; i < 10; i++) {
       n = rand() % 26 + 97; // generate lowercase ASCII character
       printf("%c ", (char)n);
   }
   
   printf("\nGenerating 10 random floating point numbers between 0 and 1:\n");
   
   for(i = 0; i < 10; i++) {
       printf("%f ", (float)rand()/(float)(RAND_MAX));
   }
   
   return 0;
}