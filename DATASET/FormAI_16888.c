//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>

int main() {
  int num1, num2, sum, prod;
  printf("Welcome to the Arithmetic Program!\n");
  printf("Please enter two numbers separated by a space:\n");
  scanf("%d %d", &num1, &num2);
  printf("Great choices! Let's do some math:\n");

  sum = num1 + num2;
  prod = num1 * num2;

  printf("The sum of %d and %d is: %d\n", num1, num2, sum);
  printf("The product of %d and %d is: %d\n", num1, num2, prod);

  if(num1 > num2){
    printf("%d is greater than %d\n", num1, num2);
  }
  
  if(num2 > num1){
    printf("%d is greater than %d\n", num2, num1);
  }

  printf("Now let's play with these numbers!\n");

  printf("%d incremented by 1 is: %d\n", num1, ++num1);

  printf("%d decremented by 1 is: %d\n", num2, --num2);

  if(num1 % 2 == 0){
    printf("%d is an even number\n", num1);
  }

  if(num2 % 2 == 1){
    printf("%d is an odd number\n", num2);
  }

  printf("Thanks for playing in the math playground! See you next time!\n");

  return 0;
}