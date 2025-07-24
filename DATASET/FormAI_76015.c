//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {

   int a = 42;
   int b = 15;
   int c;

   printf("a = %d, b = %d\n", a, b);

   c = a & b;
   printf("a & b = %d\n", c);

   c = a | b;
   printf("a | b = %d\n", c);

   c = a ^ b;
   printf("a ^ b = %d\n", c);

   c = ~a;
   printf("~a = %d\n", c);

   c = a << 2;
   printf("a << 2 = %d\n", c);

   c = a >> 2;
   printf("a >> 2 = %d\n", c);

   return 0;
}