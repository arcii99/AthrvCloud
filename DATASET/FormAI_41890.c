//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() {
   int num1 = 27;
   int num2 = 14;
   int result;

   // Bitwise AND
   result = num1 & num2;
   printf("Bitwise AND: %d & %d = %d\n", num1, num2, result);

   // Bitwise OR
   result = num1 | num2;
   printf("Bitwise OR: %d | %d = %d\n", num1, num2, result);

   // Bitwise XOR
   result = num1 ^ num2;
   printf("Bitwise XOR: %d ^ %d = %d\n", num1, num2, result);

   // Bitwise NOT
   result = ~num1;
   printf("Bitwise NOT: ~%d = %d\n", num1, result);

   // Bitwise LEFT SHIFT
   result = num1 << 2;
   printf("Bitwise LEFT SHIFT: %d << 2 = %d\n", num1, result);

   // Bitwise RIGHT SHIFT
   result = num1 >> 2;
   printf("Bitwise RIGHT SHIFT: %d >> 2 = %d\n", num1, result);

   // Bitwise Assignment Operators
   result &= num2;
   printf("Bitwise AND Assignment: %d &= %d = %d\n", result, num2, result);
   result |= num2;
   printf("Bitwise OR Assignment: %d |= %d = %d\n", result, num2, result);
   result ^= num2;
   printf("Bitwise XOR Assignment: %d ^= %d = %d\n", result, num2, result);
   result <<= 2;
   printf("Bitwise LEFT SHIFT Assignment: %d <<= 2 = %d\n", result, result);
   result >>= 2;
   printf("Bitwise RIGHT SHIFT Assignment: %d >>= 2 = %d\n", result, result);

   return 0;
}