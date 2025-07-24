//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// function prototypes
float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
float power(float, float);
float square_root(float);

// main function
int main(void) {
  int choice;
  float num1, num2, result;
  
  printf("Welcome to the Scientific Calculator!\n");
  
  // loop until user selects "6" to exit
  do {
    printf("\nPlease select an operation: \n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Square root\n");
    printf("7. Exit\n");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        printf("Enter two numbers to add: ");
        scanf("%f %f", &num1, &num2);
        result = add(num1, num2);
        printf("%.2f + %.2f = %.2f\n", num1, num2, result);
        break;
        
      case 2:
        printf("Enter two numbers to subtract: ");
        scanf("%f %f", &num1, &num2);
        result = subtract(num1, num2);
        printf("%.2f - %.2f = %.2f\n", num1, num2, result);
        break;
        
      case 3:
        printf("Enter two numbers to multiply: ");
        scanf("%f %f", &num1, &num2);
        result = multiply(num1, num2);
        printf("%.2f * %.2f = %.2f\n", num1, num2, result);
        break;
        
      case 4:
        printf("Enter two numbers to divide: ");
        scanf("%f %f", &num1, &num2);
        result = divide(num1, num2);
        if (result == INFINITY || result == -INFINITY) {
          printf("Cannot divide by zero.\n");
        }
        else {
          printf("%.2f / %.2f = %.2f\n", num1, num2, result);
        }
        break;
        
      case 5:
        printf("Enter the base number: ");
        scanf("%f", &num1);
        printf("Enter the exponent: ");
        scanf("%f", &num2);
        result = power(num1, num2);
        printf("%.2f ^ %.2f = %.2f\n", num1, num2, result);
        break;
        
      case 6:
        printf("Enter a number to find the square root: ");
        scanf("%f", &num1);
        result = square_root(num1);
        if (result < 0) {
          printf("Invalid input.\n");
        }
        else {
          printf("sqrt(%.2f) = %.2f\n", num1, result);
        }
        break;
        
      case 7:
        printf("Goodbye!\n");
        break;
        
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while (choice != 7);
  
  return 0;
}

// function definitions
float add(float num1, float num2) {
  return num1 + num2;
}

float subtract(float num1, float num2) {
  return num1 - num2;
}

float multiply(float num1, float num2) {
  return num1 * num2;
}

float divide(float num1, float num2) {
  return num1 / num2;
}

float power(float base, float exponent) {
  return pow(base, exponent);
}

float square_root(float num) {
  if (num < 0) {
    return -1;
  }
  return sqrt(num);
}