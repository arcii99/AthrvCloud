//FormAI DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_VALUES 1000000

int main() {
   int values[NUM_VALUES];
   srand(time(NULL));

   // populate array with random numbers
   for (int i = 0; i < NUM_VALUES; i++) {
      values[i] = rand() % NUM_VALUES;
   }

   // calculate average of all values using iteration
   clock_t t1 = clock();
   double sum = 0;
   for (int i = 0; i < NUM_VALUES; i++) {
      sum += values[i];
   }
   double average = sum / NUM_VALUES;
   clock_t t2 = clock();
   printf("Average using iteration: %f Time taken: %f seconds\n", average, (double)(t2 - t1) / CLOCKS_PER_SEC);

   // calculate average using pointer arithmetic
   t1 = clock();
   sum = 0;
   int *ptr = values;
   for (int i = 0; i < NUM_VALUES; i++) {
      sum += *(ptr++);
   }
   average = sum / NUM_VALUES;
   t2 = clock();
   printf("Average using pointer arithmetic: %f Time taken: %f seconds\n", average, (double)(t2 - t1) / CLOCKS_PER_SEC);

   return 0;
}