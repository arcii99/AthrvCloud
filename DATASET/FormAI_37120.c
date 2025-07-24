//FormAI DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>

int main() {
  
  int num1, num2, operation;
  float result;
  
  printf("Welcome to this unique arithmetic program!\n\n");
  printf("Please enter the first number: ");
  scanf("%d", &num1);
  printf("Please enter the second number: ");
  scanf("%d", &num2);
  
  printf("\nChoose an operation to perform: \n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Modulo\n");
  printf("Enter your choice: ");
  scanf("%d", &operation);
  
  switch(operation) {
      
      case 1: // Addition
          result = num1 + num2;
          printf("\n%d + %d = %f", num1, num2, result);
          break;
          
      case 2: // Subtraction
          result = num1 - num2;
          printf("\n%d - %d = %f", num1, num2, result);
          break;
          
      case 3: // Multiplication
          result = num1 * num2;
          printf("\n%d * %d = %f", num1, num2, result);
          break;
          
      case 4: // Division
          if(num2 == 0) {
              printf("\nDivision by zero is not allowed!");
          }
          else {
              result = (float)num1 / num2;
              printf("\n%d / %d = %f", num1, num2, result);
          }
          break;
          
      case 5: // Modulo
          result = num1 % num2;
          printf("\n%d mod %d = %f", num1, num2, result);
          break;
          
      default: // Invalid operation choice
          printf("\nInvalid operation choice!");
  }
  
  printf("\n\nThank you for using this program. Have a great day!");
  
  return 0;
}