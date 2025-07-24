//FormAI DATASET v1.0 Category: Bitwise operations ; Style: artistic
#include <stdio.h>

int main() {
   int a = 62; // 111110 in binary
   int b = 47; // 101111 in binary

   // Bitwise AND
   printf("a & b = %d\n", a & b); // Result is 42, 101010 in binary
   
   // Bitwise OR
   printf("a | b = %d\n", a | b); // Result is 63, 111111 in binary
   
   // Bitwise XOR
   printf("a ^ b = %d\n", a ^ b); // Result is 21, 010101 in binary
   
   // Bitwise NOT
   printf("~a = %d\n", ~a); // Result is -63, 11111111111111111111111111000001 in binary
   
   // Bitwise left shift
   printf("a << 1 = %d\n", a << 1); // Result is 124, 1111100 in binary
   
   // Bitwise right shift
   printf("a >> 1 = %d\n", a >> 1); // Result is 31, 1111 in binary
   
   return 0;
}