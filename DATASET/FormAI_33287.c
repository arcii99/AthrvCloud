//FormAI DATASET v1.0 Category: Error handling ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  char input[10];
  int num1, num2;
  
  printf("Enter two integers: ");
  
  // check for invalid input
  if (fgets(input, sizeof(input), stdin) == NULL) {
    fprintf(stderr, "Error: Failed to read input.\n");
    exit(1);
  }
  if (sscanf(input, "%d%d", &num1, &num2) != 2) {
    fprintf(stderr, "Error: Invalid input.\n");
    exit(1);
  }
  
  // perform arithmetic operations
  int sum = num1 + num2;
  int difference = num1 - num2;
  int product = num1 * num2;
  int quotient = 0;
  if (num2 != 0) {
    quotient = num1 / num2;
  } else {
    fprintf(stderr, "Error: Division by zero.\n");
    exit(1);
  }
  
  // display result
  printf("The sum of %d and %d is %d.\n", num1, num2, sum);
  printf("The difference between %d and %d is %d.\n", num1, num2, difference);
  printf("The product of %d and %d is %d.\n", num1, num2, product);
  printf("The quotient of %d and %d is %d.\n", num1, num2, quotient);
  
  return 0;
}