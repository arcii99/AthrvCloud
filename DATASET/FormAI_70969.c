//FormAI DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>

int main() {

   int num1, num2;

   printf("Enter two numbers: ");

   if(scanf("%d",&num1) != 1 || scanf("%d",&num2) != 1){
       printf("Invalid input. Please enter valid numbers.\n");
       return 1;
   }

   char operation;

   printf("Enter the operation (+,-,*,/): ");
   scanf(" %c", &operation);

   switch(operation) {
       case '+':
            printf("%d + %d = %d\n", num1, num2, num1+num2);
            break;
       case '-':
            printf("%d - %d = %d\n", num1, num2, num1-num2);
            break;
       case '*': 
            printf("%d * %d = %d\n", num1, num2, num1*num2);
            break;
       case '/':
            if(num2 == 0) {
                printf("Undefined result. Division by zero not allowed.\n");
                break;
            }
            printf("%d / %d = %.2f\n", num1, num2, (float)num1/num2);
            break;
       default:
            printf("Invalid operation. Please enter a valid operation (+,-,*,/).\n");
            break;
   }

   return 0;
}