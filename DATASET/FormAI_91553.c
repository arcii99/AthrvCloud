//FormAI DATASET v1.0 Category: Educational ; Style: Ada Lovelace
/* Ada Lovelace Style C Program */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, result;
  
  printf("Welcome to Ada's Calculator!\n\n");
  
  printf("Please enter the first number: ");
  scanf("%d", &num1);
  
  printf("Please enter the second number: ");
  scanf("%d", &num2);
  
  result = num1 + num2;
  printf("\n%d + %d = %d\n", num1, num2, result);
  
  result = num1 - num2;
  printf("%d - %d = %d\n", num1, num2, result);
  
  result = num1 * num2;
  printf("%d * %d = %d\n", num1, num2, result);
  
  if (num2 == 0) {
    printf("Cannot divide by zero.\n");
  }
  else {
    result = num1 / num2;
    printf("%d / %d = %d\n", num1, num2, result);
  }
  
  printf("\nThank you for using Ada's Calculator!");
  return 0;
}