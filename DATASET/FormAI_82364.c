//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

int main() {
  int a = 10;
  int b = 20;
  
  printf("a: %d\tb:%d\n", a, b);
  
  // Bitwise AND
  int and_result = a & b;
  printf("a & b: %d\n", and_result);
  
  // Bitwise OR
  int or_result = a | b;
  printf("a | b: %d\n", or_result);
  
  // Bitwise XOR
  int xor_result = a ^ b;
  printf("a ^ b: %d\n", xor_result);
  
  // Bitwise NOT
  int not_result = ~a;
  printf("~a: %d\n", not_result);
  
  // Left shift
  int left_shift = a << 2;
  printf("a << 2: %d\n", left_shift);
  
  // Right shift
  int right_shift = b >> 1;
  printf("b >> 1: %d\n", right_shift);
  
  // Bitwise AND assignment
  a &= b;
  printf("a &= b: %d\n", a);
  
  // Bitwise OR assignment
  b |= a;
  printf("b |= a: %d\n", b);
  
  // Bitwise XOR assignment
  a ^= b;
  printf("a ^= b: %d\n", a);
  
  return 0;
}