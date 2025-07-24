//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

int main() {
   int a = 8;
   int b = 3;
   int result;

   result = a & b;
   printf("a & b = %d\n", result);

   result = a | b;
   printf("a | b = %d\n", result);

   result = a ^ b;
   printf("a ^ b = %d\n", result);

   result = ~a;
   printf("~a = %d\n", result);

   result = a << 2;
   printf("a << 2 = %d\n", result);

   result = a >> 2;
   printf("a >> 2 = %d\n", result);

   return 0;
}