//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Sherlock Holmes
/* 
  "The Case of the Mysterious Calculator"
  A C Program by Sherlock Holmes

  The year is 1895 and a new device called a "scientific calculator" has 
  been developed, causing quite a stir among the intellectual circles. 
  However, there are rumors that these calculators have been tampered with 
  and are giving inaccurate results. 

  I, Sherlock Holmes, have been hired to investigate the issue and 
  present my findings to the Royal Society. 

  Here is my implementation of a correct and reliable scientific 
  calculator in C language: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  float num1, num2;
  int option;

  printf("\n______Welcome to Sherlock Holmes' Scientific Calculator______\n\n");

  // Display menu of options
  printf("Please select an operation:\n");
  printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
  printf("5. Power\n6. Square Root\n7. Logarithm with base 10\n8. Exit\n");

  // Get user input for operation choice
  printf("Enter your choice: ");
  scanf("%d", &option);

  while (option <1 || option >8) {  // Ensure valid input
    printf("\nInvalid entry! Please enter a number between 1 and 8.\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
  }

  // Execute operation based on user choice
  switch(option) {

    case 1:  // Addition
      printf("\nEnter the first number: ");
      scanf("%f", &num1);
      printf("Enter the second number: ");
      scanf("%f", &num2);
      printf("\nResult: %.2f + %.2f = %.2f\n", num1, num2, num1+num2);
      break;

    case 2:  // Subtraction
      printf("\nEnter the first number: ");
      scanf("%f", &num1);
      printf("Enter the second number: ");
      scanf("%f", &num2);
      printf("\nResult: %.2f - %.2f = %.2f\n", num1, num2, num1-num2);
      break;

    case 3:  // Multiplication
      printf("\nEnter the first number: ");
      scanf("%f", &num1);
      printf("Enter the second number: ");
      scanf("%f", &num2);
      printf("\nResult: %.2f * %.2f = %.2f\n", num1, num2, num1*num2);
      break;

    case 4:  // Division
      printf("\nEnter the first number: ");
      scanf("%f", &num1);
      do {
        printf("Enter the second number (cannot be 0): ");
        scanf("%f", &num2);
      } while (num2 == 0);  // Ensure non-zero input

      printf("\nResult: %.2f / %.2f = %.2f\n", num1, num2, num1/num2);
      break;

    case 5:  // Power (num1^num2)    
      printf("\nEnter the base number: ");
      scanf("%f", &num1);
      printf("Enter the power: ");
      scanf("%f", &num2);
      printf("\nResult: %.2f ^ %.2f = %.2f\n", num1, num2, pow(num1,num2));
      break;

    case 6:  // Square Root
      printf("\nEnter the number: ");
      scanf("%f", &num1);
      printf("\nResult: sqrt(%.2f) = %.2f\n", num1, sqrt(num1));
      break;

    case 7:  // Logarithm with base 10
      printf("\nEnter the number: ");
      scanf("%f", &num1);
      printf("\nResult: log10(%.2f) = %.2f\n", num1, log10(num1));
      break;

    case 8:  // Exit
      printf("\nThank you for using Sherlock Holmes' Scientific Calculator.\n");
      break;

    default:
      printf("\nInvalid entry! Please enter a number between 1 and 8.\n");
      break;
  }

  return 0;
}