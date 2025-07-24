//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {
   int a = 5;
   int b= 7;
   int c;

   c = a & b;       // bitwise AND operation
   printf("a & b = %d\n", c );

   c = a | b;       // bitwise OR operation
   printf("a | b = %d\n", c );

   c = a ^ b;       // bitwise XOR operation
   printf("a ^ b = %d\n", c );

   c = ~a;          // bitwise NOT operation
   printf("~a = %d\n", c );

   c = a << 1;      // left shift operation
   printf("a << 1 = %d\n", c );

   c = a >> 1;      // right shift operation
   printf("a >> 1 = %d\n", c );

   return 0;
}