//FormAI DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>

int main() {
  int a = 12;      // Binary 1100
  int b = 25;      // Binary 11001
  
  int c = a & b;   // Binary 1000 (8)
  printf("Bitwise AND:\n");
  printf("(Decimal) %d & %d = %d\n", a, b, c);
  printf("(Binary) %d & %d = %d\n", a, b, c);
  
  c = a | b;       // Binary 1101 (13)
  printf("\nBitwise OR:\n");
  printf("(Decimal) %d | %d = %d\n", a, b, c);
  printf("(Binary) %d | %d = %d\n", a, b, c);
  
  c = a ^ b;       // Binary 1001 (9)
  printf("\nBitwise XOR:\n");
  printf("(Decimal) %d ^ %d = %d\n", a, b, c);
  printf("(Binary) %d ^ %d = %d\n", a, b, c);
  
  c = ~a;          // Binary 11111111111111111111111111110011 (-13)
  printf("\nBitwise NOT:\n");
  printf("(Decimal) ~%d = %d\n", a, c);
  printf("(Binary) ~%d = %d\n", a, c);
  
  c = a << 2;      // Binary 110000 (48)
  printf("\nBitwise Left Shift:\n");
  printf("(Decimal) %d << 2 = %d\n", a, c);
  printf("(Binary) %d << 2 = %d\n", a, c);
  
  c = b >> 2;      // Binary 110 (6)
  printf("\nBitwise Right Shift:\n");
  printf("(Decimal) %d >> 2 = %d\n", b, c);
  printf("(Binary) %d >> 2 = %d\n", b, c);

  return 0;
}