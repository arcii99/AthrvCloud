//FormAI DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>

int bitwiseAND(int a, int b) {
  return a & b;
}

int bitwiseOR(int a, int b) {
  return a | b;
}

int bitwiseXOR(int a, int b) {
  return a ^ b;
}

int bitwiseNOT(int a) {
  return ~a;
}

int leftShift(int a, int b) {
  return a << b;
}

int rightShift(int a, int b) {
  return a >> b;
}

int main() {
  int a = 5;
  int b = 10;

  // Bitwise AND
  printf("Bitwise AND: %d & %d = %d\n", a, b, bitwiseAND(a, b));

  // Bitwise OR
  printf("Bitwise OR: %d | %d = %d\n", a, b, bitwiseOR(a, b));

  // Bitwise XOR
  printf("Bitwise XOR: %d ^ %d = %d\n", a, b, bitwiseXOR(a, b));

  // Bitwise NOT
  printf("Bitwise NOT of %d = %d\n", a, bitwiseNOT(a));

  // Left Shift
  printf("Left shift of %d by %d = %d\n", a, b, leftShift(a, b));

  // Right Shift
  printf("Right shift of %d by %d = %d\n", a, b, rightShift(b, a));

  return 0;
}