//FormAI DATASET v1.0 Category: Scientific ; Style: minimalist
#include <stdio.h>

// function prototypes
int multiply(int num1, int num2);
void printResults(int num1, int num2, int product);

int main() {
  int num1, num2;
  printf("Enter two numbers to multiply: ");
  scanf("%d %d", &num1, &num2);

  // call multiplication function
  int product = multiply(num1, num2);

  // call print function to display results
  printResults(num1, num2, product);

  return 0;
}

int multiply(int num1, int num2) {
  return num1 * num2;
}

void printResults(int num1, int num2, int product) {
  printf("%d multiplied by %d equals %d\n", num1, num2, product);
}