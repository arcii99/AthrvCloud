//FormAI DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>

int main() {
  int num1, num2, sum, diff, prod, quo, mod;
  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);

  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;
  quo = num1 / num2;
  mod = num1 % num2;

  printf("Sum = %d\n", sum);
  printf("Difference = %d\n", diff);
  printf("Product = %d\n", prod);
  printf("Quotient = %d\n", quo);
  printf("Modulus = %d\n", mod);

  return 0;
}