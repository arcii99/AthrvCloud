//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include <stdio.h>

int main() {
  int x = 10; // binary form 1010
  int y = 7;  // binary form 0111

  // Bitwise AND operation
  int and_result = x & y; // binary form 0010
  printf("Bitwise AND result: %d\n", and_result);

  // Bitwise OR operation
  int or_result = x | y; // binary form 1111
  printf("Bitwise OR result: %d\n", or_result);

  // Bitwise XOR operation
  int xor_result = x ^ y; // binary form 1101
  printf("Bitwise XOR result: %d\n", xor_result);

  // Bitwise Complement operation
  int complement_result = ~x; // binary form 11111111111111111111111111110101
  printf("Bitwise Complement result: %d\n", complement_result);

  // Bitwise SHIFT LEFT operation
  int shift_left_result = x << 2; // binary form 101000
  printf("Bitwise Shift Left result: %d\n", shift_left_result);

  // Bitwise SHIFT RIGHT operation
  int shift_right_result = x >> 2; // binary form 0001
  printf("Bitwise Shift Right result: %d\n", shift_right_result);

  return 0;
}