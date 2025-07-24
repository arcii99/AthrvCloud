//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include <stdio.h>

int main() {
   int a = 5; // 0101 in binary
   int b = 9; // 1001 in binary

   // Bitwise AND: & (both bits must be 1 for result to be 1)
   int c = a & b; // 0001 (binary) = 1 (decimal)
   printf("a & b = %d\n", c);
   
   // Bitwise OR: | (at least one bit must be 1 for result to be 1)
   c = a | b; // 1101 (binary) = 13 (decimal)
   printf("a | b = %d\n", c);

   // Bitwise XOR: ^ (only one bit can be 1 for result to be 1)
   c = a ^ b; // 1100 (binary) = 12 (decimal)
   printf("a ^ b = %d\n", c);

   // Bitwise complement: ~ (1s compliment)
   c = ~a; // 1010 (binary) = -6 (decimal)
   printf("~a = %d\n", c);

   // Bitwise left shift: << (shifts bits to the left by a given number of positions)
   c = a << 2; // 010100 (binary) = 20 (decimal)
   printf("a << 2 = %d\n", c);

   // Bitwise right shift: >> (shifts bits to the right by a given number of positions)
   c = b >> 2; // 0010 (binary) = 2 (decimal)
   printf("b >> 2 = %d\n", c);

   return 0;
}