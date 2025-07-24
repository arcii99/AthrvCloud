//FormAI DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ARRAY_SIZE 1000000 // Array size for benchmarking

// Bubble sort algorithm implementation
void bubblesort(int *array, int n) {
  int temp, i, j;

  for(i=1;i<n;++i) {
     for(j=0;j<(n-i);++j)
        if(array[j]>array[j+1]) {
           temp=array[j];
           array[j]=array[j+1];
           array[j+1]=temp;
        }
  }
}

// Main function to run the benchmark
int main() {
  int i;
  int *data = (int*) malloc(sizeof(int) * ARRAY_SIZE);
  clock_t start, end;
  double cpu_time_used;

  // Generate random data to sort
  srand(time(NULL));
  for(i=0;i<ARRAY_SIZE;++i)
    data[i] = rand() % 10000;

  // Record the start time
  start = clock();

  // Run the algorithm
  bubblesort(data, ARRAY_SIZE);

  // Record the end time
  end = clock();

  // Calculate the time used and print the result
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Time used: %f seconds\n", cpu_time_used);

  free(data);
  return 0;
}