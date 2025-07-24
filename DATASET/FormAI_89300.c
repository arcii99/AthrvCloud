//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <time.h>

int main() {
  clock_t start_time, end_time;
  double total_time;
  int numbers[100000];
  int sum = 0;

  for(int i=0; i<100000; i++) {
     numbers[i] = i+1;
  }

  start_time = clock();

  for(int i=0; i<100000; i++) {
     sum += numbers[i];
  }

  end_time = clock();
  total_time = (double)(end_time-start_time)/CLOCKS_PER_SEC;

  printf("The sum of the first 100000 integers is: %d\n", sum);
  printf("The time taken to calculate the sum is: %f seconds", total_time);

  return 0;
}