//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include <stdio.h>

int main() {
   unsigned int a = 60; // 0011 1100
   unsigned int b = 13; // 0000 1101
   unsigned int c;

   printf("\n\n~ Bitwise NOT operator (~):\n");
   printf("====================================\n");
   c = ~a; // 1100 0011
   printf("The complement of a = %d is %d\n", a, c);

   printf("\n\n& Bitwise AND operator (&):\n");
   printf("====================================\n");
   c = a & b; // 0000 1100
   printf("%d & %d = %d\n", a, b, c);

   printf("\n\n| Bitwise OR operator (|):\n");
   printf("====================================\n");
   c = a | b; // 0011 1101
   printf("%d | %d = %d\n", a, b, c);

   printf("\n\n^ Bitwise XOR operator (^):\n");
   printf("====================================\n");
   c = a ^ b; // 0011 0001
   printf("%d ^ %d = %d\n", a, b, c);

   printf("\n\n<< Bitwise left shift operator (<<):\n");
   printf("====================================\n");
   c = a << 2; // 1111 0000
   printf("%d << 2 = %d\n", a, c);
   
   printf("\n\n>> Bitwise right shift operator (>>):\n");
   printf("====================================\n");
   c = a >> 2; // 0000 1111
   printf("%d >> 2 = %d\n", a, c);

   return 0;
}