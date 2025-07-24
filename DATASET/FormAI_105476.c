//FormAI DATASET v1.0 Category: Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main(){
  float num1, num2, result;
  char operator;
  
  printf("Welcome to my calculator program!\n");
  printf("Enter your first number: ");
  scanf("%f", &num1);
  printf("Enter your operator (+, -, *, /): ");
  scanf(" %c", &operator);
  printf("Enter your second number: ");
  scanf("%f", &num2);
  
  switch(operator){
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
      if(num2 == 0){
        printf("Division by zero is undefined.\n");
        exit(0);
      }
      result = num1 / num2;
      break;
    default:
      printf("Invalid operator.\n");
      exit(0);
  }
  
  printf("Result: %.2f\n", result);
  
  return 0;
}