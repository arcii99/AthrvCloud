//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

int main() {
  printf("Take a deep breath and let's do some peaceful arithmetic!\n");

  int num1, num2;

  printf("Please enter a number: ");
  scanf("%d", &num1);

  printf("Thank you! Now, please enter another number: ");
  scanf("%d", &num2);

  int sum = num1 + num2;
  printf("The sum of %d and %d is: %d\n", num1, num2, sum);

  int difference = num1 - num2;
  printf("The difference of %d and %d is: %d\n", num1, num2, difference);

  int product = num1 * num2;
  printf("The product of %d and %d is: %d\n", num1, num2, product);

  if(num2 != 0) {
    float quotient = (float)num1 / (float)num2;
    printf("The quotient of %d divided by %d is: %f\n", num1, num2, quotient);
  } else {
    printf("Oops! Looks like we cannot divide by zero.\n");
  }

  return 0;
}