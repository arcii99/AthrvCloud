//FormAI DATASET v1.0 Category: System boot optimizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the C System Boot Optimizer\n");
  
  // Generate random numbers for optimization
  srand(time(NULL));
  int num1 = rand() % 50 + 1;
  int num2 = rand() % 50 + 1;
  
  // Calculate optimization results
  int result = num1 * num2;
  float percent = (float) result / (float) 2500 * 100;
  
  // Display optimization results
  printf("The boot optimization is %d x %d = %d\n", num1, num2, result);
  printf("This is a %.2f%% optimization improvement!\n", percent);
  
  // Determine if optimization is successful
  if (percent > 50) {
    printf("Congratulations! Your system is now optimized!\n");
  } else {
    printf("Unfortunately, your system could not be optimized.\n");
    printf("Please consult your system administrator for assistance.\n");
  }
  
  return 0;
}