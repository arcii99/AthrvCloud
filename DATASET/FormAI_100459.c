//FormAI DATASET v1.0 Category: Bitwise operations ; Style: content
#include <stdio.h>

int main() {
   unsigned int a = 60;   // 0011 1100 
   unsigned int b = 13;   // 0000 1101 
   int result = 0;
   
   // Bitwise AND
   result = a & b;        // 0000 1100
   printf("result of a & b is %d\n", result );
 
   // Bitwise OR
   result = a | b;        // 0011 1101 
   printf("result of a | b is %d\n", result );
 
   // Bitwise XOR
   result = a ^ b;        // 0011 0001
   printf("result of a ^ b is %d\n", result );
   
   // Bitwise NOT
   result = ~a;           // 1100 0011
   printf("result of ~a is %d\n", result );
   
   // Bitwise left shift
   result = a << 2;       // 1111 0000
   printf("result of a << 2 is %d\n", result );
   
   // Bitwise right shift
   result = a >> 2;       // 0000 1111
   printf("result of a >> 2 is %d\n", result );
   
   return 0;
}