//FormAI DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include <stdio.h>

int main() {
  // create two variables to perform bitwise operations on
  int a = 9;
  int b = 6;

  // print out the binary representation of each variable
  printf("a in binary: %d%d%d%d\n", (a >> 3) & 1, (a >> 2) & 1, (a >> 1) & 1, a & 1);
  printf("b in binary: %d%d%d\n", (b >> 2) & 1, (b >> 1) & 1, b & 1);

  // perform bitwise AND between a and b and print out the result in binary
  int c = a & b;
  printf("a & b in binary: %d%d%d\n", (c >> 2) & 1, (c >> 1) & 1, c & 1);

  // perform bitwise OR between a and b and print out the result in binary
  int d = a | b;
  printf("a | b in binary: %d%d%d%d\n", (d >> 3) & 1, (d >> 2) & 1, (d >> 1) & 1, d & 1);

  // perform bitwise XOR between a and b and print out the result in binary
  int e = a ^ b;
  printf("a ^ b in binary: %d%d%d\n", (e >> 2) & 1, (e >> 1) & 1, e & 1);

  // perform bitwise complement on a and print out the result in binary
  int f = ~a;
  printf("~a in binary (2's complement): %d%d%d%d\n", (f >> 3) & 1, (f >> 2) & 1, (f >> 1) & 1, f & 1);

  // perform left shift on a and print out the result in binary
  int g = a << 2;
  printf("a << 2 in binary: %d%d%d%d\n", (g >> 3) & 1, (g >> 2) & 1, (g >> 1) & 1, g & 1);

  // perform right shift on a and print out the result in binary
  int h = a >> 2;
  printf("a >> 2 in binary: %d%d%d\n", (h >> 1) & 1, h & 1);

  // use bitwise AND to check if a is odd or even
  if (a & 1) {
    printf("a is odd\n");
  } else {
    printf("a is even\n");
  }

  // use bitwise XOR to swap the values of a and b
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;

  // print out the new values of a and b
  printf("a: %d\n", a);
  printf("b: %d\n", b);

  return 0;
}