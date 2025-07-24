//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Alan Touring
#include <stdio.h>

int main() {
  // Example variables
  unsigned char a = 0b1010, b = 0b1100;

  // Bitwise AND operation
  unsigned char result_AND = a & b;
  printf("Bitwise AND of %d (0x%x) and %d (0x%x) is %d (0x%x)\n", a, a, b, b, result_AND, result_AND);

  // Bitwise OR operation
  unsigned char result_OR = a | b;
  printf("Bitwise OR of %d (0x%x) and %d (0x%x) is %d (0x%x)\n", a, a, b, b, result_OR, result_OR);

  // Bitwise XOR operation
  unsigned char result_XOR = a ^ b;
  printf("Bitwise XOR of %d (0x%x) and %d (0x%x) is %d (0x%x)\n", a, a, b, b, result_XOR, result_XOR);

  // Bitwise complement operation
  unsigned char result_complement = ~a;
  printf("Bitwise complement of %d (0x%x) is %d (0x%x)\n", a, a, result_complement, result_complement);

  // Left shift operation
  unsigned char result_left_shift = a << 2;
  printf("Left shift of %d (0x%x) by 2 is %d (0x%x)\n", a, a, result_left_shift, result_left_shift);

  // Right shift operation
  unsigned char result_right_shift = b >> 2;
  printf("Right shift of %d (0x%x) by 2 is %d (0x%x)\n", b, b, result_right_shift, result_right_shift);

  return 0;
}