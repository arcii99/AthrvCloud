//FormAI DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>

int main() {
   int a = 10;
   int b = 20; 
   int c = 0;

   printf("Before bitwise operations, a = %d, b = %d\n", a, b);

   // Bitwise AND operator
   c = a & b;
   printf("a & b = %d\n", c );

   // Bitwise OR operator
   c = a | b;
   printf("a | b = %d\n", c );

   // Bitwise XOR operator
   c = a ^ b;
   printf("a ^ b = %d\n", c );

   // Bitwise NOT operator
   c = ~a;
   printf("~a = %d\n", c );

   // Bitwise Left Shift operator
   c = a << 2;
   printf("a << 2 = %d\n", c );

   // Bitwise Right Shift operator
   c = b >> 2;
   printf("b >> 2 = %d\n", c );

   return 0;
}