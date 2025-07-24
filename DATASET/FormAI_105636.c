//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Alan Touring
#include <stdio.h>

int main() {
   unsigned int x = 10; // binary: 0000 1010
   unsigned int y = 7;  // binary: 0000 0111

   // Bitwise AND
   unsigned int res_and = x & y; // 0000 0010
   printf("Bitwise AND: %u\n", res_and);

   // Bitwise OR
   unsigned int res_or = x | y; // 0000 1111
   printf("Bitwise OR: %u\n", res_or);

   // Bitwise XOR
   unsigned int res_xor = x ^ y; // 0000 1101
   printf("Bitwise XOR: %u\n", res_xor);

   // Bitwise NOT
   unsigned int res_not_x = ~x; // 1111 0101
   unsigned int res_not_y = ~y; // 1111 1000
   printf("Bitwise NOT of x: %u\n", res_not_x);
   printf("Bitwise NOT of y: %u\n", res_not_y);

   // Left shift
   unsigned int res_lshift = x << 2; // 0010 1000
   printf("Left shift: %u\n", res_lshift);

   // Right shift
   unsigned int res_rshift = x >> 1; // 0000 0101
   printf("Right shift: %u\n", res_rshift);

   return 0;
}