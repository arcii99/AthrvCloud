//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>

int main() {

  unsigned int a = 60;   /* 60 = 0011 1100 */
  unsigned int b = 13;   /* 13 = 0000 1101 */
  int result = 0; 

  /* AND operation */
  result = a & b;       /* 12 = 0000 1100 */
  printf("a & b = %d\n", result );

  /* OR operation */
  result = a | b;       /* 61 = 0011 1101 */
  printf("a | b = %d\n", result );

  /* exclusive OR operation */
  result = a ^ b;       /* 49 = 0011 0001 */
  printf("a ^ b = %d\n", result );

  /* complement operation */
  result = ~a;          /*-61 = 1100 0011 */
  printf("~a = %d\n", result );

  /* left shift operation */
  result = a << 2;     /* 240 = 1111 0000 */
  printf("a << 2 = %d\n", result );

  /* right shift operation */
  result = a >> 2;     /* 15 = 0000 1111 */
  printf("a >> 2 = %d\n", result );

  return 0;
}