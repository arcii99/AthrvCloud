//FormAI DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>

int main() {
  int num1 = 10;
  int num2 = 3;
  float num3 = 7.5;
  
  printf("num1 + num2 = %d\n", num1 + num2);
  printf("num1 - num2 = %d\n", num1 - num2);
  printf("num1 * num2 = %d\n", num1 * num2);
  printf("num1 / num2 = %d\n", num1 / num2);
  printf("num1 %% num2 = %d\n", num1 % num2);
  
  printf("num1 + num3 = %f\n", num1 + num3);
  printf("num1 / num3 = %f\n", num1 / num3);
  
  int result = num1 + num2 * num3;
  printf("num1 + num2 * num3 = %d\n", result);
  
  int x = 2;
  int y = 5;
  int z = 7;
  int equation = x * y + z / x - y % z;
  printf("The equation x * y + z / x - y %% z = %d\n", equation);
  
  return 0;
}