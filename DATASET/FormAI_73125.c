//FormAI DATASET v1.0 Category: Bitwise operations ; Style: visionary
#include <stdio.h>

int main() {
   int a = 99, b = 23;
   unsigned int c = 0;

   c = a | b; /* bitwise OR operation */
   printf("a | b = %d\n", c);

   c = a & b; /* bitwise AND operation */
   printf("a & b = %d\n", c);

   c = a ^ b; /* bitwise XOR operation */
   printf("a ^ b = %d\n", c);

   c = ~a; /* bitwise NOT operation */
   printf("~a = %d\n", c);

   c = a << 2; /* bitwise left shift operation */
   printf("a << 2 = %d\n", c);

   c = b >> 1; /* bitwise right shift operation */
   printf("b >> 1 = %d\n", c);

   return 0;
}