//FormAI DATASET v1.0 Category: Recursive ; Style: shocked
#include<stdio.h>

int factorial(int n) {
  if (n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}

int main() {
  int num;
  printf("Enter a number to find the factorial of: ");
  scanf("%d", &num);
  if (num < 0) {
    printf("Negative numbers don't have factorial values.\n");
    return 1;
  } else {
    int result = factorial(num);
    printf("The factorial of %d is: %d\n", num, result);
    return 0;
  }
}