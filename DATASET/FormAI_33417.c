//FormAI DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include <stdio.h>

int main() {
   unsigned int num1 = 10; // 0xA in hex
   unsigned int num2 = 7;  // 0x7 in hex
   
   // Bitwise AND '&'
   printf("Bitwise AND result of %d and %d: %d\n", num1, num2, num1 & num2);
   
   // Bitwise OR '|'
   printf("Bitwise OR result of %d and %d: %d\n", num1, num2, num1 | num2);
   
   // Bitwise XOR '^'
   printf("Bitwise XOR result of %d and %d: %d\n", num1, num2, num1 ^ num2);
   
   // Bitwise NOT '~'
   printf("Bitwise NOT result of %d: %d\n", num1, ~num1);
   
   // Left Shift '<<'
   printf("Left shift result of %d by 2: %d\n", num1, num1 << 2);
   
   // Right Shift '>>'
   printf("Right shift result of %d by 2: %d\n", num1, num1 >> 2);
   
   // Bitwise AND with mask
   unsigned int mask = 0xF; // 0xF has all 4 bits set to 1
   printf("Bitwise AND result of %d and mask %d: %d\n", num1, mask, num1 & mask);
   
   // Check if 7th bit is set or not
   unsigned int num3 = 128; // 0x80 in hex, 7th bit is set
   unsigned int bitStatus = num3 & (1 << 6); // shift 1 by 6 (7th position) and bitwise AND with num3
   if (bitStatus)
      printf("7th bit of %d is set\n", num3);
   else
      printf("7th bit of %d is not set\n", num3);
      
   return 0;
}