//FormAI DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

int factorial(int n);

int main() {
  int num;
  printf("Enter an integer: ");
  scanf("%d", &num);
  int result = factorial(num);
  printf("%d! = %d\n", num, result);
  return 0;
}

int factorial(int n) {
  if(n < 0) {
    printf("Error: Factorial of a negative number doesn't exist\n");
    exit(1);
  } else if (n ==0) {
    return 1;
  } else {
    return n*factorial(n-1);
  }
}