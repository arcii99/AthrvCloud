//FormAI DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>

/* Define bitwise operators functions */
void and_operation(int x, int y);
void or_operation(int x, int y);
void xor_operation(int x, int y);
void complement_operation(int x);
void left_shift_operation(int x, int n);
void right_shift_operation(int x, int n);

int main() {
  int x = 15, y = 20; // Initialize variables with some integer values

  printf("Bitwise AND Operator:\n");
  and_operation(x, y);
  
  printf("Bitwise OR Operator:\n");
  or_operation(x, y);
  
  printf("Bitwise XOR Operator:\n");
  xor_operation(x, y);
  
  printf("Bitwise Complement Operator:\n");
  complement_operation(x);
  
  printf("Left Shift Operator:\n");
  left_shift_operation(x, 2);
  
  printf("Right Shift Operator:\n");
  right_shift_operation(y, 3);

  return 0;
}

/* Bitwise AND operation */
void and_operation(int x, int y) {
  printf("%d & %d = %d\n", x, y, x & y);
}

/* Bitwise OR operation */
void or_operation(int x, int y) {
  printf("%d | %d = %d\n", x, y, x | y);
}

/* Bitwise XOR operation */
void xor_operation(int x, int y) {
  printf("%d ^ %d = %d\n", x, y, x ^ y);
}

/* Bitwise complement operation */
void complement_operation(int x) {
  printf("~%d = %d\n", x, ~x);
}

/* Left shift operation */
void left_shift_operation(int x, int n) {
  printf("%d << %d = %d\n", x, n, x << n);
}

/* Right shift operation */
void right_shift_operation(int x, int n) {
  printf("%d >> %d = %d\n", x, n, x >> n);
}