//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
  unsigned int a, b;
  int c;

  printf("Enter two numbers: ");
  scanf("%u %u", &a, &b);

  printf("\nBitwise AND Operation (&):\n");
  c = a & b;
  printf("%u & %u = %d\n", a, b, c);

  printf("\nBitwise OR Operation (|):\n");
  c = a | b;
  printf("%u | %u = %d\n", a, b, c);

  printf("\nBitwise XOR Operation (^):\n");
  c = a ^ b;
  printf("%u ^ %u = %d\n", a, b, c);

  printf("\nBitwise NOT Operation (~):\n");
  c = ~a;
  printf("~%u = %d\n", a, c);
  c = ~b;
  printf("~%u = %d\n", b, c);

  printf("\nLeft Shift Operation (<<):\n");
  c = a << 2;
  printf("%u << 2 = %d\n", a, c);

  printf("\nRight Shift Operation (>>):\n");
  c = b >> 1;
  printf("%u >> 1 = %d\n", b, c);

  return 0;
}