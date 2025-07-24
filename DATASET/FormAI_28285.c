//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

int main() {
   int num1 = 10, num2 = 15;
   
   printf("Before bitwise operations: num1 = %d, num2 = %d\n", num1, num2);

   // Bitwise OR operator
   int result_or = num1 | num2;
   printf("Result of Bitwise OR operator: %d\n", result_or);
   
   // Bitwise AND operator
   int result_and = num1 & num2;
   printf("Result of Bitwise AND operator: %d\n", result_and);

   // Bitwise XOR operator
   int result_xor = num1 ^ num2;
   printf("Result of Bitwise XOR operator: %d\n", result_xor);

   // Bitwise NOT operator
   int result_not = ~num1;
   printf("Result of Bitwise NOT operator: %d\n", result_not);

   // Bitwise shift left operator
   int result_shift_left = num1 << 2;
   printf("Result of Bitwise shift left operator: %d\n", result_shift_left);

   // Bitwise shift right operator
   int result_shift_right = num1 >> 2;
   printf("Result of Bitwise shift right operator: %d\n", result_shift_right);

   printf("After bitwise operations: num1 = %d, num2 = %d", num1, num2);

   return 0;
}