//FormAI DATASET v1.0 Category: Arithmetic ; Style: interoperable
#include <stdio.h>

int add(int x, int y);     // function prototype for addition
int subtract(int x, int y);   // function prototype for subtraction
int multiply(int x, int y);   // function prototype for multiplication
int divide(int x, int y);   // function prototype for division

int main() {
  int a = 10, b = 5;   // initializing two integers a and b
  
  printf("The sum of %d and %d is %d.\n", a, b, add(a, b));   // calling the add function and printing the result
  printf("The difference between %d and %d is %d.\n", a, b, subtract(a, b));   // calling the subtract function and printing the result
  printf("The product of %d and %d is %d.\n", a, b, multiply(a, b));   // calling the multiply function and printing the result
  printf("The quotient of %d divided by %d is %d.\n", a, b, divide(a, b));   // calling the divide function and printing the result

  return 0;
}

int add(int x, int y) {   // function definition for addition
  return x + y;
}

int subtract(int x, int y) {   // function definition for subtraction
  return x - y;
}

int multiply(int x, int y) {   // function definition for multiplication
  return x * y;
}

int divide(int x, int y) {   // function definition for division
  return x / y;
}