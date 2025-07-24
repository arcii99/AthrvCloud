//FormAI DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int dividend = 20;
  int divisor = 0;
  int quotient;

  if (divisor == 0) {
    fprintf(stderr, "Cannot divide by zero!\n");
    exit(EXIT_FAILURE);
  }

  quotient = dividend / divisor;

  printf("Quotient: %d\n", quotient);

  return 0;
}