//FormAI DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>

int add(int a, int b) {
  return a + b;
}

int subtract(int a, int b) {
  return a - b;
}

int multiply(int a, int b) {
  return a * b;
}

int divide(int a, int b) {
  return a / b;
}

int main() {
  int a = 10, b = 5;
  int sum = add(a, b);
  int difference = subtract(a, b);
  int product = multiply(a, b);
  int quotient = divide(a, b);

  printf("%d + %d = %d\n", a, b, sum);
  printf("%d - %d = %d\n", a, b, difference);
  printf("%d * %d = %d\n", a, b, product);
  printf("%d / %d = %d\n", a, b, quotient);

  return 0;
}