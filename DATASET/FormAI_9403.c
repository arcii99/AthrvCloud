//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

int main() {
   int a = 10, b = 15, c;
   
   // Example of bitwise AND operation
   c = a & b;     
   printf("a & b = %d\n", c);

   // Example of bitwise OR operation
   c = a | b;      
   printf("a | b = %d\n", c);

   // Example of bitwise NOT operation
   c = ~a;         
   printf("~a = %d\n", c);

   // Example of bitwise XOR operation
   c = a ^ b;      
   printf("a ^ b = %d\n", c);

   // Example of left shift operation
   c = a << 2;     
   printf("a << 2 = %d\n", c);

   // Example of right shift operation
   c = b >> 2;     
   printf("b >> 2 = %d\n", c);

   return 0;
}