//FormAI DATASET v1.0 Category: Scientific ; Style: introspective
#include <stdio.h>

int main() {
  int num1, num2;
  printf("Enter two numbers separated by a space: ");
  scanf("%d%d", &num1, &num2);

  printf("The sum of %d and %d is %d.\n", num1, num2, num1 + num2);
  printf("The difference of %d and %d is %d.\n", num1, num2, num1 - num2);
  printf("The product of %d and %d is %d.\n", num1, num2, num1 * num2);
  if (num2 != 0) {
    printf("The quotient of %d and %d is %d with a remainder of %d.\n", 
           num1, num2, num1 / num2, num1 % num2);
  } else {
    printf("The second number cannot be 0 for division.\n");
  }

  int max = (num1 > num2) ? num1 : num2;
  printf("The maximum number is %d.\n", max);

  int min = (num1 < num2) ? num1 : num2;
  printf("The minimum number is %d.\n", min);

  return 0;
}