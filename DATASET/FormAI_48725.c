//FormAI DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
int main() {
   char operator;
   double n1, n2;

   printf("Enter an operator (+, -, *, /): ");
   scanf("%c", &operator);

   printf("Enter two operands: ");
   scanf("%lf %lf",&n1, &n2);

   switch(operator)
   {
       case '+':
           printf("%.1lf + %.1lf = %.1lf",n1, n2, n1+n2);
           break;

       case '-':
           printf("%.1lf - %.1lf = %.1lf",n1, n2, n1-n2);
           break;

       case '*':
           printf("%.1lf * %.1lf = %.1lf",n1, n2, n1*n2);
           break;

       case '/':
           if(n2 == 0)
           {
               printf("Error! Cannot Divide by Zero");
           }
           else
           {
               printf("%.1lf / %.1lf = %.1lf",n1, n2, n1/n2);
           }
           break;

       default:
           printf("Error! Invalid Operator");
   }

   return 0;
}