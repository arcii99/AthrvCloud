//FormAI DATASET v1.0 Category: Bitwise operations ; Style: active
#include <stdio.h>

int main() {
  int a = 25; // binary value 00011001
  int b = 18; // binary value 00010010

  printf("Bitwise AND: %d\n", a & b); // 00010000 (16)
  printf("Bitwise OR: %d\n", a | b); // 00011011 (27)
  printf("Bitwise XOR: %d\n", a ^ b); // 00001011 (11)
  printf("Bitwise Complement of a: %d\n", ~a); // 11100110 (-26)
  printf("Bitwise Left Shift of a by 2: %d\n", a << 2); // 01100100 (100)
  printf("Bitwise Right Shift of a by 2: %d\n", a >> 2); // 00000110 (6)

  // Bitwise Setting of 3rd bit of a to 1
  a = a | (1 << 2); // 00011001 -> 000110101
  printf("Setting 3rd bit of a to 1: %d\n", a); // 29

  // Bitwise Clearing of 4th bit of b to 0
  b = b & ~(1 << 3); // 00010010 -> 00000010
  printf("Clearing 4th bit of b to 0: %d\n", b); // 2

  // Bitwise Toggling of 5th bit of a
  a = a ^ (1 << 4); // 00011001 -> 00010001
  printf("Toggling 5th bit of a: %d\n", a); // 17

  return 0;
}