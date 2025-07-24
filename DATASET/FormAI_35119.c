//FormAI DATASET v1.0 Category: Educational ; Style: excited
#include <stdio.h>

int main() {
  int num, count = 1;
  printf("Let's play a game! Guess the number I am thinking of between 1 and 10!\n");
  scanf("%d", &num);
  while (num != 4) {
    printf("Nope, try again! You have %d guesses left.\n", 5 - count);
    count++;
    if (count > 5) {
      printf("Sorry, you ran out of guesses. Better luck next time!\n");
      return 0;
    }
    scanf("%d", &num);
  }
  printf("Congratulations! You guessed the number in %d tries!\n", count);
  printf("Now let's play again, but with a twist!\n");
  printf("This time, I will think of a number between 1 and 100, and you have to guess it in 10 tries.\n");
  int rand_num = (rand() % 100) + 1;
  count = 1;
  while (num != rand_num) {
    printf("Nope, try again! You have %d guesses left.\n", 10 - count);
    count++;
    if (count > 10) {
      printf("Sorry, you ran out of guesses. The number was %d. Better luck next time!\n", rand_num);
      return 0;
    }
    scanf("%d", &num);
    if (num < rand_num) {
      printf("Your guess was too low! Guess higher.\n");
    }
    else if (num > rand_num) {
      printf("Your guess was too high! Guess lower.\n");
    }
  }
  printf("Congratulations! You guessed the number in %d tries!\n", count);
  printf("Thanks for playing!\n");
  return 0;
}