//FormAI DATASET v1.0 Category: Bitwise operations ; Style: optimized
#include <stdio.h>

int main() {
   unsigned int num = 57; // Binary equivalent is 0011 1001
   unsigned int mask = 28; // Binary equivalent is 0001 1100

   // Applying bitwise AND to the given number and mask
   unsigned int result = num & mask; // Binary equivalent is 0001 1000
   
   // Printing the result in decimal and binary notation
   printf("Result using bitwise AND: %d\n", result);
   printf("Result in binary notation: %08x\n", result);
   
   // Applying bitwise OR to the given number and mask
   result = num | mask; // Binary equivalent is 0011 1101
   
   printf("Result using bitwise OR: %d\n", result);
   printf("Result in binary notation: %08x\n", result);
   
   // Applying bitwise XOR to the given number and mask
   result = num ^ mask; // Binary equivalent is 0010 0101
   
   printf("Result using bitwise XOR: %d\n", result);
   printf("Result in binary notation: %08x\n", result);
   
   // Applying bitwise NOT to the given number
   result = ~num; // Binary equivalent is 1100 0110
   
   printf("Result using bitwise NOT: %d\n", result);
   printf("Result in binary notation: %08x\n", result);
   
   // Applying left shift operation to the given number
   result = num << 2; // Binary equivalent is 1110 0100
   
   printf("Result using left shift: %d\n", result);
   printf("Result in binary notation: %08x\n", result);
   
   // Applying right shift operation to the given number
   result = num >> 2; // Binary equivalent is 0000 1110
   
   printf("Result using right shift: %d\n", result);
   printf("Result in binary notation: %08x\n", result);

   return 0;
}