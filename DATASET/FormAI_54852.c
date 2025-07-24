//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to compare two integers for quicksort
int cmpfunc(const void *a, const void *b) {
   return (*(int*)a - *(int*)b);
}

int main() {
   // Allocate memory for array
   int *arr = (int*) malloc(ARRAY_SIZE * sizeof(int));

   // Populate array with random integers
   srand(time(NULL));
   for (int i=0; i<ARRAY_SIZE; i++) {
      arr[i] = rand() % 1000000;
   }

   // Sort array using quicksort
   qsort(arr, ARRAY_SIZE, sizeof(int), cmpfunc);

   // Find the median of array
   int median;
   if (ARRAY_SIZE % 2 == 0) {
      median = (arr[ARRAY_SIZE/2] + arr[(ARRAY_SIZE/2)-1]) / 2;
   } else {
      median = arr[ARRAY_SIZE/2];
   }

   printf("The median of the array is: %d", median);

   // Free allocated memory
   free(arr);

   return 0;
}