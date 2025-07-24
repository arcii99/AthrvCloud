//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void handleError(int errorCode);

int main() {
  int a = 5, b = 0, result;

  if (b == 0) {
    handleError(100);
    exit(0);
  }

  result = a / b;

  printf("Result: %d\n", result);

  return 0;
}

void handleError(int errorCode) {
  printf("Oops, something went wrong!\n");

  switch (errorCode) {
    case 100:
      printf("Error Code %d: Division by zero\n", errorCode);
      break;
    default:
      printf("Error Code %d: Unknown error occurred\n", errorCode);
      break;
  }

  // Gracefully handle the error and shutdown the program
  printf("Exiting the program now...\n");
}