//FormAI DATASET v1.0 Category: Scientific ; Style: introspective
#include <stdio.h>

/* This program calculates the factorial of a number using recursion. 
   It is introspective in that it displays each calculation being performed */ 

int factorial(int n) {

  int result;

  if (n == 0) {
    return 1;
  } else {
    result = n * factorial(n-1);
    printf("Calculating %d! = %d x %d! = %d\n", n, n, n-1, result);
    return result;
  }
}

int main() {

  int num;
  printf("Enter a positive integer: ");
  scanf("%d", &num);

  printf("Factorial of %d is %d\n", num, factorial(num));

  return 0;
}