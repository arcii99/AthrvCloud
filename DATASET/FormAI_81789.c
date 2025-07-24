//FormAI DATASET v1.0 Category: Syntax parsing ; Style: systematic
#include <stdio.h>

int main() {
   char operator;
   float num1, num2;

   printf("Enter operator either +, -, * or /: ");
   scanf("%c", &operator);

   printf("Enter two operands: ");
   scanf("%f %f",&num1, &num2);

   switch(operator) {
      case '+':
         printf("%.2f + %.2f = %.2f",num1, num2, num1+num2);
         break;

      case '-':
         printf("%.2f - %.2f = %.2f",num1, num2, num1-num2);
         break;

      case '*':
         printf("%.2f * %.2f = %.2f",num1, num2, num1*num2);
         break;

      case '/':
         printf("%.2f / %.2f = %.2f",num1, num2, num1/num2);
         break;

      default:
         printf("Error! operator is not correct");
         break;
   }

   return 0;
}