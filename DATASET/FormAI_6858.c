//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <math.h>

// Function to calculate factorial
int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  else {
    return n * factorial(n-1);
  }
}

// Function to calculate sine
double sine(int x) {
  double sine = 0.0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      sine += pow(x, 2*i+1) / factorial(2*i+1);
    }
    else {
      sine -= pow(x, 2*i+1) / factorial(2*i+1);
    }
  }
  return sine;
}

// Function to calculate cosine
double cosine(int x) {
  double cosine = 0.0;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      cosine += pow(x, 2*i) / factorial(2*i);
    }
    else {
      cosine -= pow(x, 2*i) / factorial(2*i);
    }
  }
  return cosine;
}

// Function to calculate tangent
double tangent(int x) {
  double sine_value = sine(x);
  double cosine_value = cosine(x);
  return sine_value/cosine_value;
}

int main() {
  int choice;
  double result;
  int num;
  printf("Welcome to Scientific Calculator\n\n");
  
  while(1) {
    printf("Please choose an operation:\n");
    printf("1. Sine\n");
    printf("2. Cosine\n");
    printf("3. Tangent\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
      printf("Enter an integer: ");
      scanf("%d", &num);
      result = sine(num);
      printf("Sine of %d = %f\n\n", num, result);
    }
    else if (choice == 2) {
      printf("Enter an integer: ");
      scanf("%d", &num);
      result = cosine(num);
      printf("Cosine of %d = %f\n\n", num, result);
    }
    else if (choice == 3) {
      printf("Enter an integer: ");
      scanf("%d", &num);
      result = tangent(num);
      printf("Tangent of %d = %f\n\n", num, result);
    }
    else if (choice == 4) {
      printf("Thank you for using the calculator.\n");
      break;
    }
    else {
      printf("Invalid choice, please try again.\n\n");
    }
  }
  return 0;
}