//FormAI DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>

// Bitwise operations functions

void and_operation(int a, int b) {
  int result = a & b;
  printf("AND Operation: %d & %d = %d\n", a, b, result);
}

void or_operation(int a, int b) {
  int result = a | b;
  printf("OR Operation: %d | %d = %d\n", a, b, result);
}

void xor_operation(int a, int b) {
  int result = a ^ b;
  printf("XOR Operation: %d ^ %d = %d\n", a, b, result);
}

void shift_left_operation(int a, int b) {
  int result = a << b;
  printf("Shift left Operation: %d << %d = %d\n", a, b, result);
}

void shift_right_operation(int a, int b) {
  int result = a >> b;
  printf("Shift right Operation: %d >> %d = %d\n", a, b, result);
}

// Main function
int main() {
  int a = 14;
  int b = 11;

  printf("a = %d, b = %d\n\n", a, b);

  and_operation(a, b);
  or_operation(a, b);
  xor_operation(a, b);
  shift_left_operation(a, b);
  shift_right_operation(a, b);

  return 0;
}