//FormAI DATASET v1.0 Category: Bitwise operations ; Style: invasive
#include <stdio.h>

int main() {
   int a = 5;
   int b = 9;
   int c;

   // Bitwise AND
   c = a & b;
   printf("Bitwise AND: %d\n", c);

   // Bitwise OR
   c = a | b;
   printf("Bitwise OR: %d\n", c);

   // Bitwise XOR
   c = a ^ b;
   printf("Bitwise XOR: %d\n", c);

   // Bitwise NOT
   c = ~a;
   printf("Bitwise NOT: %d\n", c);

   // Left shift
   c = a << 2;
   printf("Left shift: %d\n", c);

   // Right shift
   c = b >> 2;
   printf("Right shift: %d\n", c);

   return 0;
}