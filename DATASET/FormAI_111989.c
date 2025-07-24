//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>

int main() {
   int num1 = 60; /* 60 = 0011 1100 */
   int num2 = 13; /* 13 = 0000 1101 */
   int result = 0;

   // Bitwise AND operator
   result = num1 & num2; /* 12 = 0000 1100 */
   printf("Bitwise AND: %d\n", result );

   // Bitwise OR operator
   result = num1 | num2; /* 61 = 0011 1101 */
   printf("Bitwise OR: %d\n", result );

   // Bitwise XOR operator
   result = num1 ^ num2; /* 49 = 0011 0001 */
   printf("Bitwise XOR: %d\n", result );

   // Bitwise complement operator
   result = ~num1; /* -61 = 1100 0011 */
   printf("Bitwise Complement of num1: %d\n", result );

   // Left shift operator
   result = num1 << 2; /* 240 = 1111 0000 */
   printf("Left shift of num1 by 2 bits: %d\n", result );

   // Right shift operator
   result = num1 >> 2; /* 15 = 0000 1111 */
   printf("Right shift of num1 by 2 bits: %d\n", result );

   return 0;
}