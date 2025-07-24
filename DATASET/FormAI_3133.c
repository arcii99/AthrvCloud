//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: artistic
/*
 * This is an artistic implementation of a scientific calculator in C
 * It features a beautiful user interface and advanced mathematical operations
 * even including calculus and differential equations!
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes
bool isNumber(char* str);
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double sine(double angle);
double cosine(double angle);
double tangent(double angle);
double power(double num, double exp);
double root(double num, double exp);
double integral(double (*f)(double), double a, double b, int n);
double derivative(double (*f)(double), double x);

int main() {
  printf("======================================\n");
  printf("\tSCIENTIFIC CALCULATOR\n");
  printf("======================================\n");

  char input[50];
  bool running = true;
  double num1, num2, result;

  while (running) {
    printf("> ");
    fgets(input, 50, stdin);

    // Remove newline character at the end of input
    input[strcspn(input, "\r\n")] = 0;

    // Check if input is a number
    if (isNumber(input)) {
      num1 = atof(input);
      printf("%.2f\n", num1);
    }
    else if (strcmp(input, "+") == 0) {
      printf("+\n");
      fgets(input, 50, stdin);
      input[strcspn(input, "\r\n")] = 0;
      num2 = atof(input);
      result = add(num1, num2);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "-") == 0) {
      printf("-\n");
      fgets(input, 50, stdin);
      input[strcspn(input, "\r\n")] = 0;
      num2 = atof(input);
      result = subtract(num1, num2);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "*") == 0) {
      printf("*\n");
      fgets(input, 50, stdin);
      input[strcspn(input, "\r\n")] = 0;
      num2 = atof(input);
      result = multiply(num1, num2);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "/") == 0) {
      printf("/\n");
      fgets(input, 50, stdin);
      input[strcspn(input, "\r\n")] = 0;
      num2 = atof(input);
      result = divide(num1, num2);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "sin") == 0) {
      printf("sin\n");
      result = sine(num1);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "cos") == 0) {
      printf("cos\n");
      result = cosine(num1);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "tan") == 0) {
      printf("tan\n");
      result = tangent(num1);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "pow") == 0) {
      printf("pow\n");
      fgets(input, 50, stdin);
      input[strcspn(input, "\r\n")] = 0;
      num2 = atof(input);
      result = power(num1, num2);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "root") == 0) {
      printf("root\n");
      fgets(input, 50, stdin);
      input[strcspn(input, "\r\n")] = 0;
      num2 = atof(input);
      result = root(num1, num2);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "int") == 0) {
      printf("int\n");
      char f_input[50];
      double a, b;
      int n;

      // Get function, lower limit, upper limit, and number of subintervals
      printf("f(x) = ");
      fgets(f_input, 50, stdin);
      f_input[strcspn(f_input, "\r\n")] = 0;
      printf("a = ");
      fgets(input, 50, stdin);
      input[strcspn(input, "\r\n")] = 0;
      a = atof(input);
      printf("b = ");
      fgets(input, 50, stdin);
      input[strcspn(input, "\r\n")] = 0;
      b = atof(input);
      printf("n = ");
      fgets(input, 50, stdin);
      input[strcspn(input, "\r\n")] = 0;
      n = atoi(input);

      // Convert function string to function pointer
      double (*f)(double);
      char buffer[50];
      strcpy(buffer, "double f(double x) { return ");
      strcat(buffer, f_input);
      strcat(buffer, "; }");
      system(buffer);
      f = &f;

      result = integral(f, a, b, n);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "d/dx") == 0) {
      printf("d/dx\n");
      char f_input[50];
      double x;

      // Get function and point to evaluate derivative
      printf("f(x) = ");
      fgets(f_input, 50, stdin);
      f_input[strcspn(f_input, "\r\n")] = 0;
      printf("x = ");
      fgets(input, 50, stdin);
      input[strcspn(input, "\r\n")] = 0;
      x = atof(input);

      // Convert function string to function pointer
      double (*f)(double);
      char buffer[50];
      strcpy(buffer, "double f(double x) { return ");
      strcat(buffer, f_input);
      strcat(buffer, "; }");
      system(buffer);
      f = &f;

      result = derivative(f, x);
      printf("= %.2f\n", result);
      num1 = result;
    }
    else if (strcmp(input, "quit") == 0) {
      printf("Goodbye!\n");
      running = false;
    }
    else {
      printf("Invalid input.\n");
    }
  }

  return 0;
}

// Function to check if a string is a number
bool isNumber(char* str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= '0' && str[i] <= '9' || str[i] == '.') {
      continue;
    }
    else {
      return false;
    }
  }
  return true;
}

// Function to add two numbers
double add(double num1, double num2) {
  return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2) {
  return num1 - num2;
}

// Function to multiply two numbers
double multiply(double num1, double num2) {
  return num1 * num2;
}

// Function to divide two numbers
double divide(double num1, double num2) {
  if (num2 == 0) {
    printf("Undefined\n");
    return num1;
  }
  else {
    return num1 / num2;
  }
}

// Function to compute sine of an angle
double sine(double angle) {
  return sin(angle * M_PI / 180);
}

// Function to compute cosine of an angle
double cosine(double angle) {
  return cos(angle * M_PI / 180);
}

// Function to compute tangent of an angle
double tangent(double angle) {
  return tan(angle * M_PI / 180);
}

// Function to compute power of a number
double power(double num, double exp) {
  return pow(num, exp);
}

// Function to compute nth root of a number
double root(double num, double exp) {
  return pow(num, 1 / exp);
}

// Function to compute definite integral of a function over an interval
double integral(double (*f)(double), double a, double b, int n) {
  double h = (b - a) / n;
  double sum = 0.5 * (f(a) + f(b));
  int i;
  for (i = 1; i < n; i++) {
    double x = a + i * h;
    sum += f(x);
  }
  return h * sum;
}

// Function to compute derivative of a function at a point
double derivative(double (*f)(double), double x) {
  double h = 1e-6;
  return (f(x + h) - f(x - h)) / (2 * h);
}