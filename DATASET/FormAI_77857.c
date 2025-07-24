//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {
   int x = 15; // 0000 1111
   int y = 22; // 0001 0110

   // Bitwise AND
   int result1 = x & y; // 0000 0110
   printf("x & y = %d\n", result1);

   // Bitwise OR
   int result2 = x | y; // 0001 1111
   printf("x | y = %d\n", result2);

   // Bitwise XOR
   int result3 = x ^ y; // 0001 1001
   printf("x ^ y = %d\n", result3);

   // Bitwise NOT
   int result4 = ~x; // 1111 0000
   printf("~x = %d\n", result4);

   // Bitwise LEFT SHIFT
   int result5 = x << 2; // 0011 1100
   printf("x << 2 = %d\n", result5);

   // Bitwise RIGHT SHIFT
   int result6 = y >> 3; // 0000 0101
   printf("y >> 3 = %d\n", result6);

   return 0;
}