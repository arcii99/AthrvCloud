//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int option;
  
  do {
    // Displaying the menu
    printf("\nWelcome to the Visionary Calculator.\n");
    printf("Please select an option from the menu below:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Square Root\n");
    printf("8. Exit\n");
    printf("\nOption: ");
    scanf("%d", &option);
    
    // Handling the user's choice
    switch(option) {
      case 1:
        {
          float num1, num2;
          printf("\nPlease enter the first number: ");
          scanf("%f", &num1);
          printf("\nPlease enter the second number: ");
          scanf("%f", &num2);
          printf("\nResult: %.2f\n", num1 + num2);
          break;
        }
      case 2:
        {
          float num1, num2;
          printf("\nPlease enter the first number: ");
          scanf("%f", &num1);
          printf("\nPlease enter the second number: ");
          scanf("%f", &num2);
          printf("\nResult: %.2f\n", num1 - num2);
          break;
        }
      case 3:
        {
          float num1, num2;
          printf("\nPlease enter the first number: ");
          scanf("%f", &num1);
          printf("\nPlease enter the second number: ");
          scanf("%f", &num2);
          printf("\nResult: %.2f\n", num1 * num2);
          break;
        }
      case 4:
        {
          float num1, num2;
          printf("\nPlease enter the first number: ");
          scanf("%f", &num1);
          printf("\nPlease enter the second number: ");
          scanf("%f", &num2);
          if (num2 != 0) {
            printf("\nResult: %.2f\n", num1 / num2);
          } else {
            printf("\nInvalid Input! Division by zero is not allowed.\n");
          }
          break;
        }
      case 5:
        {
          int num1, num2;
          printf("\nPlease enter the first number: ");
          scanf("%d", &num1);
          printf("\nPlease enter the second number: ");
          scanf("%d", &num2);
          printf("\nResult: %d\n", num1 % num2);
          break;
        }
      case 6:
        {
          float num1, num2;
          printf("\nPlease enter the base: ");
          scanf("%f", &num1);
          printf("\nPlease enter the exponent: ");
          scanf("%f", &num2);
          printf("\nResult: %.2f\n", pow(num1, num2));
          break;
        }
      case 7:
        {
          float num;
          printf("\nPlease enter the number: ");
          scanf("%f", &num);
          if (num > 0) {
            printf("\nResult: %.2f\n", sqrt(num));
          } else {
            printf("\nInvalid Input! Negative numbers are not allowed.\n");
          }
          break;
        }
      case 8:
        printf("\nThank you for using Visionary Calculator!\n");
        return 0;
      default:
        printf("\nInvalid Input! Please try again.\n");
        break;
    }
  } while (option != 8);
  
  return 0;
}