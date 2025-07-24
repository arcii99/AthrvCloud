//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

int main(){
   int a = 20; // 10100 in binary
   int b = 27; // 11011 in binary
   int result;

   // & bitwise AND operator example
   result = a & b; // returns 10000 in binary (16 in decimal)
   printf("a & b = %d\n", result);

   // | bitwise OR operator example
   result = a | b; // returns 11111 in binary (31 in decimal)
   printf("a | b = %d\n", result);

   // ^ bitwise XOR operator example
   result = a ^ b; // returns 01111 in binary (15 in decimal)
   printf("a ^ b = %d\n", result);

   // ~ bitwise NOT operator example
   result = ~a; // returns 01011 in binary (-21 in decimal)
   printf("~a = %d\n", result);

   // << bitwise left shift operator example
   result = a << 3; // returns 10100000 in binary (160 in decimal)
   printf("a << 3 = %d\n", result);

   // >> bitwise right shift operator example
   result = b >> 2; // returns 001101 in binary (6 in decimal)
   printf("b >> 2 = %d\n", result);

   return 0;
}