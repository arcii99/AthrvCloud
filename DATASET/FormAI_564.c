//FormAI DATASET v1.0 Category: Bitwise operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
   int num1 = 25;
   int num2 = 12;
   int num3 = 0;
   
   printf("The numbers are: num1 = %d, num2 = %d\n", num1, num2);

   // Bitwise AND
   num3 = num1 & num2;
   printf("num1 & num2 = %d\n", num3);

   // Bitwise OR
   num3 = num1 | num2;
   printf("num1 | num2 = %d\n", num3);

   // Bitwise XOR
   num3 = num1 ^ num2;
   printf("num1 ^ num2 = %d\n", num3);
   
   // Bitwise NOT
   num3 = ~num1;
   printf("~num1 = %d\n", num3);
   
   // Bitwise LEFT SHIFT
   num3 = num1 << 2;
   printf("num1 << 2 = %d\n", num3);

   // Bitwise RIGHT SHIFT
   num3 = num1 >> 2;
   printf("num1 >> 2 = %d\n", num3);

   // Bitwise AND assignment
   num1 &= num2;
   printf("num1 &= num2; num1 = %d\n", num1);

   // Bitwise OR assignment
   num1 |= num2;
   printf("num1 |= num2; num1 = %d\n", num1);

   // Bitwise XOR assignment
   num1 ^= num2;
   printf("num1 ^= num2; num1 = %d\n", num1);

   // Bitwise LEFT SHIFT assignment
   num1 <<= 2;
   printf("num1 <<= 2; num1 = %d\n", num1);

   // Bitwise RIGHT SHIFT assignment
   num1 >>= 2;
   printf("num1 >>= 2; num1 = %d\n", num1);

   return 0;
}