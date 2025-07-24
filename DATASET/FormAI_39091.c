//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

int main() 
{
  unsigned int x = 10;  // binary is 1010
  unsigned int y = 6;   // binary is 0110

  printf("x: %d (binary: %u)\n", x, x);
  printf("y: %d (binary: %u)\n", y, y);

  // Bitwise AND: Sets each bit to 1 if both bits are 1
  unsigned int result_and = x & y;
  printf("Result of Bitwise AND: %d (binary: %u)\n", result_and, result_and);

  // Bitwise OR: Sets each bit to 1 if one of the bits is 1
  unsigned int result_or = x | y;
  printf("Result of Bitwise OR: %d (binary: %u)\n", result_or, result_or);

  // Bitwise XOR: Sets each bit to 1 if only one of the bits is 1
  unsigned int result_xor = x ^ y;
  printf("Result of Bitwise XOR: %d (binary: %u)\n", result_xor, result_xor);

  // Bitwise Complement: Inverts all the bits
  unsigned int result_complement_x = ~x;
  printf("Result of Bitwise Complement on x: %d (binary: %u)\n", result_complement_x, result_complement_x);

  unsigned int result_complement_y = ~y;
  printf("Result of Bitwise Complement on y: %d (binary: %u)\n", result_complement_y, result_complement_y);

  // Bitwise Shift: Shifts the bits to the left by the specified number of positions
  unsigned int result_shift = x << 1;
  printf("Result of Bitwise Shift (left) on x: %d (binary: %u)\n", result_shift, result_shift);

  // Bitwise Shift: Shifts the bits to the right by the specified number of positions
  result_shift = x >> 1;
  printf("Result of Bitwise Shift (right) on x: %d (binary: %u)\n", result_shift, result_shift);

  return 0;
}