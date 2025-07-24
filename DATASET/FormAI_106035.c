//FormAI DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>

int main() {

  // Let's ask the user for some values

  int num1, num2;
  printf("Can you give me a number?\n");
  scanf("%d", &num1);
  printf("How about another one?\n");
  scanf("%d", &num2);

  // Now, let's add them together

  int sum = num1 + num2;

  // What's the result?

  printf("The sum of %d and %d is %d.\n", num1, num2, sum);

  // Let's get a little more complicated, shall we?

  int mult = num1 * num2;
  int div = num1 / num2;

  printf("%d multiplied by %d is %d.\n", num1, num2, mult);
  printf("%d divided by %d is %d with a remainder of %d.\n", num1, num2, div, num1 % num2);

  // How about some comparisons?

  if(num1 == num2) {
    printf("%d is equal to %d.\n", num1, num2);
  } else if(num1 > num2) {
    printf("%d is greater than %d.\n", num1, num2);
  } else {
    printf("%d is less than %d.\n", num1, num2);
  }

  // Let's use some functions to calculate the power and square root

  #include <math.h>
  double power = pow(num1, num2);
  double sqrt1 = sqrt(num1);
  double sqrt2 = sqrt(num2);

  printf("%d to the power of %d is %lf.\n", num1, num2, power);
  printf("The square root of %d is %lf.\n", num1, sqrt1);
  printf("The square root of %d is %lf.\n", num2, sqrt2);

  // Hopefully, that's enough to keep your brain buzzing for a while!

  return 0;
}