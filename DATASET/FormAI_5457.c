//FormAI DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>

// function to compute factorial of a number
int factorial(int n) {
  if (n == 1 || n == 0) // base cases
    return 1;
  else
    return n * factorial(n - 1); // recursive call
}

// function to compute fibonacci of a number
int fibonacci(int n) {
  if (n == 0) // base cases
    return 0;
  else if (n == 1 || n == 2)
    return 1; 
  else
    return fibonacci(n - 1) + fibonacci(n - 2); // recursive call
}

int main() {

  // take user input for which function to call and which number to compute
  int choice, num;
  printf("Enter 1 to compute factorial or 2 to compute fibonacci: ");
  scanf("%d", &choice);
  printf("Enter the number to compute: ");
  scanf("%d", &num);

  // call the appropriate function and print output
  if (choice == 1)
    printf("Factorial of %d is %d", num, factorial(num));
  else if (choice == 2)
    printf("Fibonacci of %d is %d", num, fibonacci(num));
  else
    printf("Invalid choice");

  return 0;
}