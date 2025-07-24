//FormAI DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
  int level;
  printf("Welcome to the Visionary Game!\n");
  printf("Choose your level (1-5): ");
  scanf("%d", &level);
  if (level < 1 || level > 5) {
    printf("Invalid level. Please choose a level between 1 and 5.\n");
    return 0;
  }

  // Initialize variables
  int score = 0;
  int remaining = level * 3 + 5;
  int guess;
  int answer = rand() % (level * 10) + 1;

  // Game loop
  while (remaining > 0) {
    printf("Guess a number between 1 and %d (remaining guesses: %d): ", level * 10, remaining);
    scanf("%d", &guess);
    if (guess < 1 || guess > level * 10) {
      printf("Invalid guess. Please guess a number between 1 and %d.\n", level * 10);
      continue;
    }

    // Compare guess and answer
    if (guess < answer) {
      printf("Too low!\n");
    } else if (guess > answer) {
      printf("Too high!\n");
    } else {
      printf("You got it!\n");
      score += level * 100;
      remaining = level * 3 + 5;
      answer = rand() % (level * 10) + 1;
    }

    // Update remaining guesses
    remaining--;
  }

  printf("Game over. Your score is %d.\n", score);
  return 0;
}