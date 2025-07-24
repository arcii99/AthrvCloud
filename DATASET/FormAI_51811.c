//FormAI DATASET v1.0 Category: Benchmarking ; Style: romantic
#include <stdio.h>
#include <time.h>

int main() {
   clock_t start, end;
   double cpu_time_used;

   start = clock();

   // Benchmark code section starts here
   int x = 0;
   for(int i = 0; i < 100000000; i++) {
       x += i;
   }
   // Benchmark code section ends here

   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

   printf("Time taken for the operation: %lf seconds\n", cpu_time_used);
   return 0;
}