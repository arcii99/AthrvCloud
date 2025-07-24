//FormAI DATASET v1.0 Category: Bitwise operations ; Style: brave
#include <stdio.h>

int main() {
  int a = 25, b = 22;

  printf("The binary representation of %d is: ", a);
  printBinary(a);
  printf("\nThe binary representation of %d is: ", b);
  printBinary(b);
  
  // Perform bitwise AND operator on a and b
  int c = a & b;
  printf("\nThe result of bitwise AND between %d and %d is %d\n", a, b, c);
  printf("The binary representation of %d is: ", c);
  printBinary(c);
  
  // Perform bitwise OR operator on a and b
  int d = a | b;
  printf("\nThe result of bitwise OR between %d and %d is %d\n", a, b, d);
  printf("The binary representation of %d is: ", d);
  printBinary(d);
  
  // Perform bitwise XOR operator on a and b
  int e = a ^ b;
  printf("\nThe result of bitwise XOR between %d and %d is %d\n", a, b, e);
  printf("The binary representation of %d is: ", e);
  printBinary(e);
  
  // Perform bitwise NOT operator on a
  int f = ~a;
  printf("\nThe result of bitwise NOT of %d is %d\n", a, f);
  printf("The binary representation of %d is: ", f);
  printBinary(f);

  return 0;
}

void printBinary(int n) {
  if (n > 1) {
    printBinary(n / 2);
  }
  printf("%d", n % 2);
}