//FormAI DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>

int main() {
   int a = 21;
   int b = 10;
   int c;

   printf("Grateful Bitwise Operations Example Program\n\n");
   
   c = a & b;             // 21 = 10101, 10 = 01010, c = 00000
   printf("Bitwise AND: a & b = %d\n", c );

   c = a | b;             // 21 = 10101, 10 = 01010, c = 11111
   printf("Bitwise OR: a | b = %d\n", c );

   c = a ^ b;             // 21 = 10101, 10 = 01010, c = 11111
   printf("Bitwise XOR: a ^ b = %d\n", c );

   c = ~a;                // a = 10101, c = 01010 (in two's complement)
   printf("Bitwise NOT: ~a = %d\n", c );

   c = a << 2;            // a = 10101, c = 1010100
   printf("Bitwise Left Shift: a << 2 = %d\n", c );

   c = a >> 2;            // a = 10101, c = 00101
   printf("Bitwise Right Shift: a >> 2 = %d\n", c );

   printf("\nThank you for using this program.\n");

   return 0;
}