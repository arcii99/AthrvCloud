//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

int main()
{
  int a = 57;
  int b = 23;
  
  printf("a = %d\nb = %d\n\n", a, b);
  
  // Bitwise AND
  printf("a & b = %d\n", a & b);
  
  // Bitwise OR
  printf("a | b = %d\n", a | b);
  
  // Bitwise XOR
  printf("a ^ b = %d\n", a ^ b);
  
  // Bitwise NOT
  printf("~a = %d\n~b = %d\n\n", ~a, ~b);
  
  // Left shift
  printf("a << 2 = %d\n", a << 2);
  
  // Right shift
  printf("a >> 2 = %d\n\n", a >> 2);
  
  // Bitwise AND assignment
  printf("a &= b (a = a & b) = %d\n", a &= b);
  
  // Bitwise OR assignment
  printf("a |= b (a = a | b) = %d\n", a |= b);
  
  // Bitwise XOR assignment
  printf("a ^= b (a = a ^ b) = %d\n\n", a ^= b);
  
  // Left shift assignment
  printf("a <<= 2 (a = a << 2) = %d\n", a <<= 2);
  
  // Right shift assignment
  printf("a >>= 2 (a = a >> 2) = %d\n", a >>= 2);
  
  return 0;
}