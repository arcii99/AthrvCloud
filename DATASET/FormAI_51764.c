//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
   // Declare variables
   unsigned int x = 60; // 0011 1100
   unsigned int y = 13; // 0000 1101
   int result;

   // Bitwise AND operator
   result = x & y; // 0000 1100
   printf("x & y = %d\n", result);

   // Bitwise OR operator
   result = x | y; // 0011 1101
   printf("x | y = %d\n", result);

   // Bitwise XOR operator
   result = x ^ y; // 0011 0001
   printf("x ^ y = %d\n", result);

   // Bitwise complement operator
   result = ~x; // 1100 0011
   printf("~x = %d\n", result);

   // Left shift operator
   result = x << 2; // 1111 0000
   printf("x << 2 = %d\n", result);

   // Right shift operator
   result = x >> 2; // 0000 1111
   printf("x >> 2 = %d\n", result);

   return 0;
}