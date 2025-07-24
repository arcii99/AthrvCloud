//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Function to handle division by zero error
double divide(int a, int b) {
  if (b == 0) {
    // Setting error number
    errno = EDOM;
    // Printing error message
    fprintf(stderr, "%s\n", "Error: Division by zero");
    // Exiting the program with error code
    exit(EXIT_FAILURE);
  }
  return (double) a/b;
}

int main() {
  int num1, num2;
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  // Calling divide function and handling error
  double result = divide(num1, num2);
  if (errno == EDOM) {
    // Performing recovery operation
    printf("Enter any non zero number to replace 'num2': ");
    scanf("%d", &num2);
    // Recalling divide function with non zero number
    result = divide(num1, num2);
  }

  // Printing the result
  printf("Result: %f\n", result);

  return 0;
}