//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>

int main() {
  int num1 = 10;
  int num2 = 20;

  printf("num1 before swap: %d\n", num1);
  printf("num2 before swap: %d\n", num2);

  // bitwise XOR operator to swap values
  num1 = num1 ^ num2;
  num2 = num1 ^ num2;
  num1 = num1 ^ num2;

  printf("\nnum1 after swap: %d\n", num1);
  printf("num2 after swap: %d\n", num2);

  printf("\nNow let's try something mind-bending!\n");

  int a = 10;
  int b = 20;
  int c = 30;
  int d = 40;

  printf("\nBefore operations:\n");
  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);
  printf("d: %d\n", d);

  // bitwise OR operator to set bit 1 in a and b
  a = a | 0x1;
  b = b | 0x1;

  // bitwise XOR operator to toggle bit 5 in c
  c = c ^ (0x1 << 5);

  // bitwise AND operator to clear bits 2 and 4 in d
  d = d & ~(0x1 << 2) & ~(0x1 << 4);

  printf("\nAfter operations:\n");
  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);
  printf("d: %d\n", d);

  return 0;
}