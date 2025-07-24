//FormAI DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>

// Function that returns the maximum of two numbers
int max(int a, int b) {
  return a > b ? a : b;
}

// Function that returns the minimum of two numbers
int min(int a, int b) {
  return a < b ? a : b;
}

// Function that computes the greatest common divisor of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

// Function that computes the least common multiple of two numbers
int lcm(int a, int b) {
  return (a / gcd(a, b)) * b;
}

// Function that computes the factorial of a number
int factorial(int n) {
  if (n <= 1) {
    return 1;
  }
  return n * factorial(n - 1);
}

// Function that computes the nth Fibonacci number
int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int a = 5, b = 7;

  printf("Maximum of %d and %d is %d\n", a, b, max(a, b));
  printf("Minimum of %d and %d is %d\n", a, b, min(a, b));
  printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
  printf("LCM of %d and %d is %d\n", a, b, lcm(a, b));
  printf("Factorial of %d is %d\n", a, factorial(a));
  printf("Fibonacci number at %d-th position is %d\n", a, fibonacci(a));

  return 0;
}