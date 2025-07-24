//FormAI DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>

int main() {
  int num1, num2, sum, sub, mul, div, rem;
  
  printf("Enter two numbers: ");
  scanf("%d%d", &num1, &num2);
  
  sum = num1 + num2;
  sub = num1 - num2;
  mul = num1 * num2;
  div = num1 / num2;
  rem = num1 % num2;
  
  printf("\nThe sum of %d and %d is %d", num1, num2, sum);
  printf("\nThe difference of %d and %d is %d", num1, num2, sub);
  printf("\nThe product of %d and %d is %d", num1, num2, mul);
  printf("\nThe quotient when %d is divided by %d is %d", num1, num2, div);
  printf("\nThe remainder when %d is divided by %d is %d", num1, num2, rem);
  
  if(num1 > num2) {
    printf("\n%d is greater than %d", num1, num2);
  } else if(num1 < num2) {
    printf("\n%d is less than %d", num1, num2);
  } else {
    printf("\n%d is equal to %d", num1, num2);
  }
  
  return 0;
}