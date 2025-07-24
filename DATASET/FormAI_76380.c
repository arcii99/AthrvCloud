//FormAI DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  int dividend = 50;
  int divisor = 0;
  int quotient;

  if (divisor == 0) {
    fprintf(stderr, "Error: Division by zero. Exiting program. \n");
    exit(EXIT_FAILURE);
  } else {
    quotient = dividend / divisor;
    printf("Quotient: %d\n", quotient);
  }

  return 0;
}