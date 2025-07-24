//FormAI DATASET v1.0 Category: Recursive ; Style: inquisitive
#include <stdio.h>

int factorial(int n) {
  if (n == 0 || n == 1) { // base case
    return 1;
  }
  else { // recursive case
    return n * factorial(n-1);
  }
}

int main() {
  int number;
  printf("Enter a number to calculate its factorial: ");
  scanf("%d", &number);
  printf("%d! = %d", number, factorial(number));
  return 0;
}