//FormAI DATASET v1.0 Category: Arithmetic ; Style: mathematical
#include <stdio.h>

int main() {
  // Let's define our variables
  int x = 10;
  int y = 5;
  int z;

  // Let's perform some arithmetic operations
  z = x + y;
  printf("When %d is added to %d the result is %d.\n", x, y, z);

  z = x - y;
  printf("When %d is subtracted from %d the result is %d.\n", y, x, z);

  z = x * y;
  printf("When %d is multiplied by %d the result is %d.\n", x, y, z);

  z = x / y;
  printf("When %d is divided by %d the quotient is %d.\n", x, y, z);

  // Modulo operator
  z = x % y;
  printf("When %d is divided by %d the remainder is %d.\n", x, y, z);

  // Increment and Decrement operators
  printf("The value of x is %d.\n", x);
  x++;
  printf("After incrementing, the value of x is %d.\n", x);
  x--;
  printf("After decrementing, the value of x is %d.\n", x);

  return 0;
}