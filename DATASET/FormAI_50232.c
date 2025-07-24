//FormAI DATASET v1.0 Category: Error handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int dividend = 10;
  int divisor = 0;
  int result;
  
  printf("Let's divide %d by %d\n", dividend, divisor);
  
  // Handling Divide by Zero Error
  if (divisor == 0) {
    printf("Oh no! You cannot divide by zero. Please try again with a non-zero divisor.\n");
    exit(0); // exiting the program
  }
  
  result = dividend / divisor;
  printf("The result is %d\n", result);
  
  return 0;
}