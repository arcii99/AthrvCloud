//FormAI DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void error_exit(const char *msg) {
  fprintf(stderr, "Error message: %s\n", msg);
  exit(EXIT_FAILURE);
}

int safe_divide(int a, int b) {
  if (b == 0) {
    error_exit("Division by zero");
  }
  return a / b;
}

int main() {
  int num1, num2, result;

  printf("Enter two numbers: ");
  if (scanf("%d %d", &num1, &num2) != 2) {
    error_exit("Invalid input");
  }

  // Simple error handling example
  if (num2 == 0) {
    error_exit("Division by zero");
  }

  // Safe error handling with function
  result = safe_divide(num1, num2);
  printf("Result of division: %d\n", result);

  // Out of memory error handling example
  int *ptr = NULL;
  ptr = malloc(sizeof(int) * 10000000000); // Trying to allocate way too much memory
  if (ptr == NULL) {
    error_exit("Failed to allocate memory");
  }
  free(ptr);

  return 0;
}