//FormAI DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>

int main() {
  int num1, num2, sum, product, difference, quotient, remainder;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("\nEnter the second number: ");
  scanf("%d", &num2);

  sum = num1 + num2;
  product = num1 * num2;
  difference = num1 - num2;
  quotient = num1 / num2;
  remainder = num1 % num2;

  printf("\nSum of %d and %d is: %d", num1, num2, sum);
  printf("\nProduct of %d and %d is: %d", num1, num2, product);
  printf("\nDifference of %d and %d is: %d", num1, num2, difference);
  printf("\nQuotient of %d and %d is: %d", num1, num2, quotient);
  printf("\nRemainder of %d and %d is: %d", num1, num2, remainder);

  int i;
  printf("\n\nPrinting 10 multiples of the sum: \n");
  for (i = 1; i <= 10; i++) {
    printf("%d x %d = %d \n", sum, i, (sum * i));
  }

  printf("\nPrinting the sum in reverse order:\n");
  for (i = sum; i >= 1; i--) {
    printf("%d\n", i);
  }

  printf("\nPrinting the sum in 3's multiples:\n");
  for (i = 3; i <= sum; i += 3) {
    printf("%d\n", i);
  }

  printf("\nPrinting the ASCII value of the sum:\n");
  printf("%d\n", sum);

  return 0;
}