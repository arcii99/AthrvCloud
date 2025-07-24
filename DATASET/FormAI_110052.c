//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include<stdio.h>
#include<math.h>

int main(){

  char operator;
  double num1, num2;

  printf("Enter an operator (+, -, *, /, ^): ");
  scanf("%c", &operator);

  printf("Enter first number: ");
  scanf("%lf", &num1);

  printf("Enter second number: ");
  scanf("%lf", &num2);

  switch(operator){
    case '+':
      printf("%.2lf + %.2lf = %.2lf", num1, num2, num1+num2);
      break;

    case '-':
      printf("%.2lf - %.2lf = %.2lf", num1, num2, num1-num2);
      break;

    case '*':
      printf("%.2lf * %.2lf = %.2lf", num1, num2, num1*num2);
      break;

    case '/':
      if(num2 == 0){
        printf("Error! You cannot divide by zero!");
      }
      else{
        printf("%.2lf / %.2lf = %.2lf", num1, num2, num1/num2);
      }
      break;

    case '^':
      printf("%.2lf ^ %.2lf = %.2lf", num1, num2, pow(num1,num2));
      break;

    default:
      printf("Error! Invalid operator entered!");
      break;
  }

  return 0;
}