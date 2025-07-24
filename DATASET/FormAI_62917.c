//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define PI 3.14159265  // define value of pi
#define MAX_LENGTH 100 // define maximum length of expression

// function to check if character is an operator or not
int isOperator(char c) {
   if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
      return 1;
   else
      return 0;
}

// function to check if character is a valid operand or not
int isOperand(char c) {
   if(c >= '0' && c <= '9')
      return 1;
   else
      return 0;
}

// function to perform basic arithmetic operations
double performOperation(char operator, double operand1, double operand2) {
   switch(operator) {
      case '+': return operand1 + operand2;
      case '-': return operand1 - operand2;
      case '*': return operand1 * operand2;
      case '/': return operand1 / operand2;
      case '%': return fmod(operand1,operand2);
      case '^': return pow(operand1,operand2);
      default : return 0;
   }
}

int main(){
   char expression[MAX_LENGTH];
   double stack[MAX_LENGTH], result;
   int top = -1, i;

   printf("Enter the expression: ");
   fgets(expression,MAX_LENGTH,stdin); // get expression from user input

   for(i = 0; expression[i] != '\0'; i++) {
      char currentChar = expression[i];

      if(isOperator(currentChar)) {
         double operand2 = stack[top--];
         double operand1 = stack[top--];
         result = performOperation(currentChar, operand1, operand2);
         stack[++top] = result;
      } else if(isOperand(currentChar)) {
         double operand = 0;
         int j;
         
         // convert sequence of continuous digits to corresponding number
         for(j = i; isOperand(expression[j]); j++) {
            operand = operand * 10 + (expression[j] - '0');
         }
         i = j - 1;
         stack[++top] = operand;
      } else if(isalpha(currentChar)) {
         switch(currentChar) {
            case 's': result = sin(stack[top]); break;
            case 'c': result = cos(stack[top]); break;
            case 't': result = tan(stack[top]); break;
            case 'l': result = log(stack[top]); break;
            case 'e': result = exp(stack[top]); break;
            case 'p': result = pow(PI,stack[top]); break;
            default : result = 0;
         }
         stack[++top] = result;
      }
   }
   printf("Result is: %.2lf\n", result);
   return 0;
}