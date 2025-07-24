//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>

// function to check if a number is positive
int isPositive(int num) {
  if(num < 0) {
    return 0;  // return false
  }
  return 1;  // return true
}

// function to calculate factorial of a number
int factorial(int num) {
  if(num < 0) {
    printf("Error: Factorial can not be calculated for a negative number!\n");
    return -1;  // return error code
  }
  int fact = 1;
  for(int i=1; i<=num; i++) {
    fact *= i;
  }
  return fact;
}

int main() {
  int n, pos;
  printf("Enter a number: ");
  scanf("%d", &n);
  // handle Error if input is negative
  if(!isPositive(n)) {
    printf("Error: Input can not be negative!\n");
    return 1;  // return error code
  }
  // handle Error if factorial can not be calcualted
  pos = factorial(n);
  if(pos == -1) {
    return 1;  // return error code
  }
  printf("Factorial of %d = %d\n", n, pos);
  return 0;
}