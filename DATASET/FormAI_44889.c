//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

int main() {
  int num1 = 10, num2 = 6; 
  printf("num1=%d, num2=%d\n", num1, num2);

  num1 = num1 ^ num2; 
  num2 = num1 ^ num2; 
  num1 = num1 ^ num2;
  
  printf("After swapping, num1=%d, num2=%d\n", num1, num2);

  int num3 = 7;
  printf("num3 = %d\n", num3);

  num3 = num3 << 2; 
  printf("num3 after left shift by 2 = %d\n", num3);

  int num4 = -7;
  printf("num4 = %d\n", num4);

  num4 = num4 >> 2; 
  printf("num4 after right shift by 2 = %d\n", num4);

  int num5 = 8;
  int num6 = 7;
  printf("num5 = %d, num6 = %d\n", num5, num6);

  num5 = num5 & num6;
  printf("num5 after AND operation with num6 = %d\n", num5);

  int num7 = 8;
  int num8 = 7;
  printf("num7 = %d, num8 = %d\n", num7, num8);

  num7 = num7 | num8;
  printf("num7 after OR operation with num8 = %d\n", num7);

  int num9 = 7;
  printf("num9 = %d\n", num9);

  num9 = ~num9;
  printf("num9 after NOT operation = %d\n", num9);

  return 0;
}