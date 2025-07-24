//FormAI DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>

int main() {
  int x = 15; // initialize x as 15
  int y = 5; // initialize y as 5
  int z; // declare variable z

  // Arithmetic Operations
  z = x + y; // addition
  printf("x + y = %d\n",z);
  
  z = x - y; // subtraction
  printf("x - y = %d\n",z);

  z = x * y; // multiplication
  printf("x * y = %d\n",z);

  z = x / y; // integer division
  printf("x / y = %d\n",z);

  double a = 15.0; // initialize a as 15.0
  double b = 5.0; // initialize b as 5.0
  double c; // declare variable c

  c = a / b; // floating point division
  printf("a / b = %lf\n",c);

  int remainder;
  remainder = x % y; // modulo
  printf("x %% y = %d\n", remainder);

  // Pre-increment and Post-increment Operations
  printf("x before pre-increment: %d\n", x);
  printf("x after pre-increment: %d\n", ++x);

  printf("y before post-increment: %d\n", y);
  printf("y after post-increment: %d\n", y++);

  // Bitwise Operations
  int m = 10; // initialize m as 10
  int n = 15; // initialize n as 15
  int bitwise_and, bitwise_or, bitwise_xor;

  bitwise_and = m & n; // bitwise AND
  printf("m & n = %d\n", bitwise_and);

  bitwise_or = m | n; // bitwise OR
  printf("m | n = %d\n", bitwise_or);

  bitwise_xor = m ^ n; // bitwise XOR
  printf("m ^ n = %d\n", bitwise_xor);

  int left_shift, right_shift;
  int r = 10; // initialize r as 10

  left_shift = r << 2; // left shift
  printf("r << 2 = %d\n", left_shift);

  right_shift = r >> 2; // right shift
  printf("r >> 2 = %d\n", right_shift);

  return 0;
}