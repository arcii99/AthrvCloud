//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Alan Touring
#include <stdio.h>

int main() {
   unsigned int a = 60; //0011 1100
   unsigned int b = 13; //0000 1101
   int result;

   // Bitwise AND
   result = a & b;     // 0000 1100
   printf("a & b = %d\n", result );

   // Bitwise OR
   result = a | b;     // 0011 1101 
   printf("a | b = %d\n", result );

   // Bitwise XOR
   result = a ^ b;     // 0011 0001
   printf("a ^ b = %d\n", result );

   // Bitwise NOT
   result = ~a;        // 1100 0011
   printf("~a = %d\n", result );

   // Left shift
   result = a << 2;    // 1111 0000
   printf("a << 2 = %d\n", result );

   // Right shift
   result = a >> 2;    // 0000 1111
   printf("a >> 2 = %d\n", result );

   return 0;
}