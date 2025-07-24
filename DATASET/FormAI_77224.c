//FormAI DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>

int main() {
   int num1 = 10, num2 = 20;
   printf("Number 1 is: %d and Number 2 is: %d\n", num1, num2);

   // Bitwise AND operator
   int result = num1 & num2;
   printf("Result of AND operation: %d\n", result);

   // Bitwise OR operator
   result = num1 | num2;
   printf("Result of OR operation: %d\n", result);

   // Bitwise XOR operator
   result = num1 ^ num2;
   printf("Result of XOR operation: %d\n", result);

   // Bitwise NOT operator
   result = ~num1;
   printf("Result of NOT operation on num1: %d\n", result);

   // Bitwise Left Shift operator
   result = num1 << 2;
   printf("Result of Left Shift operation on num1: %d\n", result);

   // Bitwise Right Shift operator
   result = num2 >> 2;
   printf("Result of Right Shift operation on num2: %d\n", result);

   // Bitwise AND assignment operator
   num1 &= num2;
   printf("After AND assignment, num1 is: %d\n", num1);

   // Bitwise OR assignment operator
   num1 |= num2;
   printf("After OR assignment, num1 is: %d\n", num1);

   // Bitwise XOR assignment operator
   num1 ^= num2;
   printf("After XOR assignment, num1 is: %d\n", num1);

   return 0;
}