//FormAI DATASET v1.0 Category: Bitwise operations ; Style: interoperable
#include <stdio.h>

int main() {
   int a = 7; //00000111
   int b = 4; //00000100
   
   // Bitwise AND
   printf("a & b = %d\n", a&b);

   // Bitwise OR
   printf("a | b = %d\n", a|b);

   // Bitwise XOR
   printf("a ^ b = %d\n", a^b);

   // Bitwise NOT
   printf("~a = %d\n", ~a);

   // Left Shift
   printf("a << 1 = %d\n", a<<1);
   
   // Right Shift
   printf("a >> 1 = %d\n", a>>1);

   // Binary AND Assignment
   a &= b;
   printf("a &= b; a = %d\n", a);

   // Binary OR Assignment
   a |= b;
   printf("a |= b; a = %d\n", a);

   // Binary XOR Assignment
   a ^= b;
   printf("a ^= b; a = %d\n", a);

   // Left Shift Assignment
   a <<= 1;
   printf("a <<= 1; a = %d\n", a);

   // Right Shift Assignment
   a >>= 1;
   printf("a >>= 1; a = %d\n", a);

   return 0;
}