//FormAI DATASET v1.0 Category: Bitwise operations ; Style: puzzling
#include <stdio.h>

int main() {
   int num1 = 21; // Binary: 10101
   int num2 = 17; // Binary: 10001
   int num3 = 0;
   int num4 = 0;
   
   // Bitwise OR Operation
   num3 = num1 | num2; // Binary: 10101 | 10001 = 10101
   printf("Bitwise OR between %d and %d = %d\n", num1, num2, num3);
   
   // Bitwise XOR Operation
   num3 = num1 ^ num2; // Binary: 10101 ^ 10001 = 00100
   printf("Bitwise XOR between %d and %d = %d\n", num1, num2, num3);
   
   // Bitwise AND Operation
   num3 = num1 & num2; // Binary: 10101 & 10001 = 10001
   printf("Bitwise AND between %d and %d = %d\n", num1, num2, num3);
   
   // Bitwise NOT Operation (Unary)
   num4 = ~num1; // Binary: ~10101 = 01010
   printf("Bitwise NOT of %d = %d\n", num1, num4);
   
   // Bitwise Left Shift Operation
   num3 = num1 << 2; // Binary: 10101 << 2 = 1010100
   printf("Bitwise Left Shift %d by 2 = %d\n", num1, num3);
   
   // Bitwise Right Shift Operation
   num3 = num1 >> 2; // Binary: 10101 >> 2 = 101
   printf("Bitwise Right Shift %d by 2 = %d\n", num1, num3);
   
   return 0;
}