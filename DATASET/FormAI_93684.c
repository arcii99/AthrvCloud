//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

int main() {
   int a = 5; 
   int b = 9; 
   int c;

   printf("The value of a is %d and the value of b is %d before bitwise operations.\n", a, b);

   c = a & b;
   printf("The result of AND bitwise operation between a and b is %d.\n", c);

   c = a | b;
   printf("The result of OR bitwise operation between a and b is %d.\n", c);

   c = a ^ b;
   printf("The result of XOR bitwise operation between a and b is %d.\n", c);

   c = ~a;
   printf("The result of NOT bitwise operation on a is %d.\n", c);

   c = a << 2;
   printf("The result of left shift by 2 bits on a is %d.\n", c);

   c = b >> 2;
   printf("The result of right shift by 2 bits on b is %d.\n", c);

   return 0;
}