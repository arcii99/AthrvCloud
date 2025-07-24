//FormAI DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>

int main() {

   unsigned int a = 60;    /* 60 = 0011 1100 */  
   unsigned int b = 13;    /* 13 = 0000 1101 */
   int result1 = 0;
   int result2 = 0;

   result1 = a & b;        /* 12 = 0000 1100 */
   result2 = a | b;        /* 61 = 0011 1101 */

   printf("a & b = %d\n", result1 );
   printf("a | b = %d\n", result2 );

   result1 = ~a;           /* -61 = 1100 0011 */
   result2 = a<<2;         /* 240 = 1111 0000 */
   printf("~a = %d\n", result1 );
   printf("a<<2 = %d\n", result2 );

   result1 = a>>2;         /* 15 = 0000 1111 */
   result2 = b>>2;         /* 3 = 0000 0011 */
   printf("a>>2 = %d\n", result1 );
   printf("b>>2 = %d\n", result2 );

   return 0;
}