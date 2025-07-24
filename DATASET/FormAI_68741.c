//FormAI DATASET v1.0 Category: Recursive ; Style: imaginative
#include <stdio.h>

// A function that returns a factorial of a number using recursion
int factorial(int n) {
  if (n == 1) { // Base case
    return 1;
  } else { // Recursive case
    return n * factorial(n-1);
  }
}

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  
  if (num < 0) { // Validation
    printf("Invalid input!");
  } else {
    int result = factorial(num);
    printf("The factorial of %d is %d", num, result);
  }
  
  return 0;
}