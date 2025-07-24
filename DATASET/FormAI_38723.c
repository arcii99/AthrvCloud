//FormAI DATASET v1.0 Category: Educational ; Style: cheerful
#include <stdio.h>

int main() {
  // Cheerful welcoming message
  printf("Welcome to my C educational example program!\n");
  printf("In this program, we will explore the wonderful world of C programming.\n");
  // Variable declaration and initialization
  int num1 = 5;
  int num2 = 10;
  // Addition and output
  int sum = num1 + num2;
  printf("The sum of %d and %d is %d\n", num1, num2, sum);
  // Subtraction and output
  int diff = num2 - num1;
  printf("The difference between %d and %d is %d\n", num2, num1, diff);
  // Multiplication and output
  int prod = num1 * num2;
  printf("The product of %d and %d is %d\n", num1, num2, prod);
  // Division and output
  float quot = (float)num2 / (float)num1;
  printf("The quotient of %d and %d is %f\n", num2, num1, quot);
  // Modulus and output
  int mod = num2 % num1;
  printf("The modulus of %d and %d is %d\n", num2, num1, mod);
  // Conditional statement and output
  if (num1 > num2) {
    printf("%d is greater than %d\n", num1, num2);
  } else if (num2 > num1) {
    printf("%d is greater than %d\n", num2, num1);
  } else {
    printf("%d and %d are equal\n", num1, num2);
  }
  // Looping statement and output
  int i;
  for (i = 0; i < 5; i++) {
    printf("Hello, world!\n");
  }
  // Exiting message
  printf("Thank you for exploring the world of C programming with me!\n");
  return 0;
}