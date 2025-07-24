//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include<stdio.h>
#include<math.h>

// Function prototypes
void addition();
void subtraction();
void multiplication();
void division();
void power();
void square_root();
void logarithm();
void modulus();
void factorial();

int main() {
  int choice;

  while(1) {
    // Display the menu
    printf("\n--------- MENU ---------\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n7. Logarithm\n8. Modulus\n9. Factorial\n0. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addition();
        break;
      case 2:
        subtraction();
        break;
      case 3:
        multiplication();
        break;
      case 4:
        division();
        break;
      case 5:
        power();
        break;
      case 6:
        square_root();
        break;
      case 7:
        logarithm();
        break;
      case 8:
        modulus();
        break;
      case 9:
        factorial();
        break;
      case 0:
        printf("\nGoodbye!\n");
        return 0;
      default:
        printf("\nInvalid choice. Please enter a valid choice.\n");
    }
  }

  return 0;
}

void addition() {
  double num1, num2, result;
  printf("\nEnter two numbers: ");
  scanf("%lf %lf", &num1, &num2);
  result = num1 + num2;
  printf("The result is: %lf\n", result);
}

void subtraction() {
  double num1, num2, result;
  printf("\nEnter two numbers: ");
  scanf("%lf %lf", &num1, &num2);
  result = num1 - num2;
  printf("The result is: %lf\n", result);
}

void multiplication() {
  double num1, num2, result;
  printf("\nEnter two numbers: ");
  scanf("%lf %lf", &num1, &num2);
  result = num1 * num2;
  printf("The result is: %lf\n", result);
}

void division() {
  double num1, num2, result;
  printf("\nEnter two numbers: ");
  scanf("%lf %lf", &num1, &num2);
  if(num2 == 0) {
    printf("Error: Division by zero.\n");
    return;
  }
  result = num1 / num2;
  printf("The result is: %lf\n", result);
}

void power() {
  double num, exp, result;
  printf("\nEnter a number: ");
  scanf("%lf", &num);
  printf("Enter the exponent: ");
  scanf("%lf", &exp);
  result = pow(num, exp);
  printf("The result is: %lf\n", result);
}

void square_root() {
  double num, result;
  printf("\nEnter a number: ");
  scanf("%lf", &num);
  if(num < 0) {
    printf("Error: Cannot calculate square root of negative number.\n");
    return;
  }
  result = sqrt(num);
  printf("The result is: %lf\n", result);
}

void logarithm() {
  double num, result;
  printf("\nEnter a number: ");
  scanf("%lf", &num);
  if(num <= 0) {
    printf("Error: Cannot calculate logarithm of non-positive number.\n");
    return;
  }
  result = log10(num);
  printf("The result is: %lf\n", result);
}

void modulus() {
  int num1, num2, result;
  printf("\nEnter two numbers: ");
  scanf("%d %d", &num1, &num2);
  result = num1 % num2;
  printf("The result is: %d\n", result);
}

void factorial() {
  int num, i;
  unsigned long long int fact = 1;
  printf("\nEnter a number: ");
  scanf("%d", &num);
  if(num < 0) {
    printf("Error: Cannot calculate factorial of negative number.\n");
    return;
  }
  for(i=1; i<=num; i++) {
    fact *= i;
  }
  printf("The factorial of %d is: %llu\n", num, fact);
}