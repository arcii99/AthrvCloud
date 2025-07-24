//FormAI DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>

int main() {
  int num1, num2, result;
  
  printf("I am curious to see what you can do with arithmetic. Give me two numbers to play with: ");
  scanf("%d%d", &num1, &num2);

  printf("\nLet's see...\n");

  printf("%d + %d is %d\n", num1, num2, num1 + num2);
  printf("%d - %d is %d\n", num1, num2, num1 - num2);
  printf("%d * %d is %d\n", num1, num2, num1 * num2);
  
  if(num2 == 0) {
    printf("But I can't divide by zero! Something went wrong here...\n");
  } else {
    result = num1 / num2;
    printf("%d / %d is %d with a remainder of %d\n", num1, num2, result, num1 % num2);
  }

  printf("\nThat was fun! Shall we try again? (Y/N): ");
  
  char playAgain;
  scanf(" %c", &playAgain);

  if(playAgain == 'Y' || playAgain == 'y') {
    main();
  } else {
    printf("\nThanks for playing! Goodbye :)\n");
  }

  return 0;
}