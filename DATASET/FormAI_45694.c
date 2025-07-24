//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>

int main() {
  int x = 10, y = 5;

  printf("Welcome to the magical world of arithmetic!\n");
  printf("x = %d, y = %d\n", x, y);
  printf("-------------------------\n");

  // Addition
  printf("x + y = %d\n", x+y);

  // Subtraction
  printf("x - y = %d\n", x-y);

  // Multiplication
  printf("x * y = %d\n", x*y);

  // Division
  printf("x / y = %d\n", x/y);

  // Modulo
  printf("x %% y = %d\n", x%y);

  // Increment
  printf("++x = %d\n", ++x);

  // Decrement
  printf("--y = %d\n", --y);

  printf("-------------------------\n");

  // Bitwise Operations
  int a = 5, b = 3;
  printf("a = %d, b = %d\n", a, b);

  // Bitwise AND
  printf("a & b = %d\n", a&b);

  // Bitwise OR
  printf("a | b = %d\n", a|b);

  // Bitwise XOR
  printf("a ^ b = %d\n", a^b);

  // Bitwise NOT
  printf("~a = %d, ~b = %d\n", ~a, ~b);

  printf("-------------------------\n");

  // Shift Operations
  int c = 15, d = 2;
  printf("c = %d, d = %d\n", c, d);

  // Left Shift
  printf("c << d = %d\n", c<<d);

  // Right Shift
  printf("c >> d = %d\n", c>>d);

  printf("-------------------------\n");

  // Assignment Operations
  int e = 10;

  // Simple Assignment
  printf("e = %d\n", e);

  // Add and Assign
  e += 5;
  printf("e += 5 --> e = %d\n", e);

  // Subtract and Assign
  e -= 2;
  printf("e -= 2 --> e = %d\n", e);

  // Multiply and Assign
  e *= 3;
  printf("e *= 3 --> e = %d\n", e);

  // Divide and Assign
  e /= 2;
  printf("e /= 2 --> e = %d\n", e);

  // Modulo and Assign
  e %= 2;
  printf("e %%= 2 --> e = %d\n", e);

  // Left Shift and Assign
  e <<= 2;
  printf("e <<= 2 --> e = %d\n", e);

  // Right Shift and Assign
  e >>= 1;
  printf("e >>= 1 --> e = %d\n", e);

  // Bitwise AND and Assign
  e &= 5;
  printf("e &= 5 --> e = %d\n", e);

  // Bitwise OR and Assign
  e |= 7;
  printf("e |= 7 --> e = %d\n", e);

  // Bitwise XOR and Assign
  e ^= 3;
  printf("e ^= 3 --> e = %d\n", e);

  printf("-------------------------\n");

  // Conditional and Logical Operators
  int f = 7;
  int g = 3;
  int h = (f > g) ? f : g;
  printf("f = %d, g = %d, h = %d\n", f, g, h);

  int i = 10;
  int j = 5;
  int k = (i > j) && (i%j == 0);
  printf("i = %d, j = %d, k = %d\n", i, j, k);

  int l = 10;
  int m = 5;
  int n = (l < m) || (l%m == 0);
  printf("l = %d, m = %d, n = %d\n", l, m, n);

  return 0;
}