//FormAI DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>

int main() {
   int a = 7, b = 15;

   // Bitwise AND operation to find the common bits
   int result_and = a & b; 
   printf("Bitwise AND of %d and %d is %d\n", a, b, result_and);

   // Bitwise OR operation to find the union of bits
   int result_or = a | b;
   printf("Bitwise OR of %d and %d is %d\n", a, b, result_or);

   // Bitwise XOR operation to find the non-common bits
   int result_xor = a ^ b;
   printf("Bitwise XOR of %d and %d is %d\n", a, b, result_xor);

   // Bitwise NOT operation to find the 1's complement of a
   int result_not = ~a;
   printf("Bitwise NOT of %d is %d\n", a, result_not);

   // Bitwise Left Shift operation to double the value of a
   int result_left_shift = a << 1;
   printf("Bitwise Left Shift of %d is %d\n", a, result_left_shift);

   // Bitwise Right Shift operation to get half value of b
   int result_right_shift = b >> 1;
   printf("Bitwise Right Shift of %d is %d\n", b, result_right_shift);

   return 0;
}