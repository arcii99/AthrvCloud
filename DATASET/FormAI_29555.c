//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include<stdio.h>

int main() {
  int a = 15; // 1111 in binary
  int b = 7; // 0111 in binary

  // Output the binary representation of the numbers
  printf("a in binary: %d%d%d%d\n", (a >> 3) & 1, (a >> 2) & 1, (a >> 1) & 1, a & 1);
  printf("b in binary: %d%d%d%d\n", (b >> 3) & 1, (b >> 2) & 1, (b >> 1) & 1, b & 1);

  // Perform bitwise operations
  int bitwise_and = a & b;
  int bitwise_or = a | b;
  int bitwise_xor = a ^ b;
  int bitwise_complement = ~a;

  printf("a & b = %d\n", bitwise_and);
  printf("a | b = %d\n", bitwise_or);
  printf("a ^ b = %d\n", bitwise_xor);
  printf("~a = %d\n", bitwise_complement);

  // Output the binary representation of the results
  printf("a & b in binary: %d%d%d%d\n", (bitwise_and >> 3) & 1, (bitwise_and >> 2) & 1, (bitwise_and >> 1) & 1, bitwise_and & 1);
  printf("a | b in binary: %d%d%d%d\n", (bitwise_or >> 3) & 1, (bitwise_or >> 2) & 1, (bitwise_or >> 1) & 1, bitwise_or & 1);
  printf("a ^ b in binary: %d%d%d%d\n", (bitwise_xor >> 3) & 1, (bitwise_xor >> 2) & 1, (bitwise_xor >> 1) & 1, bitwise_xor & 1);
  printf("~a in binary: %d%d%d%d\n", (bitwise_complement >> 3) & 1, (bitwise_complement >> 2) & 1, (bitwise_complement >> 1) & 1, bitwise_complement & 1);

  return 0;
}