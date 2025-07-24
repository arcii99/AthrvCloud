//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include <stdio.h>

int main() {
   unsigned int a = 60; /* 60 = 0011 1100 */
   unsigned int b = 13; /* 13 = 0000 1101 */
   int result = 0;
   
   printf("I'm about to perform some exciting bitwise operations!\n\n");

   /* Bitwise AND */
   printf("Now let's perform a Bitwise AND...\n");
   result = a & b; /* 12 = 0000 1100 */
   printf("When we Bitwise AND %d and %d, the result is %d!\n\n", a, b, result );

   /* Bitwise OR */
   printf("Next up, let's do a Bitwise OR...\n");
   result = a | b; /* 61 = 0011 1101 */
   printf("When we Bitwise OR %d and %d, the result is %d!\n\n", a, b, result );

   /* Bitwise XOR */
   printf("Now it's time for a Bitwise XOR...\n");
   result = a ^ b; /* 49 = 0011 0001 */
   printf("When we Bitwise XOR %d and %d, the result is %d!\n\n", a, b, result );

   /* Bitwise NOT */
   printf("Now let's try the Bitwise NOT operator...\n");
   result = ~a; /* -61 = 1100 0011 */
   printf("When we apply the Bitwise NOT to %d, the result is %d!\n\n", a, result );

 	 /* Left Shift */
   printf("Hold on to your hats - it's time for a Left Shift!\n");
   result = a << 2; /* 240 = 1111 0000 */
   printf("When we shift %d left by 2 bits, the result is %d!\n\n", a, result );

   /* Right Shift */
   printf("And finally, we'll wrap things up with a Right Shift...\n");
   result = a >> 2; /* 15 = 0000 1111 */
   printf("When we shift %d right by 2 bits, the result is %d!\n\n", a, result );

   printf("Now that was some exciting bitwise operation action!\n");

   return 0;
}