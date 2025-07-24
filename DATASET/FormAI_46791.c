//FormAI DATASET v1.0 Category: Benchmarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void bubbleSort(int arr[], int n) {
   int temp, i, j;
   for(i = 0; i < n-1; i++) {
       for(j = 0; j < n-i-1; j++) {
           if(arr[j] > arr[j+1]) {
               temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
   }
}

int main() {
   int arr[SIZE];
   int i;
   float time_taken;
   clock_t t;

   srand(time(0)); // seeding the random number generator with current time

   // filling the array with random elements
   for(i = 0; i < SIZE; i++) {
       arr[i] = rand() % 1000;
   }

   printf("Before sorting:\n");
   for(i = 0; i < SIZE; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n");

   t = clock();
   bubbleSort(arr, SIZE);
   t = clock() - t;

   printf("After sorting:\n");
   for(i = 0; i < SIZE; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n");

   time_taken = ((float)t)/CLOCKS_PER_SEC; // calculating the time taken in seconds
   printf("Bubble sort took %f seconds to execute \n", time_taken);

   return 0;
}