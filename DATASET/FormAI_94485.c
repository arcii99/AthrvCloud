//FormAI DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>

int main() {
  int num1, num2, sum, difference, product, quotient, remainder;

  printf("Enter two integers: ");
  scanf("%d %d", &num1, &num2);

  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  quotient = num1 / num2;
  remainder = num1 % num2;

  printf("The sum of %d and %d is %d\n", num1, num2, sum);
  printf("The difference between %d and %d is %d\n", num1, num2, difference);
  printf("The product of %d and %d is %d\n", num1, num2, product);
  printf("The quotient of %d and %d is %d\n", num1, num2, quotient);
  printf("The remainder when %d is divided by %d is %d\n", num1, num2, remainder);

  return 0;
}