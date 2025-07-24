//FormAI DATASET v1.0 Category: Scientific ; Style: minimalist
#include <stdio.h>

int factorial(int n) {
  if(n == 0)
    return 1;
  else
    return n * factorial(n-1);
}

int main() {
  int num;

  printf("Enter a number to find its factorial: ");
  scanf("%d", &num);

  if(num < 0)
    printf("Error! Factorial of negative number doesn't exist.");
  else
    printf("Factorial of %d is %d", num, factorial(num));

  return 0;
}