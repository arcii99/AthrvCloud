//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <math.h>

int main() {
   float num1, num2;
   double result;
   int choice;

   printf("Please choose an operation:\n");
   printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponential\n");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         printf("Please enter the first number: ");
         scanf("%f", &num1);
         printf("Please enter the second number: ");
         scanf("%f", &num2);
         result = num1 + num2;
         printf("The result is: %.2f\n", result);
         break;
      case 2:
         printf("Please enter the first number: ");
         scanf("%f", &num1);
         printf("Please enter the second number: ");
         scanf("%f", &num2);
         result = num1 - num2;
         printf("The result is: %.2f\n", result);
         break;
      case 3:
         printf("Please enter the first number: ");
         scanf("%f", &num1);
         printf("Please enter the second number: ");
         scanf("%f", &num2);
         result = num1 * num2;
         printf("The result is: %.2f\n", result);
         break;
      case 4:
         printf("Please enter the dividend: ");
         scanf("%f", &num1);
         printf("Please enter the divisor: ");
         scanf("%f", &num2);
         if(num2 == 0) {
            printf("Cannot divide by zero\n");
         }
         else {
            result = num1 / num2;
            printf("The result is: %.2f\n", result);
         }
         break;
      case 5:
         printf("Please enter the base number: ");
         scanf("%f", &num1);
         printf("Please enter the exponent: ");
         scanf("%f", &num2);
         result = pow(num1, num2);
         printf("The result is: %.2f\n", result);
         break;
      default:
         printf("Invalid Choice\n");
         break;
   }

   return 0;
}