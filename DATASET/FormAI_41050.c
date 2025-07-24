//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

int main() {
  int x = 0xF0; // Binary value : 11110000
  int y = 0x0F; // Binary value : 00001111

  // 1. Bitwise AND
  int result_and = x & y; // Binary value : 00000000 (All bits get turned off except last 4 bits)
  printf("Bitwise AND: %x\n", result_and); // Output: 0

  // 2. Bitwise OR
  int result_or = x | y; // Binary value : 11111111 (All bits get turned on except last 4 bits)
  printf("Bitwise OR: %x\n", result_or); // Output: ff

  // 3. Bitwise XOR
  int result_xor = x ^ y; // Binary value : 11111111 (All bits get turned on except first 4 bits)
  printf("Bitwise XOR: %x\n", result_xor); // Output: ff

  // 4. Bitwise NOT
  int result_not_x = ~x; // Binary value : 00001111 (All bits get turned off and turned on l bits)
  int result_not_y = ~y; // Binary value : fffffff0 (All bits get turned off and turned on first l bits)
  printf("Bitwise NOT of X: %x\n", result_not_x); // Output: f
  printf("Bitwise NOT of Y: %x\n", result_not_y); // Output: fffffff0

  // 5. Bitwise Left Shift
  int result_left_shift = x << 2; // Binary value : 11000000 (Last 2 bits get turned off)
  printf("Bitwise Left Shift: %x\n", result_left_shift); // Output: c0

  // 6. Bitwise Right Shift
  int result_right_shift = x >> 2; // Binary value : 1111 (Last 2 bits get turned off)
  printf("Bitwise Right Shift: %x\n", result_right_shift); // Output: f

  return 0;
}