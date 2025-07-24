//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>

int main() {
  int num1 = 25;
  int num2 = 30;

  printf("num1 = %d, num2 = %d\n", num1, num2);

  num1 ^= num2; // XOR operation
  num2 ^= num1;
  num1 ^= num2;

  printf("After swapping using XOR operation:\n");
  printf("num1 = %d, num2 = %d\n", num1, num2);

  int num3 = 100;
  int num4 = 75;
  int num5 = 15;

  printf("\nnum3 = %d, num4 = %d, num5 = %d\n", num3, num4, num5);

  num3 &= num4; // AND operation
  num3 |= num5; // OR operation

  printf("After performing AND and OR operations:\n");
  printf("num3 = %d, num4 = %d, num5 = %d\n", num3, num4, num5);

  int num6 = 12;

  printf("\nnum6 = %d\n", num6);

  num6 <<= 2; // Shift bits to the left by 2

  printf("After shifting bits to the left by 2:\n");
  printf("num6 = %d\n", num6);

  return 0;
}