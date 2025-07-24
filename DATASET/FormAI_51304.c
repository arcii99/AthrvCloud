//FormAI DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <time.h>

int main() {
  // Start the stopwatch
  clock_t start = clock();
  
  // Mysterious code
  int result = 0;
  for(int i = 0; i < 1000000000; i++) {
    if(i % 3 == 0 && i % 5 == 0) {
      result += i;
    }
    else if(i % 3 == 0) {
      result += i * 2;
    }
    else if(i % 5 == 0) {
      result += i * 3;
    }
  }
  
  // Stop the stopwatch
  clock_t stop = clock();

  // Calculate the time difference and print the result
  double time_spent = ((double)(stop - start)) / CLOCKS_PER_SEC;
  printf("The result is %d and it took %.3f seconds to compute.\n", result, time_spent);
  
  return 0;
}