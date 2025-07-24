//FormAI DATASET v1.0 Category: Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, num, num_of_guesses = 0;
  srand(time(0));
  num = rand() % 100 + 1;
  printf("Guess the number between 1 and 100\n");
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    num_of_guesses++;
    if (guess > num) {
      printf("Too high!\n");
    }
    else if (guess < num) {
      printf("Too low!\n");
    }
    else {
      printf("Congrats! You guessed the number in %d tries.\n", num_of_guesses);
    }
  } while (guess != num);
  return 0;
}