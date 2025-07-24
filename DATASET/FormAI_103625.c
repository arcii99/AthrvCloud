//FormAI DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>

int main() {
  int x = 10, y = 5;
  long result;

  // Addition of two numbers
  result = x + y;
  printf("%d + %d = %ld\n", x, y, result);

  // Subtraction of two numbers
  result = x - y;
  printf("%d - %d = %ld\n", x, y, result);

  // Multiplication of two numbers
  result = x * y;
  printf("%d * %d = %ld\n", x, y, result);

  // Division of two numbers
  result = x / y;
  printf("%d / %d = %ld\n", x, y, result);

  // Modulus of two numbers
  result = x % y;
  printf("%d %% %d = %ld\n", x, y, result);

  // Increment operator
  x++;
  printf("x is now %d\n", x);

  // Decrement operator
  y--;
  printf("y is now %d\n", y);

  // Pre-increment operator
  ++x;
  printf("x is now %d\n", x);

  // Pre-decrement operator
  --y;
  printf("y is now %d\n", y);

  // Assignment operators
  x += y;
  printf("x += y is %d\n", x);

  x -= y;
  printf("x -= y is %d\n", x);

  x *= y;
  printf("x *= y is %d\n", x);

  x /= y;
  printf("x /= y is %d\n", x);

  x %= y;
  printf("x %%= y is %d\n", x);

  return 0;
}