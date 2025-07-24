//FormAI DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>

// Grateful Arithmetic Program

int main() {
  int num1, num2, sum, prod, diff;

  printf("Greetings! Thank you for using this program!\n");
  printf("Please enter two numbers: \n");
  scanf("%d %d", &num1, &num2);

  sum = num1 + num2;
  printf("The sum of your numbers is %d.\n", sum);

  prod = num1 * num2;
  printf("The product of your numbers is %d.\n", prod);

  diff = num1 - num2;
  if (diff < 0) {
    printf("The difference between your numbers is negative. But don't worry, stay positive!\n");
  } else {
    printf("The difference between your numbers is %d. Isn't that great?\n", diff);
  }

  printf("Thank you for using this program. Have a wonderful day!\n");

  return 0;
}