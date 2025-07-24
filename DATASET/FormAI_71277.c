//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
  
  // Generate random array
  int array[ARRAY_SIZE];
  srand(time(NULL)); 
  for(int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 100;
  }

  // Calculate the sum using a for loop
  clock_t start = clock();
  int sum = 0;
  for(int i = 0; i < ARRAY_SIZE; i++) {
    sum += array[i];
  }
  clock_t end = clock();
  double time_for = (double)(end - start) / CLOCKS_PER_SEC;
  printf("The sum is %d and it took %f seconds using a for loop.\n", sum, time_for);

  // Calculate the sum using a while loop
  start = clock();
  sum = 0;
  int i = 0;
  while(i < ARRAY_SIZE) {
    sum += array[i];
    i++;
  }
  end = clock();
  double time_while = (double)(end - start) / CLOCKS_PER_SEC;
  printf("The sum is %d and it took %f seconds using a while loop.\n", sum, time_while);
  
  // Calculate the sum using a do-while loop
  start = clock();
  sum = 0;
  i = 0;
  do {
    sum += array[i];
    i++;
  } while(i < ARRAY_SIZE);
  end = clock();
  double time_do_while = (double)(end - start) / CLOCKS_PER_SEC;
  printf("The sum is %d and it took %f seconds using a do-while loop.\n", sum, time_do_while);
  
  return 0;
}