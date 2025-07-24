//FormAI DATASET v1.0 Category: Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("**** C PORTABLE CALCULATOR ****\n\n");

  float num1, num2, result;
  char operator;

  printf("Enter the first number: ");
  scanf("%f", &num1);

  printf("Enter the operator (+,-,*,/): ");
  scanf(" %c", &operator);

  printf("Enter the second number: ");
  scanf("%f", &num2);

  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
      break;
    case '/':
      if(num2 != 0) {
        result = num1 / num2;
        printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
      } else {
        printf("\nDivision by zero is not possible.\n");
      }
      break;
    default:
      printf("\nInvalid operator.\n");
      break;
  }

  return 0;
}