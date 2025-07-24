//FormAI DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>

int main() {
  unsigned int num1 = 60;   /* 60 = 0011 1100 */  
  unsigned int num2 = 13;   /* 13 = 0000 1101 */ 
  int result = 0;

  /* Bitwise AND */
  result = num1 & num2;     /* 12 = 0000 1100 */
  printf("Bitwise AND: %d & %d = %d\n", num1, num2, result );
 
  /* Bitwise OR */
  result = num1 | num2;     /* 61 = 0011 1101 */
  printf("Bitwise OR: %d | %d = %d\n", num1, num2, result );
 
  /* Bitwise XOR */
  result = num1 ^ num2;     /* 49 = 0011 0001 */
  printf("Bitwise XOR: %d ^ %d = %d\n", num1, num2, result );
 
  /* Bitwise complement */
  result = ~num1;           /* -61 = 1100 0011 */
  printf("Bitwise complement: ~%d = %d\n", num1, result );
  
  /* Bitwise left shift */
  result = num1 << 2;       /* 240 = 1111 0000 */
  printf("Bitwise left shift: %d << 2 = %d\n", num1, result );
  
  /* Bitwise right shift */
  result = num1 >> 2;       /* 15 = 0000 1111 */
  printf("Bitwise right shift: %d >> 2 = %d\n", num1, result );

  return 0;
}