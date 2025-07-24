//FormAI DATASET v1.0 Category: Bitwise operations ; Style: lively
#include <stdio.h>

int main(void) {
  unsigned int a = 60;        /* 60 = 0011 1100 */  
  unsigned int b = 13;        /* 13 = 0000 1101 */
  int c = 0;

  /* Bitwise AND */
  c = a & b;                 /* 12 = 0000 1100 */ 
  printf("Output of bitwise AND: %d\n", c ); // Output: 12

  /* Bitwise OR */
  c = a | b;                 /* 61 = 0011 1101 */
  printf("Output of Bitwise OR: %d\n", c ); // Output: 61

  /* Bitwise XOR */
  c = a ^ b;                 /* 49 = 0011 0001 */
  printf("Output of Bitwise XOR: %d\n", c ); // Output: 49

  /* Bitwise Ones Complement */
  c = ~a;                    /* -61 = 1100 0011 */
  printf("Output of Bitwise Ones Complement: %d\n", c ); // Output: -61

  /* Left Shift Operator */
  c = a << 2;                /* 240 = 1111 0000 */
  printf("Output of Left Shift Operator: %d\n", c ); // Output: 240

  /* Right Shift Operator */
  c = a >> 2;                /* 15 = 0000 1111 */
  printf("Output of Right Shift Operator: %d\n", c ); // Output: 15

  return 0;
}