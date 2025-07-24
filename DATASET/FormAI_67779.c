//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

int main() {

  int num1, num2, sum, diff, prod, quo, rem;

  printf("Peace be upon you! I will perform arithmetic calculations for you today!\n");
  
  printf("Please enter the first number: ");
  scanf("%d", &num1);

  printf("Thank you. Now please enter the second number: ");
  scanf("%d", &num2);

  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;

  if(num2 != 0) {
      quo = num1 / num2;
      rem = num1 % num2;
  }

  printf("\nAh! Amazingly, the sum of %d and %d is %d.\n", num1, num2, sum);
  printf("Did you know that %d minus %d gives %d?\n", num1, num2, diff);
  printf("Multiplying %d and %d equals %d.\n", num1, num2, prod);

  if(num2 != 0) {
      printf("And dividing %d by %d gives %d with remainder %d.\n", num1, num2, quo, rem);
  }
  else {
      printf("Oops! The second number is 0, division is not possible.\n");
  }

  printf("Thank you for using my program today. May peace be with you!\n");

  return 0;
}