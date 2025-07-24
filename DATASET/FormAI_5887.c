//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main() {
  int arr[N];
  int sum = 0;
  double time_taken;
  clock_t start, end;

  // generate random array
  srand(time(0)); 
  for(int i = 0; i < N; i++) 
    arr[i] = rand() % 100;

  // calculate sum of array elements
  start = clock();
  for(int i = 0; i < N; i++) 
    sum += arr[i];
  end = clock();

  // calculate time taken to execute loop
  time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
  
  // print output
  printf("Sum of array elements: %d\n", sum);
  printf("Time taken for loop execution: %lf seconds\n", time_taken);

  return 0;
}