//FormAI DATASET v1.0 Category: Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice = 0, i;
  float num1, num2;
  printf("This is an Introspective Calculator Program\n");
  printf("Enter an operation to perform: \n");
  printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
  scanf("%d", &choice);
  switch(choice) {
    case 1:
      printf("Enter two numbers to add: \n");
      scanf("%f %f", &num1, &num2);
      printf("The sum is: %.2f\n", num1 + num2);
      break;
    case 2:
      printf("Enter two numbers to subtract: \n");
      scanf("%f %f", &num1, &num2);
      printf("The difference is: %.2f\n", num1 - num2);
      break;
    case 3:
      printf("Enter two numbers to multiply: \n");
      scanf("%f %f", &num1, &num2);
      printf("The product is: %.2f\n", num1 * num2);
      break;
    case 4:
      printf("Enter two numbers to divide: \n");
      scanf("%f %f", &num1, &num2);
      if(num2 == 0) {
        printf("Error: division by zero\n");
      } else {
        printf("The quotient is: %.2f\n", num1 / num2);
      }
      break;
    default:
      printf("Error: invalid input\n");
      break;
  }
  return 0;
}