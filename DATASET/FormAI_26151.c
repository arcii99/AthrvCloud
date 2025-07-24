//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double square(double);
double squareRoot(double);
double sine(double);
double cosine(double);
double tangent(double);
double degreeToRad(double);
double radToDegree(double);

int main() {
  int operation;
  double num1, num2, result;

  printf("*** Scientific Calculator ***\n\n");

  // display menu
  printf("Available Operations:\n");
  printf("1. Add\n");
  printf("2. Subtract\n");
  printf("3. Multiply\n");
  printf("4. Divide\n");
  printf("5. Power\n");
  printf("6. Square\n");
  printf("7. Square Root\n");
  printf("8. Sine\n");
  printf("9. Cosine\n");
  printf("10. Tangent\n");
  printf("11. Convert degree to radian\n");
  printf("12. Convert radian to degree\n\n");

  // get input from user
  printf("Enter operation number: ");
  scanf("%d", &operation);

  switch(operation) {
    case 1:
      printf("Enter two numbers: ");
      scanf("%lf %lf", &num1, &num2);
      result = add(num1, num2);
      printf("Result: %.2lf\n", result);
      break;

    case 2:
      printf("Enter two numbers: ");
      scanf("%lf %lf", &num1, &num2);
      result = subtract(num1, num2);
      printf("Result: %.2lf\n", result);
      break;

    case 3:
      printf("Enter two numbers: ");
      scanf("%lf %lf", &num1, &num2);
      result = multiply(num1, num2);
      printf("Result: %.2lf\n", result);
      break;

    case 4:
      printf("Enter two numbers: ");
      scanf("%lf %lf", &num1, &num2);
      result = divide(num1, num2);
      printf("Result: %.2lf\n", result);
      break;

    case 5:
      printf("Enter two numbers: ");
      scanf("%lf %lf", &num1, &num2);
      result = power(num1, num2);
      printf("Result: %.2lf\n", result);
      break;

    case 6:
      printf("Enter a number: ");
      scanf("%lf", &num1);
      result = square(num1);
      printf("Result: %.2lf\n", result);
      break;

    case 7:
      printf("Enter a number: ");
      scanf("%lf", &num1);
      result = squareRoot(num1);
      printf("Result: %.2lf\n", result);
      break;

    case 8:
      printf("Enter an angle in radians: ");
      scanf("%lf", &num1);
      result = sine(num1);
      printf("Result: %.2lf\n", result);
      break;

    case 9:
      printf("Enter an angle in radians: ");
      scanf("%lf", &num1);
      result = cosine(num1);
      printf("Result: %.2lf\n", result);
      break;

    case 10:
      printf("Enter an angle in radians: ");
      scanf("%lf", &num1);
      result = tangent(num1);
      printf("Result: %.2lf\n", result);
      break;

    case 11:
      printf("Enter an angle in degrees: ");
      scanf("%lf", &num1);
      result = degreeToRad(num1);
      printf("Result: %.2lf radians\n", result);
      break;

    case 12:
      printf("Enter an angle in radians: ");
      scanf("%lf", &num1);
      result = radToDegree(num1);
      printf("Result: %.2lf degrees\n", result);
      break;

    default:
      printf("Invalid operation\n");
  }

  return 0;
}

double add(double num1, double num2) {
  return num1 + num2;
}

double subtract(double num1, double num2) {
  return num1 - num2;
}

double multiply(double num1, double num2) {
  return num1 * num2;
}

double divide(double num1, double num2) {
  if(num2 == 0) {
    printf("Error! Division by zero.\n");
    exit(0);
  }
  return num1 / num2;
}

double power(double num1, double num2) {
  return pow(num1, num2);
}

double square(double num1) {
  return pow(num1, 2);
}

double squareRoot(double num1) {
  if(num1 < 0) {
    printf("Error! Cannot find square root of a negative number.\n");
    exit(0);
  }
  return sqrt(num1);
}

double sine(double num1) {
  return sin(num1);
}

double cosine(double num1) {
  return cos(num1);
}

double tangent(double num1) {
  return tan(num1);
}

double degreeToRad(double num1) {
  return num1 * (PI / 180);
}

double radToDegree(double num1) {
  return num1 * (180 / PI);
}