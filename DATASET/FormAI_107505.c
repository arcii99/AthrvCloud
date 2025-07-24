//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: brave
#include<stdio.h>
#include<math.h>

void main() {
  int operation;
  float num1, num2, result;

  printf("Welcome to Brave Scientific Calculator!\n\n");

  printf("Choose operation:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Square Root\n");
  printf("6. Power\n");

  printf("\nEnter operation code: ");
  scanf("%d", &operation);

  switch(operation) {
    case 1:
      printf("\nEnter first number: ");
      scanf("%f", &num1); 

      printf("Enter second number: ");
      scanf("%f", &num2);

      result = num1 + num2;
      printf("\nResult: %.2f", result);

      break;

    case 2:
      printf("\nEnter first number: ");
      scanf("%f", &num1); 

      printf("Enter second number: ");
      scanf("%f", &num2);

      result = num1 - num2;
      printf("\nResult: %.2f", result);

      break;

    case 3:
      printf("\nEnter first number: ");
      scanf("%f", &num1); 

      printf("Enter second number: ");
      scanf("%f", &num2);

      result = num1 * num2;
      printf("\nResult: %.2f", result);

      break;

    case 4:
      printf("\nEnter first number: ");
      scanf("%f", &num1); 

      printf("Enter second number: ");
      scanf("%f", &num2);

      result = num1 / num2;
      printf("\nResult: %.2f", result);

      break;

    case 5:
      printf("\nEnter the number: ");
      scanf("%f", &num1);

      result = sqrt(num1);
      printf("\nResult: %.2f", result);

      break;

    case 6:
      printf("\nEnter the base number: ");
      scanf("%f", &num1);

      printf("Enter the power: ");
      scanf("%f", &num2);

      result = pow(num1, num2);
      printf("\nResult: %.2f", result);

      break;

    default:
      printf("\nInvalid operation code. Please try again.");
  }

  return 0;
}