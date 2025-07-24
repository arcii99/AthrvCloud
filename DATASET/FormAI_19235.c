//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <math.h>

int main() {
  int option;
  float num1, num2;
  
  printf("Welcome to the Scientific Calculator Implementation Program\n");
  
  while(1) {
    printf("\nPlease select an option from the menu below:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Exit\n");
    scanf("%d", &option);
    
    switch(option) {
      case 1:
        printf("\nEnter two numbers to add: ");
        scanf("%f %f", &num1, &num2);
        printf("Result: %f\n", num1 + num2);
        break;
      case 2:
        printf("\nEnter two numbers to subtract: ");
        scanf("%f %f", &num1, &num2);
        printf("Result: %f\n", num1 - num2);
        break;
      case 3:
        printf("\nEnter two numbers to multiply: ");
        scanf("%f %f", &num1, &num2);
        printf("Result: %f\n", num1 * num2);
        break;
      case 4:
        printf("\nEnter two numbers to divide: ");
        scanf("%f %f", &num1, &num2);
        printf("Result: %f\n", num1 / num2);
        break;
      case 5:
        printf("\nEnter the base number: ");
        scanf("%f", &num1);
        printf("Enter the power to raise the number by: ");
        scanf("%f", &num2);
        printf("Result: %f\n", pow(num1, num2));
        break;
      case 6:
        printf("\nEnter a number to find square root of: ");
        scanf("%f", &num1);
        printf("Result: %f\n", sqrt(num1));
        break;
      case 7:
        printf("\nThank you for using the Scientific Calculator Implementation Program\n");
        return 0;
        break;
      default:
        printf("\nInvalid option selected. Please try again.\n");
        break;
    }
  }
}