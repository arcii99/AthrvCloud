//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
#include <stdio.h>
#include <math.h>

int main() {
   char operator;
   double num1, num2, result;
   printf("Welcome to Grateful Scientific Calculator! \n");
   printf("Enter an operator (+, -, *, /, ^, s, c, t, l, r, a, f): \n");
   scanf("%c", &operator);
   
   switch(operator) {
      case '+': // Addition
         printf("Enter two operands (separated by a space): \n");
         scanf("%lf %lf",&num1, &num2);
         result = num1 + num2;
         printf("The sum of %.2lf and %.2lf is: %.2lf", num1, num2, result);
         break;

      case '-': // Subtraction 
         printf("Enter two operands (separated by a space): \n");
         scanf("%lf %lf",&num1, &num2);
         result = num1 - num2;
         printf("The difference of %.2lf from %.2lf is: %.2lf", num2, num1, result);
         break;

      case '*': // Multiplication
         printf("Enter two operands (separated by a space): \n");
         scanf("%lf %lf",&num1, &num2);
         result = num1 * num2;
         printf("The product of %.2lf and %.2lf is: %.2lf", num1, num2, result);
         break;

      case '/': // Division
         printf("Enter two operands (separated by a space): \n");
         scanf("%lf %lf",&num1, &num2);
         if(num2 == 0) {
            printf("Error: Division by zero is undefined");
            break;
         }
         result = num1 / num2;
         printf("The quotient of %.2lf divided by %.2lf is: %.2lf", num1, num2, result);
         break;

      case '^': // Exponentiation
         printf("Enter two operands (separated by a space): \n");
         scanf("%lf %lf",&num1, &num2);
         result = pow(num1, num2);
         printf("%.2lf raised to the power of %.2lf is: %.2lf", num1, num2, result);
         break;

      case 's': // Sine function
         printf("Enter the operand in degrees: \n");
         scanf("%lf", &num1);
         result = sin(num1 * M_PI / 180.0);
         printf("The sine of %.2lf degrees is: %.2lf", num1, result);
         break;

      case 'c': // Cosine function
         printf("Enter the operand in degrees: \n");
         scanf("%lf", &num1);
         result = cos(num1 * M_PI / 180.0);
         printf("The cosine of %.2lf degrees is: %.2lf", num1, result);
         break;

      case 't': // Tangent function
         printf("Enter the operand in degrees: \n");
         scanf("%lf", &num1);
         result = tan(num1 * M_PI / 180.0);
         printf("The tangent of %.2lf degrees is: %.2lf", num1, result);
         break;

      case 'l': // Natural logarithm function
         printf("Enter the operand: \n");
         scanf("%lf", &num1);
         result = log(num1);
         printf("The natural logarithm of %.2lf is: %.2lf", num1, result);
         break;

      case 'r': // Square root function
         printf("Enter the operand: \n");
         scanf("%lf", &num1);
         if(num1 < 0) {
            printf("Error: Square roots of negative numbers are undefined");
            break;
         }
         result = sqrt(num1);
         printf("The square root of %.2lf is: %.2lf", num1, result);
         break;

      case 'a': // Absolute value function
         printf("Enter the operand: \n");
         scanf("%lf", &num1);
         result = fabs(num1);
         printf("The absolute value of %.2lf is: %.2lf", num1, result);
         break;

      case 'f': // Floor function
         printf("Enter the operand: \n");
         scanf("%lf", &num1);
         result = floor(num1);
         printf("The floor of %.2lf is: %.2lf", num1, result);
         break;

      default:
         printf("Error: Invalid operator. Please enter a valid operator as listed.");
         break;
   }   
   return 0;
}