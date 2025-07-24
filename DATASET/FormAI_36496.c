//FormAI DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2;
  printf("Enter two numbers: ");
  scanf("%d %d", &num1, &num2);

  // Checking if divisor is zero
  if (num2 == 0) {
    printf("Error: Division by zero.\n");
    exit(1);  // Exiting with status code 1
  }

  float result = (float) num1 / num2;
  printf("Result: %.2f\n", result);

  return 0;
}