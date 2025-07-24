//FormAI DATASET v1.0 Category: Random ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int n, i;
   time_t t;

   srand((unsigned) time(&t));

   printf("Enter the number of random numbers you want to generate: ");
   scanf("%d", &n);

   printf("Random numbers between 1 and 100:\n");

   for (i = 0; i < n; i++) {
      printf("%d\n", rand() % 100 + 1);
   }

   return 0;
}