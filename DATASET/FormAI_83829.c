//FormAI DATASET v1.0 Category: Funny ; Style: synchronous
#include <stdio.h>

int main() {
  printf("Welcome to the Great Number Game!\n");
  printf("In this game, you will guess a number between 1 and 100.\n");
  int correct = rand() % 100 + 1;
  int guess = -1;
  int num_guesses = 0;
  while(guess != correct) {
    printf("Guess the number: ");
    scanf("%d", &guess);
    num_guesses++;
    if(guess < correct)
      printf("Too low, try again.\n");
    else if(guess > correct)
      printf("Too high, try again.\n");
  }
  printf("Congratulations, you guessed the correct number in %d guesses!\n", num_guesses);
  return 0;
}