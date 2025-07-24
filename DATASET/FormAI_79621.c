//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cryptic
#include <stdio.h>
#include <math.h>

int main() {

  int choice;
  float num1, num2, result;

  printf("**********SCIENTIFIC CALCULATOR**********\n\n");
  printf("Please select an option:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Square root\n");
  printf("6. Power\n");
  printf("7. Sine\n");
  printf("8. Cosine\n");
  printf("9. Tangent\n");

  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Enter first number: ");
      scanf("%f", &num1);
      printf("Enter second number: ");
      scanf("%f", &num2);
      result = num1 + num2;
      printf("Result: %f", result);
      break;
    case 2:
      printf("Enter first number: ");
      scanf("%f", &num1);
      printf("Enter second number: ");
      scanf("%f", &num2);
      result = num1 - num2;
      printf("Result: %f", result);
      break;
    case 3:
      printf("Enter first number: ");
      scanf("%f", &num1);
      printf("Enter second number: ");
      scanf("%f", &num2);
      result = num1 * num2;
      printf("Result: %f", result);
      break;
    case 4:
      printf("Enter first number: ");
      scanf("%f", &num1);
      printf("Enter second number: ");
      scanf("%f", &num2);
      result = num1 / num2;
      printf("Result: %f", result);
      break;
    case 5:
      printf("Enter a number: ");
      scanf("%f", &num1);
      result = sqrt(num1);
      printf("Result: %f", result);
      break;
    case 6:
      printf("Enter base: ");
      scanf("%f", &num1);
      printf("Enter exponent: ");
      scanf("%f", &num2);
      result = pow(num1, num2);
      printf("Result: %f", result);
      break;
    case 7:
      printf("Enter an angle in degrees: ");
      scanf("%f", &num1);
      result = sin(num1 * M_PI / 180);
      printf("Result: %f", result);
      break;
    case 8:
      printf("Enter an angle in degrees: ");
      scanf("%f", &num1);
      result = cos(num1 * M_PI / 180);
      printf("Result: %f", result);
      break;
    case 9:
      printf("Enter an angle in degrees: ");
      scanf("%f", &num1);
      result = tan(num1 * M_PI / 180);
      printf("Result: %f", result);
      break;
    default:
      printf("Invalid input.");
  }

  return 0;
}