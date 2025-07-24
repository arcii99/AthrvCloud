//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Alan Touring
#include <stdio.h>

int main() {
  unsigned int num1 = 0b11110110; // 246 in binary: 11110110
  unsigned int num2 = 0b00001101; // 13 in binary:  00001101

  // Bitwise AND operation (&)
  unsigned int and_result = num1 & num2;
  printf("Bitwise AND: %u\n", and_result);

  // Bitwise OR operation (|)
  unsigned int or_result = num1 | num2;
  printf("Bitwise OR: %u\n", or_result);

  // Bitwise XOR operation (^)
  unsigned int xor_result = num1 ^ num2;
  printf("Bitwise XOR: %u\n", xor_result);

  // Bitwise NOT operation (~)
  unsigned int not_result = ~num1;
  printf("Bitwise NOT: %u\n", not_result);

  // Left shift operation (<<)
  unsigned int left_shift_result = num1 << 3;
  printf("Left Shift: %u\n", left_shift_result);

  // Right shift operation (>>)
  unsigned int right_shift_result = num2 >> 2;
  printf("Right Shift: %u\n", right_shift_result);

  return 0;
}