//FormAI DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Declare two integer variables */
  int x = 10;
  int y = 5;

  /* Use bitwise AND operator */
  int and_result = x & y;
  printf("Bitwise AND Result: %d\n", and_result);

  /* Use bitwise OR operator */
  int or_result = x | y;
  printf("Bitwise OR Result: %d\n", or_result);

  /* Use bitwise XOR operator */
  int xor_result = x ^ y;
  printf("Bitwise XOR Result: %d\n", xor_result);

  /* Use left shift operator */
  int shift_result = x << 2;
  printf("Left Shift Result: %d\n", shift_result);

  /* Use right shift operator */
  int right_shift_result = x >> 1;
  printf("Right Shift Result: %d\n", right_shift_result);

  /* Use complement operator */
  int complement_result = ~x;
  printf("Complement Result: %d\n", complement_result);

  /* Use bitwise AND operator with hexadecimal values */
  int hex_x = 0x3F; // 0011 1111
  int hex_y = 0xC0; // 1100 0000
  int hex_and_result = hex_x & hex_y; // 0000 0000
  printf("Hexadecimal Bitwise AND Result: %02X\n", hex_and_result);

  /* Use bitwise OR operator with binary values */
  int binary_x = 0b1101; // 13
  int binary_y = 0b0011; // 3
  int binary_or_result = binary_x | binary_y; // 15
  printf("Binary Bitwise OR Result: %d\n", binary_or_result);

  return 0;
}