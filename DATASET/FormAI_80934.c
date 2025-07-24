//FormAI DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>

int main() {
   unsigned int a = 60; // 0011 1100
   unsigned int b = 13; // 0000 1101
   int c = 0;           

   // Bitwise AND operator
   c = a & b;            // 0000 1100
   printf("Result of Bitwise AND: %d\n", c );

   // Bitwise OR operator
   c = a | b;            // 0011 1101
   printf("Result of Bitwise OR: %d\n", c );

   // Bitwise XOR operator
   c = a ^ b;            // 0011 0001
   printf("Result of Bitwise XOR: %d\n", c );

   // Bitwise NOT operator
   c = ~a;               // 1100 0011
   printf("Result of Bitwise NOT for a: %d\n", c );

   c = ~b;               // 1111 0010
   printf("Result of Bitwise NOT for b: %d\n", c );

   // Left shift operator
   c = a << 2;           // 1111 0000
   printf("Result of Left Shift: %d\n", c );

   // Right shift operator
   c = a >> 2;           // 0000 1111
   printf("Result of Right Shift: %d\n", c );

   return 0;
}