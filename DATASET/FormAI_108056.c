//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

int main() {
  char operator; 
  double num1, num2, result;
  
  printf("Enter an operator (+, -, *, /, ^, %%): ");
  scanf("%c", &operator);
  
  printf("Enter two numbers: ");
  scanf("%lf %lf", &num1, &num2);
  
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
        printf("Error: Divide by Zero");
        break;
      }
      result = num1 / num2;
      break;
    case '^':
      result = pow(num1, num2);
      break;
    case '%':
      result = fmod(num1, num2);
      break;
    default:
      printf("Error: Invalid Operator");
      break;
  }
  
  printf("The result is: %lf", result);
  
  return 0;
}