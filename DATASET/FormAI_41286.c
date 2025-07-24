//FormAI DATASET v1.0 Category: Bitwise operations ; Style: lively
#include <stdio.h>

int main() {
   int a = 7;
   int b = 5;
   int c = a | b;
   printf("The bitwise OR of %d and %d is %d\n", a, b, c);

   c = a & b;
   printf("The bitwise AND of %d and %d is %d\n", a, b, c);

   c = a ^ b;
   printf("The bitwise XOR of %d and %d is %d\n", a, b, c);

   c = ~a;
   printf("The bitwise NOT of %d is %d\n", a, c);

   c = a << 2;
   printf("The left shift of %d by 2 is %d\n", a, c);

   c = b >> 1;
   printf("The right shift of %d by 1 is %d\n", b, c);

   return 0;
}