//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initializing random number generator with current time
  const int SIZE = 1000000; // array size for benchmarking
  int arr[SIZE]; // initialize array

  // fill array with random integers between 1 and 100
  for(int i = 0; i < SIZE; i++) {
    arr[i] = rand() % 100 + 1;
  }

  // bubble sort benchmarking
  clock_t start_bubble = clock(); // start clock
  for(int i = 0; i < SIZE - 1; i++) {
    for(int j = 0; j < SIZE - i - 1; j++) {
      if(arr[j] > arr[j+1]) {
        // swap elements
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  clock_t end_bubble = clock(); // end clock
  double time_bubble = (double)(end_bubble - start_bubble)/CLOCKS_PER_SEC; // calculate time in seconds

  // quicksort benchmarking
  int arr2[SIZE]; // copy of original array for quicksort
  for(int i = 0; i < SIZE; i++) {
    arr2[i] = arr[i];
  }
  clock_t start_quick = clock(); // start clock
  quicksort(arr2, 0, SIZE-1); // calling quicksort function
  clock_t end_quick = clock(); // end clock
  double time_quick = (double)(end_quick - start_quick)/CLOCKS_PER_SEC; // calculate time in seconds

  printf("Bubble Sort Time: %f seconds\n", time_bubble);
  printf("Quicksort Time: %f seconds\n", time_quick);

  return 0;
}

// quicksort function
void quicksort(int arr[], int low, int high) {
  if(low < high) {
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot-1);
    quicksort(arr, pivot+1, high);
  }
}

// partition function for quicksort
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for(int j = low; j < high; j++) {
    if(arr[j] <= pivot) {
      i++;
      
      // swap elements
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  // swap elements
  int temp = arr[i+1];
  arr[i+1] = arr[high];
  arr[high] = temp;

  return i+1;
}