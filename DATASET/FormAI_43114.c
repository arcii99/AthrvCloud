//FormAI DATASET v1.0 Category: Bitwise operations ; Style: active
#include <stdio.h>

int main() {
   unsigned int a = 60;    /* 60 = 0011 1100 */
   unsigned int b = 13;    /* 13 = 0000 1101 */
   int result = 0;

   /* Example 1: Bitwise AND operator */
   result = a & b;          /* 12 = 0000 1100 */
   printf("Bitwise AND operation result: %d\n", result );

   /* Example 2: Bitwise OR operator */
   result = a | b;          /* 61 = 0011 1101 */
   printf("Bitwise OR operation result: %d\n", result );

   /* Example 3: Bitwise XOR operator */
   result = a ^ b;          /* 49 = 0011 0001 */
   printf("Bitwise XOR operation result: %d\n", result );

   /* Example 4: Bitwise complement operator */
   result = ~a;             /* -61 = 1100 0011 */
   printf("Bitwise complement operation result: %d\n", result );

   /* Example 5: Left shift operator */
   result = a << 2;         /* 240 = 1111 0000 */
   printf("Left shift operation result: %d\n", result );

   /* Example 6: Right shift operator */
   result = a >> 2;         /* 15 = 0000 1111 */
   printf("Right shift operation result: %d\n", result );

   return 0;
}