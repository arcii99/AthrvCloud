//FormAI DATASET v1.0 Category: Bitwise operations ; Style: artistic
#include <stdio.h>

int main() {

   int a = 15;
   int b = 7;
   int c;

   // AND operation
   c = a & b;      
   printf("a & b = %d\n", c );

   // OR operation
   c = a | b;       
   printf("a | b = %d\n", c );

   // XOR operation
   c = a ^ b;       
   printf("a ^ b = %d\n", c );

   // Complement operation
   c = ~a;          
   printf("~a = %d\n", c );

   // Left Shift operation
   c = a << 2;      
   printf("a << 2 = %d\n", c );

   // Right Shift operation
   c = a >> 2;      
   printf("a >> 2 = %d\n", c );

   return 0;
}