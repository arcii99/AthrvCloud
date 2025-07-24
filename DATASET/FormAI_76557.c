//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include<stdio.h>

int main() {
  int a = 10;
  int b = 5;

  // Bitwise AND operator
  int and_result = a & b;
  printf("a & b = %d\n", and_result);

  // Bitwise OR operator
  int or_result = a | b;
  printf("a | b = %d\n", or_result);

  // Bitwise NOT operator
  int not_result = ~a;
  printf("~a = %d\n", not_result);

  // Bitwise XOR operator
  int xor_result = a ^ b;
  printf("a ^ b = %d\n", xor_result);

  // Bitwise left shift operator
  int left_shift_result = a << 1;
  printf("a << 1 = %d\n", left_shift_result);

  // Bitwise right shift operator
  int right_shift_result = a >> 1;
  printf("a >> 1 = %d\n", right_shift_result);

  return 0;
}