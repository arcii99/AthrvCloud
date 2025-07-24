//FormAI DATASET v1.0 Category: Arithmetic ; Style: minimalist
#include <stdio.h>

int main(void) {
  int num1, num2, result;
  char operation;
  
  printf("Enter an arithmetic expression (Ex: 4 + 5): ");
  scanf("%d %c %d", &num1, &operation, &num2);
  
  switch(operation) {
    case '+':
      result = num1 + num2;
      printf("Result: %d\n", result);
      break;
    case '-':
      result = num1 - num2;
      printf("Result: %d\n", result);
      break;
    case '*':
      result = num1 * num2;
      printf("Result: %d\n", result);
      break;
    case '/':
      result = num1 / num2;
      printf("Result: %d\n", result);
      break;
    case '%':
      result = num1 % num2;
      printf("Result: %d\n", result);
      break;
    default:
      printf("Invalid operation.\n");
      break;
  }
  
  return 0;
}