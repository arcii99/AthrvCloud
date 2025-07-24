//FormAI DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
/* This program calculates the factorial of a positive integer using recursion */

#include <stdio.h>

int factorial(int n) {
  if (n == 0) { // base case
    return 1;
  } else { // recursive case
    return n * factorial(n-1);
  }
}

int main() {
  int num;
  printf("Please enter a positive integer to calculate its factorial: ");
  scanf("%d", &num);
  if (num < 0) {
    printf("Error: You entered a negative integer.");
  } else {
    int ans = factorial(num);
    printf("The factorial of %d is %d.", num, ans);
  }
  return 0;
}