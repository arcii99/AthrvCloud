//FormAI DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  int dividend, divisor;
  float quotient;
  printf("Enter dividend: ");
  if (scanf("%d", &dividend) != 1) { // Error handling for incorrect input format
    printf("ERROR: Invalid input for dividend\n");
    exit(EXIT_FAILURE);
  }
  printf("Enter divisor: ");
  if (scanf("%d", &divisor) != 1) { // Error handling for incorrect input format
    printf("ERROR: Invalid input for divisor\n");
    exit(EXIT_FAILURE);
  }
  if (divisor == 0) { // Error handling for division by zero
    printf("ERROR: Cannot divide by zero\n");
    exit(EXIT_FAILURE);
  }
  quotient = (float)dividend / divisor; // Typecast to float for accurate division result
  printf("Quotient = %f\n", quotient);
  return 0;
}