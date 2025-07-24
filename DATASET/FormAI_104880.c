//FormAI DATASET v1.0 Category: Calculator ; Style: relaxed
#include <stdio.h>

// function to add two numbers
int add(int a, int b) {
  return a + b;
}

// function to subtract two numbers
int subtract(int a, int b) {
  return a - b;
}

// function to multiply two numbers
int multiply(int a, int b) {
  return a * b;
}

// function to divide two numbers
float divide(int a, int b) {
  if (b == 0) {
    printf("Error: Division by zero\n");
    return 0;
  }
  return (float) a / b;
}

int main() {

  // get user input
  int num1, num2;
  printf("Enter first number: ");
  scanf("%d", &num1);
  printf("Enter second number: ");
  scanf("%d", &num2);

  // display menu
  printf("\n1) Add\n");
  printf("2) Subtract\n");
  printf("3) Multiply\n");
  printf("4) Divide\n");
  printf("5) Exit\n");

  // get user choice
  int choice;
  printf("\nEnter choice number: ");
  scanf("%d", &choice);

  // perform operation based on user choice
  switch (choice) {
    case 1:
      printf("\n%d + %d = %d\n", num1, num2, add(num1, num2));
      break;
    case 2:
      printf("\n%d - %d = %d\n", num1, num2, subtract(num1, num2));
      break;
    case 3:
      printf("\n%d * %d = %d\n", num1, num2, multiply(num1, num2));
      break;
    case 4:
      printf("\n%d / %d = %f\n", num1, num2, divide(num1, num2));
      break;
    case 5:
      return 0;
    default:
      printf("\nInvalid choice\n");
      break;
  }

  return 0;

}