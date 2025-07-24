//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <time.h>

#define ARR_SIZE 1000000

int main() {
  double start_time, end_time;

  int arr[ARR_SIZE];
  int i, j, temp;
  
  //initialize array with random values
  for(i=0; i<ARR_SIZE; i++) {
    arr[i] = rand();
  }

  //start the timer
  start_time = clock();

  //bubble sort algorithm
  for(i=0; i<ARR_SIZE-1; i++) {
    for(j=0; j<ARR_SIZE-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  //stop the timer
  end_time = clock();

  //calculate and print the elapsed time in seconds
  double elapsed_time = (end_time - start_time)/CLOCKS_PER_SEC;
  printf("Elapsed time for sorting %d numbers: %lf seconds\n", ARR_SIZE, elapsed_time);

  return 0;
}