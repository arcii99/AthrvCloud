//FormAI DATASET v1.0 Category: Benchmarking ; Style: scientific
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
   int n = 10000000;
   int sum = 0;
   clock_t start, end;
   double cpu_time_used;

   int *array = (int*)malloc(n * sizeof(int));

   for(int i = 0; i < n; i++){
      array[i] = i;
   }

   start = clock();
   for(int i = 0; i < n; i++){
      sum += array[i];
   }
   end = clock();

   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

   printf("Sum of array elements: %d \n", sum);
   printf("Time taken: %f seconds\n", cpu_time_used);
  
   free(array);
   return 0;
}