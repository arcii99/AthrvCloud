//FormAI DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>

int main() {
  int a = 25;
  int b = 7;
  
  // Bitwise AND
  int bit_and = a & b;
  printf("Bitwise AND of %d and %d is %d\n", a, b, bit_and);
  
  // Bitwise OR
  int bit_or = a | b;
  printf("Bitwise OR of %d and %d is %d\n", a, b, bit_or);

  // Bitwise XOR
  int bit_xor = a ^ b;
  printf("Bitwise XOR of %d and %d is %d\n", a, b, bit_xor);

  // Bitwise NOT
  int bit_not = ~a;
  printf("Bitwise NOT of %d is %d\n", a, bit_not);

  // Left Shift
  int left_shift = a << 2;
  printf("%d shifted left by 2 bits is %d\n", a, left_shift);

  // Right Shift
  int right_shift = a >> 1;
  printf("%d shifted right by 1 bit is %d\n", a, right_shift);

  // Clear bit
  int clear_bit = a & ~(1 << 3);
  printf("Clearing 3rd bit of %d is %d\n", a, clear_bit);

  // Set bit
  int set_bit = a | (1 << 4);
  printf("Setting 4th bit of %d is %d\n", a, set_bit);

  // Toggle bit
  int toggle_bit = a ^ (1 << 2);
  printf("Toggling 2nd bit of %d is %d\n", a, toggle_bit);

  return 0;
}