//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

int main() {
   int a = 10, b = 20;
   printf("Let's perform some bitwise operations!\n");
   printf("a = 10  and b = 20\n");

   // Example of bitwise AND operator
   int c = a & b;
   printf("Result of a & b = %d\n", c);

   // Example of bitwise OR operator
   c = a | b;
   printf("Result of a | b = %d\n", c);

   // Example of bitwise XOR operator
   c = a ^ b;
   printf("Result of a ^ b = %d\n", c);

   // Example of bitwise NOT operator
   c = ~a;
   printf("Result of ~a = %d\n", c);

   // Example of left shift operator
   c = a << 2;
   printf("Result of a << 2 = %d\n", c);

   // Example of right shift operator
   c = b >> 2;
   printf("Result of b >> 2 = %d\n", c);

   printf("Yay! We did some math with bitwise operations!\n");
   return 0;
}