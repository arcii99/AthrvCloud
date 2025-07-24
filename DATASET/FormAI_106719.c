//FormAI DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include <stdio.h>

int main() {
   unsigned int num1 = 60; // 0011 1100
   unsigned int num2 = 13; // 0000 1101
   int result1, result2, result3, result4, result5;

   printf("\nThe First Number is %d\n", num1);
   printf("The Second Number is %d\n", num2);

   // Bitwise AND ( & )
   printf("\nBitwise AND Operator:\n");
   result1 = num1 & num2;
   printf("%d & %d = %d\n", num1, num2, result1);

   // Bitwise OR ( | )
   printf("\nBitwise OR Operator:\n");
   result2 = num1 | num2;
   printf("%d | %d = %d\n", num1, num2, result2);

   // Bitwise XOR ( ^ )
   printf("\nBitwise XOR Operator:\n");
   result3 = num1 ^ num2;
   printf("%d ^ %d = %d\n", num1, num2, result3);

   // Bitwise Complement ( ~ )
   printf("\nBitwise Complement Operator:\n");
   result4 = ~num1;
   printf("~%d = %d\n", num1, result4);

   // Left shift ( << )
   printf("\nLeft Shift Operator:\n");
   result5 = num1 << 2;
   printf("%d << 2 = %d\n", num1, result5);

   return 0;
}