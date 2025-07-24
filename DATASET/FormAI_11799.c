//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // seed random number generator
  srand(time(NULL));
  
  // generate two random integers between 0 and 100
  int num1 = rand() % 101;
  int num2 = rand() % 101;
  
  // output the numbers to the user
  printf("Number 1: %d\n", num1);
  printf("Number 2: %d\n", num2);
  
  // perform addition
  int sum = num1 + num2;
  printf("Sum: %d\n", sum);
  
  // perform subtraction
  int difference = num1 - num2;
  printf("Difference: %d\n", difference);
  
  // perform multiplication
  int product = num1 * num2;
  printf("Product: %d\n", product);
  
  // perform division
  if (num2 != 0) {
    float quotient = (float) num1 / num2;
    printf("Quotient: %.2f\n", quotient);
  }
  else {
    printf("Cannot divide by zero\n");
  }
  
  return 0;
}