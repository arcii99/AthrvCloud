//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, sum, diff, product, quotient, mod;

  printf("Welcome to the futuristic arithmetic machine!\n");
  printf("Please enter your first number: ");
  scanf("%d", &num1);

  printf("Please enter your second number: ");
  scanf("%d", &num2);

  sum = num1 + num2;
  diff = abs(num1 - num2);
  product = num1 * num2;
  quotient = num1 / num2;
  mod = num1 % num2;

  printf("\nWow, I've calculated your results in the blink of an eye!\n");

  printf("\nThe sum of %d and %d is: %d \n", num1, num2, sum);
  printf("The difference of %d and %d is: %d \n", num1, num2, diff);
  printf("The product of %d and %d is: %d \n", num1, num2, product);
  printf("The quotient of %d and %d is: %d \n", num1, num2, quotient);
  printf("The remainder of %d divided by %d is: %d \n", num1, num2, mod);

  if (num1 == num2) {
    printf("\nThe numbers are equal, so there is no minimum or maximum.\n");
  } else {
    int min = num1 < num2 ? num1 : num2;
    int max = num1 > num2 ? num1 : num2;
    printf("\nThe minimum of %d and %d is: %d \n", num1, num2, min);
    printf("The maximum of %d and %d is: %d \n", num1, num2, max);
  }

  return 0;
}