//FormAI DATASET v1.0 Category: Bitwise operations ; Style: portable
#include <stdio.h>

int main() {
   int a = 10, b = 4, c = 0;

   c = a & b;     
   printf("Line 1 - Value of c is %d\n", c );

   c = a | b;     
   printf("Line 2 - Value of c is %d\n", c );

   c = a ^ b;     
   printf("Line 3 - Value of c is %d\n", c );

   c = ~a;        
   printf("Line 4 - Value of c is %d\n", c );

   c = a << 2;    
   printf("Line 5 - Value of c is %d\n", c );

   c = a >> 2;    
   printf("Line 6 - Value of c is %d\n", c );

   return 0;
}