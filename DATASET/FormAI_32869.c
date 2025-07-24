//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include<stdio.h>

int main() {
  int num1, num2, result;
  char operator;

  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);
  printf("Enter the operator (+, -, *, /): ");
  scanf(" %c", &operator);

  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("%d + %d = %d", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("%d - %d = %d", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("%d * %d = %d", num1, num2, result);
      break;
    case '/':
      if(num2 == 0) {
        printf("Error: Cannot divide by 0");
      } else {
        result = num1 / num2;
        printf("%d / %d = %d", num1, num2, result);
      }
      break;
    default:
      printf("Error: Operator is not valid");
  }
  return 0;
}