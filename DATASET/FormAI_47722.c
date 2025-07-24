//FormAI DATASET v1.0 Category: Random ; Style: energetic
/* Let's generate some random numbers! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, n;
   
   /* set the seed for random generation */
   srand(time(NULL));
 
   printf("Enter the number of random numbers to generate: ");
   scanf("%d", &n);
 
   /* generate and print the random numbers */
   for(i = 1; i <= n; i++) {
      printf("%d\n", rand());
   }
   
   return 0;
}

/* Boom! Look at that! Randomness to the max! */