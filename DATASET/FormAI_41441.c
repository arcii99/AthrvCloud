//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

int divide(int a, int b) {
  if (b==0) {
    printf("Division by 0 error!\n");
    exit(0);
  } else {
    return a/b;
  }
}

int main() {
  int dividend, divisor, quotient;
  printf("Enter the dividend: ");
  scanf("%d", &dividend);
  printf("Enter the divisor: ");
  scanf("%d", &divisor);
  quotient = divide(dividend, divisor);
  printf("The quotient of %d and %d is %d\n", dividend, divisor, quotient);
  return 0;
}