//FormAI DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
// Let's get ready to crunch some numbers!

#include <stdio.h>

int main() {

  // Declare some variables
  int num1, num2, sum, difference, quotient, product;

  // Prompt the user to enter two numbers
  printf("Let's do some arithmetic! Please enter two numbers.\n");
  scanf("%d", &num1); // Store first number in num1
  scanf("%d", &num2); // Store second number in num2

  // Perform some calculations
  sum = num1 + num2; // Add num1 and num2 together
  difference = num1 - num2; // Subtract num2 from num1
  quotient = num1 / num2; // Divide num1 by num2
  product = num1 * num2; // Multiply num1 and num2

  // Output the results with some enthusiasm!
  printf("The sum of %d and %d is %d! Woohoo!\n", num1, num2, sum);
  printf("The difference between %d and %d is %d! Yay!\n", num1, num2, difference);
  printf("The quotient of %d and %d is %d! Huzzah!\n", num1, num2, quotient);
  printf("The product of %d and %d is %d! Awesome!\n", num1, num2, product);

  return 0;
}