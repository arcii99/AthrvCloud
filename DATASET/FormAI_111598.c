//FormAI DATASET v1.0 Category: Bitwise operations ; Style: portable
#include <stdio.h>

int main() {
   unsigned int a = 60;    // 60 = 0011 1100
   unsigned int b = 13;    // 13 = 0000 1101
   int c = 0;

   // Bitwise AND operator
   c = a & b;       // 12 = 0000 1100
   printf("Line 1 - Value of c is %d\n", c );

   // Bitwise OR operator
   c = a | b;       // 61 = 0011 1101
   printf("Line 2 - Value of c is %d\n", c );

   // Bitwise XOR operator
   c = a ^ b;       // 49 = 0011 0001
   printf("Line 3 - Value of c is %d\n", c );

   // Bitwise NOT operator
   c = ~a;          // -61 = 1100 0011
   printf("Line 4 - Value of c is %d\n", c );

   // Left shift operator
   c = a << 2;      // 240 = 1111 0000
   printf("Line 5 - Value of c is %d\n", c );

   // Right shift operator
   c = a >> 2;      // 15 = 0000 1111
   printf("Line 6 - Value of c is %d\n", c );

   return 0;
}