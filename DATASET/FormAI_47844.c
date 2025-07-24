//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void bubble_sort(int arr[], int n) {
   int i, j, temp;
   for (i = 0; i < n-1; i++) {
      for (j = 0; j < n-i-1; j++) {
         if (arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

int main() {
   int i, arr[ARRAY_SIZE];
   clock_t start_time, end_time;
   double time_diff;

   srand(time(0));

   for (i = 0; i < ARRAY_SIZE; i++) {
      arr[i] = rand();
   }

   start_time = clock();
   bubble_sort(arr, ARRAY_SIZE);
   end_time = clock();

   time_diff = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

   printf("Sorting %d integers took %.4f seconds\n", ARRAY_SIZE, time_diff);

   return 0;
}