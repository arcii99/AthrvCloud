//FormAI DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

int main() {

  int num1, num2, sum, difference, product, quotient, remainder;
  printf("Enter the first number: "); // prompt user to input first number
  scanf("%d", &num1); // read input from user and store it in variable num1

  printf("Enter the second number: "); // prompt user to input second number
  scanf("%d", &num2); // read input from user and store it in variable num2

  // perform arithmetic operations on num1 and num2
  sum = num1 + num2;
  difference = num1 - num2;
  product = num1 * num2;
  quotient = num1 / num2;
  remainder = num1 % num2;

  printf("The sum of %d and %d is %d\n", num1, num2, sum); // print sum of num1 and num2
  printf("The difference of %d and %d is %d\n", num1, num2, difference); // print difference of num1 and num2
  printf("The product of %d and %d is %d\n", num1, num2, product); // print product of num1 and num2
  printf("The quotient of %d divided by %d is %d\n", num1, num2, quotient); // print quotient of num1 divided by num2
  printf("The remainder of %d divided by %d is %d\n", num1, num2, remainder); // print remainder of num1 divided by num2

  return 0;
}