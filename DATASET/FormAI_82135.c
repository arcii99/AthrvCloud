//FormAI DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include <stdio.h>

int main() {
   int x = 10;    // In binary, 10 = 1010
   int y = 7;     // In binary, 7 = 0111

   // Bitwise AND operator
   int result = x & y;    // 1010 & 0111 = 0010 (decimal 2)
   printf("x & y = %d\n", result);

   // Bitwise OR operator
   result = x | y;        // 1010 | 0111 = 1111 (decimal 15)
   printf("x | y = %d\n", result);

   // Bitwise XOR operator
   result = x ^ y;        // 1010 ^ 0111 = 1101 (decimal 13)
   printf("x ^ y = %d\n", result);

   // Bitwise NOT operator
   result = ~x;           // ~1010 = 0101 (decimal -11 due to two's complement)
   printf("~x = %d\n", result);

   // Bitwise shift left operator
   result = x << 2;       // 1010 << 2 = 101000 (decimal 40)
   printf("x << 2 = %d\n", result);

   // Bitwise shift right operator
   result = y >> 1;       // 0111 >> 1 = 0011 (decimal 3)
   printf("y >> 1 = %d\n", result);

   return 0;
}