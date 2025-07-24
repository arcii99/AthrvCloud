//FormAI DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>

int main() {
  int dividend, divisor, quotient;

  printf("Enter dividend: ");
  scanf("%d", &dividend);

  printf("Enter divisor: ");
  scanf("%d", &divisor);

  if (divisor == 0) {
    printf("Error: Division by zero\n");
    return 1;
  } else {
    quotient = dividend / divisor;
    printf("Quotient = %d\n", quotient);
    return 0;
  }
}