//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
   unsigned int a = 60;   // Binary equivalent of 60 is 0011 1100
   unsigned int b = 13;   // Binary equivalent of 13 is 0000 1101
   int result = 0;

   // Bitwise AND Operator &
   result = a & b;       //  Result: 0000 1100 (12)
   printf("a & b = %d\n", result );

   // Bitwise OR Operator |
   result = a | b;       //  Result: 0011 1101 (61)
   printf("a | b = %d\n", result );

   // Bitwise XOR Operator ^
   result = a ^ b;       //  Result: 0011 0001 (49)
   printf("a ^ b = %d\n", result );

   // Bitwise NOT Operator ~
   result = ~a;          //  Result: 1100 0011 (-61)
   printf("~a = %d\n", result );

   // Bitwise Left Shift Operator <<
   result = a << 2;      //  Result: 1111 0000 (240)
   printf("a << 2 = %d\n", result );

   // Bitwise Right Shift Operator >>
   result = a >> 2;      //  Result: 0000 1111 (15)
   printf("a >> 2  = %d\n", result );

   return 0;
}