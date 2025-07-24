//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
// Welcome to the Magical Arithmetic program!
// This unique program is designed to do some amazing mathematical operations using basic arithmetic operators.
// Hold on to your hats, folks, because we're about to go on a wild ride!

#include <stdio.h>

int main() {
  int num1, num2, num3;
  float num4, num5, result;

  printf("Enter three integers: ");
  scanf("%d %d %d", &num1, &num2, &num3);

  // Add the first two integers and subtract the third one
  result = (num1 + num2) - num3;
  printf("\nResult of (%d + %d) - %d = %.2f\n", num1, num2, num3, result);

  printf("\nEnter two decimal numbers: ");
  scanf("%f %f", &num4, &num5);

  // Multiply the decimal numbers and round the result to the nearest integer
  result = (int)((num4 * num5) + 0.5);
  printf("\nResult of (%.2f * %.2f) rounded to the nearest integer = %.0f\n", num4, num5, result);

  // Use the modulus operator to get the remainder of dividing num2 by num1
  result = num2 % num1;
  printf("\nRemainder of %d divided by %d = %.2f\n", num2, num1, result);

  // Use the bitwise operators to flip the bits of num3
  result = ~num3;
  printf("\nFlip the bits of %d = %.2f\n", num3, result);

  // Use the conditional operator to check which number is greater
  result = (num1 > num2) ? num1 : num2;
  printf("\nThe greater number between %d and %d is %.2f\n", num1, num2, result);

  return 0;
}