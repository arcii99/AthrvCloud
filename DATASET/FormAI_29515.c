//FormAI DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int num1, num2, result;
  float quotient;
  
  printf(" __      ____________  _____  _____  \n");
  printf(" \\ \\    / /|  ____\\ \\ / /_ _|/ ____| \n");
  printf("  \\ \\  / / | |__   \\ V / | | | (___   \n");
  printf("   \\ \\/ /  |  __|   > <  | |  \\___ \\  \n");
  printf("    \\  /   | |____ / . \\ | |  ____) | \n");
  printf("     \\/    |______/_/ \\_\\___|/_____/  \n");
  printf("\n");
  
  printf("Enter the first integer: ");
  scanf("%d", &num1);
  printf("Enter the second integer: ");
  scanf("%d", &num2);
  
  result = num1 + num2;
  printf("\n%d + %d = %d \n", num1, num2, result);
  
  result = num1 - num2;
  printf("\n%d - %d = %d \n", num1, num2, result);
  
  result = num1 * num2;
  printf("\n%d x %d = %d \n", num1, num2, result);
  
  if(num2 != 0) {
    quotient = (float)num1 / num2;
    printf("\n%d / %d = %.2f \n", num1, num2, quotient);
  }
  else {
    printf("\nCannot divide by zero\n");
  }
  
  result = num1 % num2;
  if(result < 0) {
    result += abs(num2);
  }
  printf("\n%d modulo %d = %d \n", num1, num2, result);
  
  result = pow(num1, num2);
  printf("\n%d raised to the power of %d = %d \n", num1, num2, result);
  
  return 0;
}