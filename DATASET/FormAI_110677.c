//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>

int main() {
  int num1, num2, result;
  char op;

  printf("Enter first number: ");
  scanf("%d", &num1);

  printf("Enter operator (+, -, *, /): ");
  scanf(" %c", &op);

  printf("Enter second number: ");
  scanf("%d", &num2);

  switch(op) {
    case '+':
      result = num1 + num2;
      break;
    
    case '-':
      result = num1 - num2;
      break;
    
    case '*':
      result = num1 * num2;
      break;

    case '/':
      if(num2 == 0) {
        printf("Error! Cannot divide by zero.");
        return 0;
      }
      result = num1 / num2;
      break;

    default:
      printf("Invalid Operator!");
      return 0;
  }

  printf("%d %c %d = %d\n", num1, op, num2, result);

  return 0;
}