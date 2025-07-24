//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>

int main() {
  // Bitwise OR example
  int a = 5; // 0101 in binary
  int b = 10; // 1010 in binary
  int c = a | b; // 1111 in binary (decimal 15)
  printf("Bitwise OR example: %d | %d = %d\n", a, b, c);
  
  // Bitwise AND example
  int d = 15; // 1111 in binary
  int e = 12; // 1100 in binary
  int f = d & e; // 1100 in binary (decimal 12)
  printf("Bitwise AND example: %d & %d = %d\n", d, e, f);
  
  // Bitwise XOR example
  int g = 10; // 1010 in binary
  int h = 12; // 1100 in binary
  int i = g ^ h; // 0110 in binary (decimal 6)
  printf("Bitwise XOR example: %d ^ %d = %d\n", g, h, i);
  
  // Bitwise NOT example
  int j = 15; // 1111 in binary
  int k = ~j; // 0000 in binary, but with a bunch of leading 1's (decimal -16)
  printf("Bitwise NOT example: ~%d = %d\n", j, k);
  
  // Bitwise left shift example
  int l = 5; // 0101 in binary
  int m = l << 2; // 010100 in binary (decimal 20)
  printf("Bitwise left shift example: %d << 2 = %d\n", l, m);
  
  // Bitwise right shift example
  int n = 42; // 101010 in binary
  int o = n >> 1; // 010101 in binary (decimal 21)
  printf("Bitwise right shift example: %d >> 1 = %d\n", n, o);
  
  return 0;
}