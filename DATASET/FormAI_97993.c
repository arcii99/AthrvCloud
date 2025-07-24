//FormAI DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>

int main() {
   unsigned int a = 0b10101010; // binary representation of 170
   unsigned int b = 0b01010101; // binary representation of 85

   printf("a = %d (in decimal)\n", a);
   printf("b = %d (in decimal)\n\n", b);

   /* Bitwise AND */ 
   printf("a & b = %d (in decimal)\n", a & b);
   /* Binary representation of a & b is 00000000 */
   /* It performs AND operation of corresponding bits, 
      and returns 1 only if both bits are 1 */
   
   /* Bitwise OR */ 
   printf("a | b = %d (in decimal)\n", a | b);
   /* Binary representation of a | b is 11111111 */
   /* It performs OR operation of corresponding bits, 
      and returns 1 if either of the bits is 1 */
   
   /* Bitwise XOR */ 
   printf("a ^ b = %d (in decimal)\n", a ^ b);
   /* Binary representation of a ^ b is 11111111 */
   /* It performs XOR operation of corresponding bits, 
      and returns 1 if the bits are different */
   
   /* Bitwise NOT */ 
   printf("~a = %d (in decimal)\n", ~a);
   /* Binary representation of ~a is 01010101 */
   /* It performs NOT operation of corresponding bits, 
      and returns the one's complement of the bits */
   
   /* Left shift */ 
   printf("a << 2 = %d (in decimal)\n", a << 2);
   /* Binary representation of a << 2 is 1010101000 */
   /* It shifts each bit to the left by specified number of positions, 
      and adds zeroes at the places where bits are lost */
   
   /* Right shift */ 
   printf("a >> 2 = %d (in decimal)\n", a >> 2);
   /* Binary representation of a >> 2 is 00101010 */
   /* It shifts each bit to the right by specified number of positions, 
      and adds zeroes at the places where bits are lost */
   
   return 0;
}