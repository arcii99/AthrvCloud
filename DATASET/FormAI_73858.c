//FormAI DATASET v1.0 Category: Bitwise operations ; Style: portable
#include <stdio.h>

int main() {
  unsigned int a = 30; // 00011110 in binary
  unsigned int b = 15; // 00001111 in binary

  // bitwise AND operation
  unsigned int result_AND = a & b; // 00001110 in binary
  printf("AND result: %d \n", result_AND);

  // bitwise OR operation
  unsigned int result_OR = a | b; // 00011111 in binary
  printf("OR result: %d \n", result_OR);

  // bitwise XOR operation
  unsigned int result_XOR = a ^ b; // 00010001 in binary
  printf("XOR result: %d \n", result_XOR);

  // bitwise NOT operation
  unsigned int result_NOT = ~a; // 11100001 in binary
  printf("NOT result for a: %d \n", result_NOT);

  // bitwise left shift
  unsigned int result_LS = a << 2; // 01111000 in binary, 120 in decimal
  printf("Left shift result: %d \n", result_LS);

  // bitwise right shift
  unsigned int result_RS = a >> 2; // 00000111 in binary, 7 in decimal
  printf("Right shift result: %d \n", result_RS);

  return 0;
}