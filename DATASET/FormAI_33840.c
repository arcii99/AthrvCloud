//FormAI DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the wackiest arithmetic program you've ever seen!\n\n");

  printf("Today's challenge: Guess the outcome of an addition problem between randomly generated numbers!\n\n");

  printf("Let's begin...\n");

  int num1, num2, result, guess;

  srand(time(NULL)); // seed for random number generation

  num1 = rand() % 100; // generate a random number between 0 and 99
  num2 = rand() % 100;

  result = num1 + num2;

  printf("The first number is %d.\n", num1);
  printf("The second number is %d.\n", num2);

  printf("\nTime to take a guess...what do you think %d + %d equals?\n", num1, num2);

  scanf("%d", &guess);

  if (guess == result) {
    printf("\nCongratulations! You're a math genius!\n\n");
  } else {
    printf("\nSorry, but the correct answer is %d. Better luck next time!\n\n");
  }

  printf("Thanks for playing!\n");

  return 0;
}