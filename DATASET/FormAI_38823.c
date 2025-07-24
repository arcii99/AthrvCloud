//FormAI DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>

int factorial(int n) {
  if(n == 0) {
    return 1; // 0! is 1 by definition
  } else {
    return n * factorial(n-1);
  }
}

int main() {
  int num;
  printf("Enter a number to find its factorial: ");
  scanf("%d", &num);
  
  if(num < 0) {
    printf("Factorial cannot be found for negative numbers!"); // Invalid input
  } else {
    printf("Factorial of %d is %d.", num, factorial(num));
  }
  
  return 0;
}