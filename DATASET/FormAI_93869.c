//FormAI DATASET v1.0 Category: Benchmarking ; Style: minimalist
#include <stdio.h>
#include <time.h>

#define ITERATIONS 1000000

int main() {
   long int start, end;
   int i, sum = 0;

   // Track start time
   start = time(NULL);

   // Loop ITERATIONS times and sum i
   for (i = 0; i < ITERATIONS; i++)
      sum += i;

   // Track end time
   end = time(NULL);

   printf("Sum of integers from 0 to %d is: %d\n", ITERATIONS-1, sum);
   printf("Time taken to calculate: %ld seconds\n", end-start);

   return 0;
}