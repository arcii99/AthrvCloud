//FormAI DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>

int main() {
   unsigned int a = 60;   // 60 = 0011 1100
   unsigned int b = 13;   // 13 = 0000 1101
   int result = 0;

   // Examples of Bitwise operators in C

   // 1. Bitwise AND operator
   result = a & b;        // 12 = 0000 1100
   printf("a & b = %d\n", result );

   // 2. Bitwise OR operator
   result = a | b;        // 61 = 0011 1101
   printf("a | b = %d\n", result );

   // 3. Bitwise XOR operator
   result = a ^ b;        // 49 = 0011 0001
   printf("a ^ b = %d\n", result );

   // 4. Bitwise NOT operator
   result = ~a;           // -61 = 1100 0011
   printf("~a = %d\n", result );

   // 5. Bitwise Left Shift operator
   result = a << 2;       // 240 = 1111 0000
   printf("a << 2 = %d\n", result );

   // 6. Bitwise Right Shift operator
   result = a >> 2;       // 15 = 0000 1111
   printf("a >> 2 = %d\n", result );

   return 0;
}