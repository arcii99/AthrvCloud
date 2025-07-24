//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

int main() {
   unsigned int a = 60;    // 60 = 0011 1100
   unsigned int b = 13;    // 13 = 0000 1101
   int c = 0;
   
   printf("a = %d\n", a);
   printf("b = %d\n", b);
   
   // Bitwise AND (&)
   c = a & b;       // 0000 1100
   printf("a & b = %d\n", c);

   // Bitwise OR (|)
   c = a | b;       // 0011 1101
   printf("a | b = %d\n", c);

   // Bitwise XOR (^)
   c = a ^ b;       // 0011 0001
   printf("a ^ b = %d\n", c);

   // Bitwise NOT (~)
   c = ~a;          // 1100 0011
   printf("~a = %d\n", c);

   // Left Shift (<<)
   c = a << 2;      // 1111 0000
   printf("a << 2 = %d\n", c);

   // Right Shift (>>)
   c = a >> 2;      // 0000 1111
   printf("a >> 2 = %d\n", c);

   return 0;
}