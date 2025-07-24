//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, number, count = 0;
  srand(time(0));
  number = rand() % 100 + 1;
  printf("Welcome to the Guessing Game!\n");
  printf("You have to guess a number between 1 and 100.\n");
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    count++;
    if (guess > number) {
      printf("Lower number please!\n");
    } else if (guess < number) {
      printf("Higher number please!\n");
    } else {
      printf("Congratulations! You guessed the number in %d attempts.\n", count);
      break;
    }
  } while (1);
  return 0;
}