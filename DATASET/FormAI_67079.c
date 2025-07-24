//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

int main() {
   int a = 60;    /* 60 = 0011 1100 */  
   int b = 13;    /* 13 = 0000 1101 */
   int c = 0;          

   c = a & b;       /* 12 = 0000 1100 */ 
   printf("The value of c after bitwise AND operation is: %d\n", c );

   c = a | b;       /* 61 = 0011 1101 */
   printf("The value of c after bitwise OR operation is: %d\n", c );

   c = a ^ b;       /* 49 = 0011 0001 */
   printf("The value of c after bitwise XOR operation is: %d\n", c );

   c = ~a;          /* -61 = 1100 0011 */
   printf("The value of c after bitwise NOT operation is: %d\n", c );

   c = a << 2;     /* 240 = 1111 0000 */
   printf("The value of c after left shift operation is: %d\n", c );

   c = a >> 2;     /* 15 = 0000 1111 */
   printf("The value of c after right shift operation is: %d\n", c );     
   
   return 0;
}