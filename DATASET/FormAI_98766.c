//FormAI DATASET v1.0 Category: Error handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int dividend, divisor, quotient;

  printf("Enter the dividend: ");
  if (scanf("%d", &dividend) != 1) {
    printf("\nError: Invalid input. Program terminated.\n");
    exit(1);
  }

  printf("Enter the divisor: ");
  if (scanf("%d", &divisor) != 1) {
    printf("\nError: Invalid input. Program terminated.\n");
    exit(1);
  } else if (divisor == 0) {
    printf("\nError: Division by zero. Program terminated.\n");
    exit(1);
  }

  quotient = dividend / divisor;
  printf("%d / %d = %d\n", dividend, divisor, quotient);

  return 0;
}