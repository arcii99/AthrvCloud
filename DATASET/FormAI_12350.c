//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include<stdio.h>
#include<math.h>

int main() {
  char operator;
  float num1, num2, result;
  
  printf("Welcome to the Scientific Calculator Program!\n");
  printf("Enter operator (+, -, *, /, ^) : ");
  scanf("%c", &operator); // scan operator input

  switch(operator) { // switch case for different operators
    case '+':
      printf("Enter two numbers separated by a space : ");
      scanf("%f %f", &num1, &num2); // scan two numbers input
      result = num1 + num2; // addition operation
      printf("%.2f + %.2f = %.2f", num1, num2, result); // print result
      break;
      
    case '-':
      printf("Enter two numbers separated by a space : ");
      scanf("%f %f", &num1, &num2); // scan two numbers input
      result = num1 - num2; // subtraction operation
      printf("%.2f - %.2f = %.2f", num1, num2, result); // print result
      break;
      
    case '*':
      printf("Enter two numbers separated by a space : ");
      scanf("%f %f", &num1, &num2); // scan two numbers input
      result = num1 * num2; // multiplication operation
      printf("%.2f * %.2f = %.2f", num1, num2, result); // print result
      break;
      
    case '/':
      printf("Enter two numbers separated by a space : ");
      scanf("%f %f", &num1, &num2); // scan two numbers input
      if(num2 == 0) { // check for division by zero error
        printf("Error! Division by zero.");
      } else {
        result = num1 / num2; // division operation
        printf("%.2f / %.2f = %.2f", num1, num2, result); // print result
      }
      break;
      
    case '^':
      printf("Enter base number : ");
      scanf("%f", &num1); // scan base number input
      printf("Enter exponent number : ");
      scanf("%f", &num2); // scan exponent number input
      result = pow(num1, num2); // exponentiation operation using pow() function
      printf("%.2f ^ %.2f = %.2f", num1, num2, result); // print result
      break;
      
    default:
      printf("Error! Invalid operator.");
  } // end switch case
  
  return 0;
} // end of program