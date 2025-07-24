//FormAI DATASET v1.0 Category: Recursive ; Style: beginner-friendly
#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n-1);
  }
}

int main() {
  int num;
  printf("Enter a positive integer to find its factorial: ");
  scanf("%d", &num);

  if (num < 0) {
    printf("Error: factorial of negative number does not exist.");
  } else {
    printf("The factorial of %d is %d", num, factorial(num));
  }

  return 0;
}