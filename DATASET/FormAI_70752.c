//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h> 

int main() {
  int num1, num2, sum, diff, product, quotient;

  printf("Hey there, I'm a funny arithmetic program! Let's do some math!\n");
  
  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  sum = num1 + num2;
  diff = (num1 > num2) ? num1 - num2 : num2 - num1;
  product = num1 * num2;
  quotient = (num2 != 0) ? num1 / num2 : -1;

  printf("\nOkay, here's what I got:\n");
  printf("The sum of %d and %d is %d.\n", num1, num2, sum);
  printf("The difference between %d and %d is %d.\n", num1, num2, diff);
  printf("%d multiplied by %d is %d.\n", num1, num2, product);

  if (quotient == -1) {
    printf("Oopsie, looks like you tried to divide by 0. That's a big no-no, buddy!\n");
  } else {
    printf("%d divided by %d is %d.\n", num1, num2, quotient);
  }

  printf("\nThanks for playing along with me! Keep on calculating!\n");

  return 0;
}