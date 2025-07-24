//FormAI DATASET v1.0 Category: Bitwise operations ; Style: interoperable
#include <stdio.h>

int main() {
   unsigned int a = 60;        //60 = 0011 1100 in binary
   unsigned int b = 13;        //13 = 0000 1101 in binary
   
   // Bitwise AND, sets each bit to 1 if both bits are 1
   unsigned int c = a & b;     //12 = 0000 1100 in binary
   printf("a & b = %u\n", c);

   // Bitwise OR, sets each bit to 1 if any of both bits are 1
   unsigned int d = a | b;     //61 = 0011 1101 in binary
   printf("a | b = %u\n", d);

   // Bitwise XOR, sets each bit to 1 if only one bit is 1
   unsigned int e = a ^ b;     //49 = 0011 0001 in binary
   printf("a ^ b = %u\n", e);

   // Bitwise NOT, inverts all the bits
   unsigned int f = ~a;        //4294967235 = 1111 1111 1111 1111 1111 1111 1100 0011 in binary
   printf("~a = %u\n", f);

   // Left shift, shifts left by the specified number of bits
   unsigned int g = a << 2;    //240 = 1111 0000 in binary
   printf("a << 2 = %u\n", g);

   // Right shift, shifts right by the specified number of bits
   unsigned int h = a >> 2;    //15 = 0000 1111 in binary
   printf("a >> 2 = %u\n", h);

   return 0;
}