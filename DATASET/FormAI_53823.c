//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
  if (n == 1) {
    printf("Wait, what?! n is equal to 1?! That's unexpected...\n");
    return 1;
  }
  printf("Calculating factorial of %d...\n", n);
  int result = n * factorial(n-1);
  printf("Factorial of %d is %d? Woah, I did not see that coming!\n", n, result);
  return result;
}

int main() {
  printf("Welcome to the surprising factorial calculator!\n");
  int input;
  printf("Please enter a number to calculate its factorial: ");
  scanf("%d", &input);
  int result = factorial(input);
  printf("\nThe unexpected result is: %d\n", result);
  return 0;
}