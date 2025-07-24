//FormAI DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
  int num1, num2, option;
  float res;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  printf("\nSelect an arithmetic operation to perform:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Modulus\n");
  printf("6. Exponentiation\n");
  printf("7. Root\n");
  printf("Option: ");
  scanf("%d", &option);

  switch (option)
  {
  case 1: // Addition
    res = num1 + num2;
    printf("Result: %f\n", res);
    break;

  case 2: // Subtraction
    res = num1 - num2;
    printf("Result: %f\n", res);
    break;

  case 3: // Multiplication
    res = num1 * num2;
    printf("Result: %f\n", res);
    break;

  case 4: // Division
    if (num2 == 0)
    {
      printf("Error: Cannot divide by zero\n");
      exit(EXIT_FAILURE);
    }
    res = (float)num1 / num2;
    printf("Result: %f\n", res);
    break;

  case 5: // Modulus
    if (num2 == 0)
    {
      printf("Error: Cannot divide by zero\n");
      exit(EXIT_FAILURE);
    }
    res = num1 % num2;
    printf("Result: %f\n", res);
    break;

  case 6: // Exponentiation
    res = pow(num1, num2);
    printf("Result: %f\n", res);
    break;

  case 7: // Root
    if (num2 == 0)
    {
      printf("Error: Cannot divide by zero\n");
      exit(EXIT_FAILURE);
    }
    res = pow(num1, 1.0 / num2);
    printf("Result: %f\n", res);
    break;

  default:
    printf("Invalid option!\n");
    exit(EXIT_FAILURE);
  }

  printf("\nThank you for using this program!\n");

  return 0;
}