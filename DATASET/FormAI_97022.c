//FormAI DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>

int main() {
   unsigned char a = 60;    // 0011 1100
   unsigned char b = 13;    // 0000 1101
   int c;

   // Bitwise AND operator
   c = a & b;            // 0000 1100
   printf("a & b = %d\n", c );

   // Bitwise OR operator
   c = a | b;            // 0011 1101
   printf("a | b = %d\n", c );

   // Bitwise XOR operator
   c = a ^ b;            // 0011 0001
   printf("a ^ b = %d\n", c );

   // Complement operator
   c = ~a;               // 1100 0011
   printf("~a = %d\n", c );

   // Left shift operator, shifting bits of a to left
   c = a << 2;           // 1111 0000
   printf("a << 2 = %d\n", c );

   // Right shift operator, shifting bits of a to right
   c = a >> 2;           // 0000 1111
   printf("a >> 2 = %d\n", c );

   return 0;
}