//FormAI DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>

#define MASK 0xFF

int main(void) {
  int num1 = 0x12;
  int num2 = 0x34;

  int result = num1 & MASK; // binary AND operation
  printf("result = 0x%02X\n", result);

  result = num2 | MASK; // binary OR operation
  printf("result = 0x%02X\n", result);

  result = num1 ^ num2; // binary XOR operation
  printf("result = 0x%02X\n", result);

  result = ~num1; // binary NOT operation
  printf("result = 0x%02X\n", result);

  result = num2 << 2; // binary left shift operation
  printf("result = 0x%02X\n", result);

  result = num2 >> 2; // binary right shift operation
  printf("result = 0x%02X\n", result);

  return 0;
}