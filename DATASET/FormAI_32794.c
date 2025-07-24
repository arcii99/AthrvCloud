//FormAI DATASET v1.0 Category: Calculator ; Style: inquisitive
#include <stdio.h>

int main() {
 int num1, num2, choice, result;
 printf("Welcome! This is a calculator program\n");
 printf("Please enter the first number: ");
 scanf("%d", &num1);
 printf("\nPlease enter the second number: ");
 scanf("%d", &num2);
 printf("\nPlease select the operation you want to perform:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
 printf("\nEnter your choice(1-4): ");
 scanf("%d", &choice);
 switch(choice){

  case 1:
     result = num1 + num2;
     printf("\nThe result of the addition operation is: %d\n",result);
     break;
  case 2:
     result = num1 - num2;
     printf("\nThe result of the subtraction operation is: %d\n",result);
     break;
  case 3:
     result = num1 * num2;
     printf("\nThe result of the multiplication operation is: %d\n",result);
     break;
  case 4:
     if(num2 != 0){
        result = num1 / num2;
        printf("\nThe result of the division operation is: %d\n",result);
     }
     else{
        printf("error: division by zero\n");
     }
     break;
  default:
     printf("\nInvalid choice, please choose between 1 to 4.\n");
     break;
 }
 return 0;
}