//FormAI DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void errorHandler(char* errorMessage, int errorCode) {
  printf("Error %d: %s\n", errorCode, errorMessage);
  exit(errorCode);
}

int divide(int numerator, int denominator) {
  if (denominator == 0) {
    errorHandler("Cannot divide by zero.", 1);
  }
  return numerator / denominator;
}

int main() {
  int num1, num2, result;
  printf("Enter the numerator: ");
  scanf("%d", &num1);
  printf("Enter the denominator: ");
  scanf("%d", &num2);

  // Error handling for negative values
  if (num1 < 0 || num2 < 0) {
    errorHandler("Negative values not allowed.", 2);
  }

  result = divide(num1, num2);
  printf("Result: %d\n", result);

  return 0;
}