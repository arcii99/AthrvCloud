//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

int main() {
   unsigned int num1 = 23;     /* 23 = 00010111 in binary */
   unsigned int num2 = 11;     /* 11 = 00001011 in binary */
   unsigned int result;

   /* Bitwise AND */
   result = num1 & num2;       /* 00000011 = 3 */
   printf("num1 & num2 = %u\n", result);

   /* Bitwise OR */
   result = num1 | num2;       /* 00011111 = 31 */
   printf("num1 | num2 = %u\n", result);

   /* Bitwise XOR */
   result = num1 ^ num2;       /* 00011100 = 28 */
   printf("num1 ^ num2 = %u\n", result);

   /* Bitwise NOT */
   result = ~num1;             /* 11101000 = 4294967272 */
   printf("~num1 = %u\n", result);

   /* Left shift */
   result = num1 << 1;         /* 00101110 = 46 */
   printf("num1 << 1 = %u\n", result);

   /* Right shift */
   result = num1 >> 1;         /* 00001011 = 11 */
   printf("num1 >> 1 = %u\n", result);

   return 0;
}