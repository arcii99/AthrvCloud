//FormAI DATASET v1.0 Category: Recursive ; Style: systematic
#include <stdio.h>

// function to calculate factorial using recursion
int factorial(int n) {
  if(n == 0)
    return 1;
  else
    return n * factorial(n-1);
}

// function to calculate fibonacci series using recursion
int fibonacci(int n) {
  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;
  else
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
  int n, choice;
  printf("Please select the operation you want to perform:\n1. Factorial\n2. Fibonacci Series\nEnter your choice: ");
  scanf("%d", &choice);
  printf("Enter the number: ");
  scanf("%d", &n);

  if(choice == 1) {
    int fact = factorial(n);
    printf("Factorial of %d is: %d", n, fact);
  } else if(choice == 2) {
    printf("Fibonacci series upto %d terms is: \n", n);
    for(int i=0; i<n; i++) {
      printf("%d ", fibonacci(i));
    }
  } else {
    printf("Invalid choice!");
  }

  return 0;
}