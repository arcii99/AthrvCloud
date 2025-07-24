//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Cyberpunk
#include <stdio.h>

int main() {
  int x = 0b1101; // Represents binary number 1101

  // Left shift operator
  int y = x << 2; // Shifts bits to left by 2 positions
  printf("Left Shift Operator: %d << 2 = %d\n", x, y);

  // Right shift operator
  int z = x >> 1; // Shifts bits to right by 1 position
  printf("Right Shift Operator: %d >> 1 = %d\n", x, z);

  // Bitwise AND operator
  int a = 0b1010;
  int b = 0b1100;
  int c = a & b; // Only 1 where both bits are 1, else 0
  printf("Bitwise AND Operator: %d & %d = %d\n", a, b, c);

  // Bitwise OR operator
  int d = a | b; // 1 where either bits are 1, else 0
  printf("Bitwise OR Operator: %d | %d = %d\n", a, b, d);

  // Bitwise XOR operator
  int e = a ^ b; // 1 where bits are different, else 0
  printf("Bitwise XOR Operator: %d ^ %d = %d\n", a, b, e);

  return 0;
}