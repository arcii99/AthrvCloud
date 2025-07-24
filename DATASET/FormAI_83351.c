//FormAI DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>

int main() {
   unsigned int a = 60;    // 0011 1100 
   unsigned int b = 13;    // 0000 1101
   int result = 0;
   
   // Bitwise AND Operation
   result = a & b;         // 0000 1100 -> 12
   printf("a & b = %d\n", result );
 
   // Bitwise OR Operation
   result = a | b;         // 0011 1101 -> 61
   printf("a | b = %d\n", result );
 
   // Bitwise XOR Operation
   result = a ^ b;         // 0011 0001 -> 49
   printf("a ^ b = %d\n", result );
 
   // Bitwise Complement Operator
   result = ~a;            // 1100 0011
   printf("~a = %d\n", result );
 
   // Bitwise Left Shift Operator
   result = a << 2;        // 1111 0000 -> 240
   printf("a << 2 = %d\n", result );
 
   // Bitwise Right Shift Operator
   result = a >> 2;        // 0000 1111 -> 15
   printf("a >> 2 = %d\n", result );
   
   return 0;
}