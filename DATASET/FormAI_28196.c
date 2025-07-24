//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

int main() {
  int num1, num2, result;
  char operator;
  
  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &operator);
  
  printf("Enter first number: ");
  scanf("%d", &num1);
  
  printf("Enter second number: ");
  scanf("%d", &num2);
  
  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("The sum of %d and %d is %d.", num1, num2, result);
      break;
    case '-':
      result = num1 - num2;
      printf("The difference of %d and %d is %d.", num1, num2, result);
      break;
    case '*':
      result = num1 * num2;
      printf("The product of %d and %d is %d.", num1, num2, result);
      break;
    case '/':
      if(num2 == 0) {
        printf("Cannot divide by zero.");
        exit(0);
      }
      result = num1 / num2;
      printf("%d divided by %d is %d.", num1, num2, result);
      break;
    default:
      printf("Invalid operator. Please try again.");
  }
  
  return 0;
}