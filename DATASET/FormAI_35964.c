//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>

int main() {
   int a = 12; // 00001100 in binary
   int b = 25; // 00011001 in binary
   int c;

   c = a & b;       /* 00001000 (8) */
   printf("Line 1 - Value of c is %d\n", c );

   c = a | b;       /* 00011101 (29) */
   printf("Line 2 - Value of c is %d\n", c );

   c = a ^ b;       /* 00010101 (21) */
   printf("Line 3 - Value of c is %d\n", c );

   c = ~a;          /* 11110011 (-13) */
   printf("Line 4 - Value of c is %d\n", c );

   c = a << 2;     /* 00110000 (48) */
   printf("Line 5 - Value of c is %d\n", c );

   c = a >> 2;     /* 00000011 (3) */
   printf("Line 6 - Value of c is %d\n", c );

   return 0;
}