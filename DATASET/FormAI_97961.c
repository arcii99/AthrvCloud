//FormAI DATASET v1.0 Category: Educational ; Style: inquisitive
#include <stdio.h>

int main() {
  int a = 5;
  int b = 7;

  printf("Enter a number: ");
  scanf("%d", &a);

  printf("Enter another number: ");
  scanf("%d", &b);

  printf("The sum of %d and %d is %d\n", a, b, a + b);
  printf("The difference between %d and %d is %d\n", a, b, a - b);
  printf("The product of %d and %d is %d\n", a, b, a * b);

  if (b == 0) {
    printf("Cannot divide by zero!\n");
  } else {
    printf("The quotient of %d and %d is %d with a remainder of %d\n", a, b, a / b, a % b);
  }

  if (a > b) {
    printf("%d is greater than %d\n", a, b);
  } else if (a < b) {
    printf("%d is less than %d\n", a, b);
  } else {
    printf("%d is equal to %d\n", a, b);
  }

  int min = (a < b) ? a : b;
  printf("The minimum of %d and %d is %d\n", a, b, min);

  int max = (a > b) ? a : b;
  printf("The maximum of %d and %d is %d\n", a, b, max);

  return 0;
}

/*
This program accepts two numbers from the user and performs basic arithmetic operations on them.
The user is prompted to enter the two numbers using scanf and the results of the operations are printed to the console using printf.
The program first adds, subtracts, multiplies, and divides the two numbers, then checks if the second number is zero before performing integer division and modulus operations.
It also determines if the first number is greater than, less than, or equal to the second number and prints the result.
Finally, it calculates the minimum and maximum of the two numbers using ternary operators and prints them to the console.
*/