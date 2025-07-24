//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#define SIZE 10

void bucketSort(int array[], int n) {
   int i, j;
   int count[SIZE] = { 0 };

   for (i = 0; i < n; i++)
      count[array[i]]++;

   for (i = 0, j = 0; i < SIZE; i++) {
      for (; count[i] > 0; (count[i])--)
         array[j++] = i;
   }
}

void printArray(int array[], int n) {
   int i;
   for (i = 0; i < n; i++)
      printf("%d ", array[i]);
   printf("\n");
}

int main() {
   int array[SIZE] = { 0 };
   int i;

   // randomly generate numbers to fill the array
   for (i = 0; i < SIZE; i++) {
      array[i] = rand() % 10;
   }

   printf("Array before sorting: ");
   printArray(array, SIZE);

   bucketSort(array, SIZE);

   printf("Array after sorting: ");
   printArray(array, SIZE);

   return 0;
}