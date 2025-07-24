//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Touring
// Standard includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
void printMenu();
void computeOperations(int choice);

// Main function
int main()
{
  int choice;

  // Infinite loop until user chooses to exit
  while (1)
  {
    // Display menu and get user choice
    printMenu();
    scanf("%d", &choice);

    // Compute operations based on user choice
    computeOperations(choice);
  }

  return 0;
}

// Function to display menu
void printMenu()
{
  printf("---------------------------------\n");
  printf("Scientific Calculator\n");
  printf("---------------------------------\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Square Root\n");
  printf("6. Exponentiation\n");
  printf("7. Logarithm\n");
  printf("8. Quit\n");
  printf("---------------------------------\n");
  printf("Enter your choice: ");
}

// Function to compute operations based on user choice
void computeOperations(int choice)
{
  double val1, val2, result;

  switch (choice)
  {
    case 1:
      printf("Enter first value: ");
      scanf("%lf", &val1);
      printf("Enter second value: ");
      scanf("%lf", &val2);
      result = val1 + val2;
      printf("Result: %.2lf\n", result);
      break;
    case 2:
      printf("Enter first value: ");
      scanf("%lf", &val1);
      printf("Enter second value: ");
      scanf("%lf", &val2);
      result = val1 - val2;
      printf("Result: %.2lf\n", result);
      break;
    case 3:
      printf("Enter first value: ");
      scanf("%lf", &val1);
      printf("Enter second value: ");
      scanf("%lf", &val2);
      result = val1 * val2;
      printf("Result: %.2lf\n", result);
      break;
    case 4:
      printf("Enter first value: ");
      scanf("%lf", &val1);
      printf("Enter second value: ");
      scanf("%lf", &val2);
      if (val2 == 0)
      {
        printf("Error: Divide by zero\n");
      }
      else
      {
        result = val1 / val2;
        printf("Result: %.2lf\n", result);
      }
      break;
    case 5:
      printf("Enter value: ");
      scanf("%lf", &val1);
      if (val1 < 0)
      {
        printf("Error: Square root of negative number\n");
      }
      else
      {
        result = sqrt(val1);
        printf("Result: %.2lf\n", result);
      }
      break;
    case 6:
      printf("Enter base value: ");
      scanf("%lf", &val1);
      printf("Enter exponent value: ");
      scanf("%lf", &val2);
      result = pow(val1, val2);
      printf("Result: %.2lf\n", result);
      break;
    case 7:
      printf("Enter value: ");
      scanf("%lf", &val1);
      if (val1 <= 0)
      {
        printf("Error: Invalid input for logarithm\n");
      }
      else
      {
        result = log10(val1);
        printf("Result: %.2lf\n", result);
      }
      break;
    case 8:
      printf("Exiting...\n");
      exit(0);
      break;
    default:
      printf("Error: Invalid choice\n");
  }
}