//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: introspective
#include <stdio.h>
#include <math.h>

int main() {
   char operator;
   double num1, num2, result;

   printf("Enter an operator (+, -, *, /, ^): ");
   scanf("%c", &operator);

   printf("Enter two operands: ");
   scanf("%lf %lf", &num1, &num2);

   switch(operator)
    {
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
            if(num2 == 0)
            {
                printf("Error: Division by zero");
                return 0;
            }
            else
            {
                result = num1 / num2;
            }
            break;

        case '^':
            result = pow(num1, num2);
            break;

        default:
            printf("Error: Operator not recognized");
            return 0;
    }

   printf("%.2lf %c %.2lf = %.2lf", num1, operator, num2, result);
   return 0;
}