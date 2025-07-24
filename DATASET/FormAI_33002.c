//FormAI DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include <stdio.h>

int main() {
  int a = 15; // 1111 in binary
  int b = 7; // 0111 in binary
  
  // Bitwise AND operator
  int result_and = a & b; // 0111 in binary
  printf("a & b = %d\n", result_and); // Expected output: 7
  
  // Bitwise OR operator
  int result_or = a | b; // 1111 in binary
  printf("a | b = %d\n", result_or); // Expected output: 15
  
  // Bitwise XOR operator
  int result_xor = a ^ b; // 1000 in binary
  printf("a ^ b = %d\n", result_xor); // Expected output: 8
  
  // Bitwise NOT operator
  int result_not_a = ~a; // 0000 0000 0000 0000 0000 0000 0000 1110 in binary
  printf("~a = %d\n", result_not_a); // Expected output: -16
  
  int result_not_b = ~b; // 1111 1111 1111 1111 1111 1111 1111 1000 in binary
  printf("~b = %d\n", result_not_b); // Expected output: -8
  
  // Left shift operator
  int result_left_shift = a << 2; // 1111 0000 in binary
  printf("a << 2 = %d\n", result_left_shift); // Expected output: 60
  
  // Right shift operator
  int result_right_shift = b >> 2; // 0000 0001 in binary
  printf("b >> 2 = %d\n", result_right_shift); // Expected output: 1
  
  return 0;
}