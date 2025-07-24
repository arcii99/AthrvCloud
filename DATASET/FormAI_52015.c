//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include <stdio.h>
#include <math.h>

// Function to perform addition
float add(float a, float b) {
  return a + b;
}

// Function to perform subtraction
float subtract(float a, float b) {
  return a - b;
}

// Function to perform multiplication
float multiply(float a, float b) {
  return a * b;
}

// Function to perform division
float divide(float a, float b) {
  if(b == 0) {
    printf("Error: Divide by zero\n");
    return 0.0;
  }
  return a / b;
}

// Function to perform modulus operation
int mod(int a, int b) {
  return a % b;
}

// Function to perform power operation
double power(double a, double b) {
  return pow(a, b);
}

int main() {
  int choice;
  float num1, num2, result;
  char ch;

  printf("***************************\n");
  printf("**** Basic Calculator *****\n");
  printf("***************************\n");

  do {
    printf("Choose from the following operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);
        result = add(num1, num2);
        printf("Result: %.2f\n", result);
        break;

      case 2:
        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);
        result = subtract(num1, num2);
        printf("Result: %.2f\n", result);
        break;

      case 3:
        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);
        result = multiply(num1, num2);
        printf("Result: %.2f\n", result);
        break;

      case 4:
        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);
        result = divide(num1, num2);
        printf("Result: %.2f\n", result);
        break;

      case 5:
        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);
        result = mod((int)num1, (int)num2);
        printf("Result: %d\n", (int)result);
        break;

      case 6:
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);
        result = power(num1, num2);
        printf("Result: %.2lf\n", result);
        break;

      case 7:
        printf("Exiting...\n");
        exit(0);

      default:
        printf("Invalid choice. Try again.\n");
    }
    printf("Do you want to continue? (y or n): ");
    getchar();
    scanf("%c", &ch);
  } while(ch == 'y' || ch == 'Y');

  return 0;
}