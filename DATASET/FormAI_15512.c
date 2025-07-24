//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: random
#include <stdio.h>
#include <math.h>

int main() {
  int option;
  float num1, num2, result;

  printf("Welcome to the Scientific Calculator!\n");

  while (1) {
    printf("Select an option:\n");
    printf("1 - Addition\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiplication\n");
    printf("4 - Division\n");
    printf("5 - Power of a number\n");
    printf("6 - Square root\n");
    printf("7 - Logarithm\n");
    printf("8 - Factorial\n");
    printf("9 - Exit\n");

    scanf("%d", &option);

    switch(option) {
      case 1:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        result = num1 + num2;
        printf("Result: %f\n", result);
        break;

      case 2:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        result = num1 - num2;
        printf("Result: %f\n", result);
        break;

      case 3:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        result = num1 * num2;
        printf("Result: %f\n", result);
        break;

      case 4:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        result = num1 / num2;
        printf("Result: %f\n", result);
        break;

      case 5:
        printf("Enter a base number: ");
        scanf("%f", &num1);
        printf("Enter an exponent: ");
        scanf("%f", &num2);
        result = pow(num1, num2);
        printf("Result: %f\n", result);
        break;

      case 6:
        printf("Enter a number: ");
        scanf("%f", &num1);
        result = sqrt(num1);
        printf("Result: %f\n", result);
        break;

      case 7:
        printf("Enter a number: ");
        scanf("%f", &num1);
        result = log(num1);
        printf("Result: %f\n", result);
        break;

      case 8:
        int input_num;
        int factorial = 1;
        printf("Enter a number: ");
        scanf("%d", &input_num);
        for (int i = 1; i <= input_num; i++){
            factorial = factorial * i;
        }
        printf("Result: %d\n", factorial);
        break;

      case 9:
        printf("Exiting calculator...\n");
        return 0;

      default:
        printf("Invalid option. Please try again.\n");
        break;
    }
  }
  return 0;
}