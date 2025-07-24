//FormAI DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>

int main() {

   unsigned int a = 60;   // 60 = 0011 1100 
   unsigned int b = 13;   // 13 = 0000 1101 
   int c = 0;           

   // Bitwise AND
   c = a & b;             // 12 = 0000 1100
   printf("a & b = %d\n", c );

   // Bitwise OR
   c = a | b;             // 61 = 0011 1101 
   printf("a | b = %d\n", c );

   // Bitwise XOR
   c = a ^ b;             // 49 = 0011 0001
   printf("a ^ b = %d\n", c );

   // Bitwise NOT
   c = ~a;                // -61 = 1100 0011
   printf("~a = %d\n", c );

   // Left shift
   c = a << 2;            // 240 = 1111 0000
   printf("a << 2 = %d\n", c );

   // Right shift
   c = a >> 2;            // 15 = 0000 1111
   printf("a >> 2 = %d\n", c );

   return 0;
}