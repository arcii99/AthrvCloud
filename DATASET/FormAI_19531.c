//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to calculate sine of angle in degrees */
double calculate_sine(double angle) {
  double radians = angle * M_PI / 180.0; // Convert degrees to radians
  return sin(radians);
}

/* Function to calculate cosine of angle in degrees */
double calculate_cosine(double angle) {
  double radians = angle * M_PI / 180.0; // Convert degrees to radians
  return cos(radians);
}

/* Function to calculate tangent of angle in degrees */
double calculate_tangent(double angle) {
  double radians = angle * M_PI / 180.0; // Convert degrees to radians
  return tan(radians);
}

/* Function to calculate logarithm base 10 of x */
double calculate_log(double x) {
  return log10(x);
}

/* Function to calculate power of base raised to exponent */
double calculate_power(double base, double exponent) {
  return pow(base, exponent);
}

/* Function to calculate square root of x */
double calculate_sqrt(double x) {
  return sqrt(x);
}

int main() {
  int operation;
  double number, angle, base, exponent, result;

  printf("Welcome to the scientific calculator!\n");

  do {
    printf("\nPlease choose an operation:\n");
    printf("1. Calculate sine\n");
    printf("2. Calculate cosine\n");
    printf("3. Calculate tangent\n");
    printf("4. Calculate logarithm base 10\n");
    printf("5. Calculate power\n");
    printf("6. Calculate square root\n");
    printf("7. Exit\n");
    scanf("%d", &operation);

    switch (operation) {
      case 1:
        printf("Please enter a degree angle: ");
        scanf("%lf", &angle);
        result = calculate_sine(angle);
        printf("The sine of %lf degrees is %lf\n", angle, result);
        break;
      case 2:
        printf("Please enter a degree angle: ");
        scanf("%lf", &angle);
        result = calculate_cosine(angle);
        printf("The cosine of %lf degrees is %lf\n", angle, result);
        break;
      case 3:
        printf("Please enter a degree angle: ");
        scanf("%lf", &angle);
        result = calculate_tangent(angle);
        printf("The tangent of %lf degrees is %lf\n", angle, result);
        break;
      case 4:
        printf("Please enter a number: ");
        scanf("%lf", &number);
        result = calculate_log(number);
        printf("The logarithm base 10 of %lf is %lf\n", number, result);
        break;
      case 5:
        printf("Please enter a base: ");
        scanf("%lf", &base);
        printf("Please enter an exponent: ");
        scanf("%lf", &exponent);
        result = calculate_power(base, exponent);
        printf("%lf raised to the power of %lf is %lf\n", base, exponent, result);
        break;
      case 6:
        printf("Please enter a number: ");
        scanf("%lf", &number);
        result = calculate_sqrt(number);
        printf("The square root of %lf is %lf\n", number, result);
        break;
      case 7:
        printf("Exiting calculator...\n");
        exit(0);
      default:
        printf("Invalid operation. Please try again.\n");
        break;
    }
  } while (1);

  return 0;
}