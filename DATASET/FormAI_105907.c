//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
   int a = 5;
   int b = 9;
   int c;

   // Perform bitwise AND
   c = a & b;
   printf("a & b = %d\n", c);    // Output: 1

   // Perform bitwise OR
   c = a | b;
   printf("a | b = %d\n", c);    // Output: 13

   // Perform bitwise XOR
   c = a ^ b;
   printf("a ^ b = %d\n", c);    // Output: 12

   // Perform bitwise complement
   c = ~a;
   printf("~a = %d\n", c);       // Output: -6

   // Perform left shift
   c = a << 1;
   printf("a << 1 = %d\n", c);   // Output: 10

   // Perform right shift
   c = b >> 2;
   printf("b >> 2 = %d\n", c);   // Output: 2

   return 0;
}