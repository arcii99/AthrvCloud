//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
   int choice;
   float num1, num2, result;
   char op;

   printf("Enter the operation you want to perform:\n"
          "1. Addition\t2. Subtraction\n"
          "3. Multiplication\t4. Division\n"
          "5. Power\t6. Square Root\n");
   scanf("%d", &choice);

   if(choice==1 || choice==2 || choice==3 || choice==4) {
      printf("Enter two numbers separated by a space: ");
      scanf("%f %f", &num1, &num2);
   }
   else if(choice==5 || choice==6) {
      printf("Enter a number: ");
      scanf("%f", &num1);
   }

   switch(choice) {
       
       case 1:
           op = '+';
           result = num1 + num2;
           break;

       case 2:
           op = '-';
           result = num1 - num2;
           break;

       case 3:
           op = '*';
           result = num1 * num2;
           break;

       case 4:
           op = '/';
           result = num1 / num2;
           break;

       case 5:
           op = '^';
           result = pow(num1, num2);
           break;

       case 6:
           op = '#';
           result = sqrt(num1);
           break;

       default:
           printf("Invalid choice. Please try again.\n");
           return 1;
   }

   printf("The result of %.2f %c %.2f is: %.2f\n", num1, op, num2, result);

   return 0;
}