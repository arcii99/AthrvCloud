//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

int main() {
  printf("Welcome to the Bitwise Operations program!\n\n");

  // First, we'll demonstrate the bitwise NOT (~) operator
  int num1 = 9; // binary: 0000 1001
  int result1 = ~num1; // binary: 1111 0110 (in two's complement)
  printf("Bitwise NOT (~) operation on %d: %d\n", num1, result1);

  // Next, let's show the bitwise AND (&) operator
  int num2 = 12; // binary: 0000 1100
  int num3 = 7; // binary: 0000 0111
  int result2 = num2 & num3; // binary: 0000 0100
  printf("Bitwise AND (&) operation on %d and %d: %d\n", num2, num3, result2);

  // Moving on to the bitwise OR (|) operator
  int num4 = 13; // binary: 0000 1101
  int num5 = 8; // binary: 0000 1000
  int result3 = num4 | num5; // binary: 0000 1101
  printf("Bitwise OR (|) operation on %d and %d: %d\n", num4, num5, result3);

  // Time to try the bitwise XOR (^) operator
  int num6 = 15; // binary: 0000 1111
  int num7 = 10; // binary: 0000 1010
  int result4 = num6 ^ num7; // binary: 0000 0101
  printf("Bitwise XOR (^) operation on %d and %d: %d\n", num6, num7, result4);

  // Finally, we'll experiment with bitwise left shift (<<) and right shift (>>)
  int num8 = 3; // binary: 0000 0011
  int result5 = num8 << 2; // binary: 0000 1100
  printf("Bitwise left shift (<<) operation on %d: %d\n", num8, result5);
  
  int num9 = 20; // binary: 0001 0100
  int result6 = num9 >> 3; // binary: 0000 0101
  printf("Bitwise right shift (>>) operation on %d: %d\n", num9, result6);

  printf("\nThanks for testing out our Bitwise Operations program!\n");

  return 0;
}