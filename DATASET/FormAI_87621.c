//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <math.h>

void displayMenu()
{
  printf("\n\nMathematical Operations\n");
  printf("-----------------------\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Square root\n");
  printf("6. Power\n");
  printf("7. Logarithm\n");
  printf("8. Sine\n");
  printf("9. Cosine\n");
  printf("10. Tangent\n");
  printf("11. Quit\n");
}

double getOperandFromUser()
{
  double operand;
  printf("Enter a number: ");
  scanf("%lf", &operand);
  return operand;
}

void addition()
{
  double num1 = getOperandFromUser();
  double num2 = getOperandFromUser();
  double result = num1 + num2;
  printf("Result: %lf\n\n", result);
}

void subtraction()
{
  double num1 = getOperandFromUser();
  double num2 = getOperandFromUser();
  double result = num1 - num2;
  printf("Result: %lf\n\n", result);
}

void multiplication()
{
  double num1 = getOperandFromUser();
  double num2 = getOperandFromUser();
  double result = num1 * num2;
  printf("Result: %lf\n\n", result);
}

void division()
{
  double num1 = getOperandFromUser();
  double num2 = getOperandFromUser();
  if (num2 == 0)
  {
    printf("Cannot divide by zero.\n\n");
    return;
  }
  double result = num1 / num2;
  printf("Result: %lf\n\n", result);
}

void squareRoot()
{
  double num = getOperandFromUser();
  if (num < 0)
  {
    printf("Cannot take square root of a negative number.\n\n");
    return;
  }
  double result = sqrt(num);
  printf("Result: %lf\n\n", result);
}

void power()
{
  double num1 = getOperandFromUser();
  double num2 = getOperandFromUser();
  double result = pow(num1, num2);
  printf("Result: %lf\n\n", result);
}

void logarithm()
{
  double num = getOperandFromUser();
  if (num <= 0)
  {
    printf("Cannot take logarithm of a non-positive number.\n\n");
    return;
  }
  double result = log10(num);
  printf("Result: %lf\n\n", result);
}

void sine()
{
  double num = getOperandFromUser();
  double result = sin(num);
  printf("Result: %lf\n\n", result);
}

void cosine()
{
  double num = getOperandFromUser();
  double result = cos(num);
  printf("Result: %lf\n\n", result);
}

void tangent()
{
  double num = getOperandFromUser();
  double result = tan(num);
  printf("Result: %lf\n\n", result);
}

int main()
{
  int choice = 0;
  do
  {
    displayMenu();
    printf("Enter your choice (1-11): ");
    scanf("%d", &choice);
    switch (choice)
    {
      case 1: addition(); break;
      case 2: subtraction(); break;
      case 3: multiplication(); break;
      case 4: division(); break;
      case 5: squareRoot(); break;
      case 6: power(); break;
      case 7: logarithm(); break;
      case 8: sine(); break;
      case 9: cosine(); break;
      case 10: tangent(); break;
      case 11: printf("Thank you for using the program.\n"); break;
      default: printf("Invalid choice. Please try again.\n"); break;
    }
  } while (choice != 11);

  return 0;
}