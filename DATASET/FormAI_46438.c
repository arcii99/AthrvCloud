//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

int main() {
   int a = 60; // 0011 1100
   int b = 13; // 0000 1101
   int result; 
   
   // bitwise AND
   result = a & b;
   printf("a & b = %d\n", result ); // 0000 1100
   
   // bitwise OR
   result = a | b;
   printf("a | b = %d\n", result ); // 0011 1101
   
   // bitwise XOR
   result = a ^ b;
   printf("a ^ b = %d\n", result ); // 0011 0001
   
   // bitwise complement
   result = ~a;
   printf("~a = %d\n", result ); // 1100 0011
      
   // left shift
   result = a << 2;
   printf("a << 2 = %d\n", result ); // 1111 0000
   
   // right shift
   result = a >> 2;
   printf("a >> 2 = %d\n", result ); // 0000 1111

   return 0;
}