//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: statistical
#include <stdio.h>
#include <math.h>

float add(float x, float y); //function prototype for addition
float subtract(float x, float y); //function prototype for subtraction
float multiply(float x, float y); //function prototype for multiplication
float divide(float x, float y); //function prototype for division
float power(float x, float y); //function prototype for power operation
float squareroot(float x); //function prototype for squareroot operation

int main() {
  char choice;
  float x, y, result;

  printf("Enter the first number: ");
  scanf("%f", &x);

  printf("Enter the second number: ");
  scanf("%f", &y);

  printf("Enter the operation (+, -, *, /, ^, s): ");
  scanf(" %c", &choice);

  switch(choice) {
    case '+':
      result = add(x, y);
      printf("%.2f + %.2f = %.2f\n", x, y, result);
      break;

    case '-':
      result = subtract(x, y);
      printf("%.2f - %.2f = %.2f\n", x, y, result);
      break;

    case '*':
      result = multiply(x, y);
      printf("%.2f * %.2f = %.2f\n", x, y, result);
      break;

    case '/':
      if (y == 0) {
        printf("Error: Division by zero\n");
        break;
      }
      result = divide(x, y);
      printf("%.2f / %.2f = %.2f\n", x, y, result);
      break;

    case '^':
      result = power(x, y);
      printf("%.2f ^ %.2f = %.2f\n", x, y, result);
      break;

    case 's':
      if (x < 0) {
        printf("Error: Can't take squareroot of a negative number\n");
        break;
      }
      result = squareroot(x);
      printf("sqrt(%.2f) = %.2f\n", x, result);
      break;

    default:
      printf("Invalid operation\n");
      break;
  }

  return 0;
}

//function definition for addition
float add(float x, float y) {
  return x + y;
}

//function definition for subtraction
float subtract(float x, float y) {
  return x - y;
}

//function definition for multiplication
float multiply(float x, float y) {
  return x * y;
}

//function definition for division
float divide(float x, float y) {
  return x / y;
}

//function definition for power operation
float power(float x, float y) {
  return pow(x, y);
}

//function definition for squareroot operation
float squareroot(float x) {
  return sqrt(x);
}