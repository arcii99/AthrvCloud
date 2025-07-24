//FormAI DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>

int main() {
  int num1, num2, sum, diff, prod;
  float quotient;

  printf("Enter first number: ");
  scanf("%d", &num1);

  printf("Enter second number: ");
  scanf("%d", &num2);

  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;

  if (num2 != 0) {
    quotient = num1 / (float)num2;
    printf("Quotient: %.2f\n", quotient);
  } else {
    printf("The second number cannot be zero for division.\n");
  }

  printf("Sum: %d\n", sum);
  printf("Difference: %d\n", diff);
  printf("Product: %d\n", prod);

  return 0;
}