//FormAI DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>

int main() {
   int a = 10, b = 22;
   unsigned int c = 15, d = 20;
   printf("\nBitwise AND operator examples: ");
   printf("\na & b = %d", a & b); // Bitwise AND
   printf("\na & c = %d", a & c);
   printf("\nb & d = %d", b & d);
   printf("\n--------------------------------------\n");

   printf("\nBitwise OR operator examples: ");
   printf("\na | b = %d", a | b); // Bitwise OR
   printf("\na | c = %d", a | c);
   printf("\nb | c = %d", b | c);
   printf("\n--------------------------------------\n");

   printf("\nBitwise XOR operator examples: ");
   printf("\na ^ b = %d", a ^ b); // Bitwise XOR
   printf("\na ^ c = %d", a ^ c);
   printf("\nb ^ d = %d", b ^ d);
   printf("\n--------------------------------------\n");

   printf("\nBitwise NOT operator examples: ");
   printf("\n~a = %d", ~a); // Bitwise NOT
   printf("\n~c = %u", ~c); 
   printf("\n--------------------------------------\n");

   printf("\nBitwise left shift operator examples: ");
   printf("\na << 1 = %d", a << 1); // Bitwise left shift
   printf("\nb << 2 = %d", b << 2);
   printf("\nc << 3 = %u", c << 3);
   printf("\n--------------------------------------\n");

   printf("\nBitwise right shift operator examples: ");
   printf("\na >> 1 = %d", a >> 1); // Bitwise right shift
   printf("\nb >> 2 = %d", b >> 2);
   printf("\nd >> 3 = %u", d >> 3);
   printf("\n--------------------------------------\n");

   return 0;
}