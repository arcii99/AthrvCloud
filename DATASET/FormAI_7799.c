//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>

int main() {
  int num1, num2, result;
  char operator;
  
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c", &operator);
  
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
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
        printf("Error: Divide by zero");
      } else {
        result = num1 / num2;
        printf("%d / %d = %d", num1, num2, result);
      }
      break;
      
    default:
      printf("Invalid operator. Please enter +, -, *, or /");
  }
  
  return 0;
}