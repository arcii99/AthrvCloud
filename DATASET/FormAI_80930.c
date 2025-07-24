//FormAI DATASET v1.0 Category: Benchmarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 //An array of 1 million elements is created

int main() {
   int i, j, temp;
   clock_t start_time, end_time;
   double time_elapsed;
   int arr[ARRAY_SIZE];

   //Populating the array with random values between 0 to 999
   for (i = 0; i < ARRAY_SIZE; i++) {
      arr[i] = rand() % 1000;
   }

   //Bubble sort implementation
   start_time = clock(); //Mark the start time
   for(i = 0; i < ARRAY_SIZE-1; i++) {
      for(j = 0; j < ARRAY_SIZE-i-1; j++) {
         if(arr[j] > arr[j + 1]) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
   end_time = clock(); //Mark the end time
   time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

   printf("Time elapsed for bubble sort: %f\n", time_elapsed);

   //Selection sort implementation
   start_time = clock(); //Mark the start time
   int min_index;
   for(i = 0; i < ARRAY_SIZE-1; i++) {
      min_index = i;
      for(j = i+1; j < ARRAY_SIZE; j++) {
         if(arr[j] < arr[min_index])
            min_index = j;
      }
      temp = arr[min_index];
      arr[min_index] = arr[i];
      arr[i] = temp;
   }
   end_time = clock(); //Mark the end time
   time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

   printf("Time elapsed for selection sort: %f\n", time_elapsed);

   //Quick sort implementation
   void quickSort(int [], int, int);
   start_time = clock(); //Mark the start time
   quickSort(arr, 0, ARRAY_SIZE-1);
   end_time = clock(); //Mark the end time
   time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

   printf("Time elapsed for quick sort: %f\n", time_elapsed);

   return 0;
}

void quickSort(int arr[], int low, int high) {
   int i, j, pivot, temp;
   if(low < high) {
      pivot = low;
      i = low;
      j = high;
      while(i < j) {
         while(arr[i] <= arr[pivot] && i <= high)
            i++;
         while(arr[j] > arr[pivot] && j >= low)
            j--;
         if(i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
      temp = arr[j];
      arr[j] = arr[pivot];
      arr[pivot] = temp;
      quickSort(arr, low, j-1);
      quickSort(arr, j+1, high);
   }
}