//FormAI DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2;
  char operator;
  float result;
  
  printf("Please enter the first number: ");
  scanf("%d", &num1);
  
  printf("Please enter the operator (+, -, *, /): ");
  scanf(" %c", &operator);
  
  printf("Please enter the second number: ");
  scanf("%d", &num2);
  
  switch(operator) {
    
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
        printf("Error: Division by zero\n");
        exit(EXIT_FAILURE);
      }
      
      result = (float)num1 / num2;
      break;
      
    default:
      printf("Invalid operator entered\n");
      exit(EXIT_FAILURE);
  }
  
  printf("%d %c %d = %f\n", num1, operator, num2, result);
  
  return 0;
}