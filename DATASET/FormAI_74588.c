//FormAI DATASET v1.0 Category: Benchmarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  long long sum = 0;
  double avg;
  int arr[1000000];

  printf("Generating random numbers...\n");

  for(int i = 0; i < 1000000; i++) {
    arr[i] = rand() % 1000000;
  }

  printf("Done!\n");
  
  clock_t start = clock();
  
  for(int j = 0; j < 1000000; j++) {
    sum += arr[j];
  }

  clock_t end = clock();
  
  avg = (double) sum / 1000000;
  double time_spent = (double) (end - start) / CLOCKS_PER_SEC;

  printf("Sum: %lld\n", sum);
  printf("Average: %f\n", avg);
  printf("Time Elapsed: %f seconds\n", time_spent);

  return 0;
}