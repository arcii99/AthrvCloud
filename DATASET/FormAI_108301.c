//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char choice = 'y';
  printf("Welcome to the C Table Game!\n");
  do {
    srand(time(NULL));
    int number = rand() % 1000 + 1;
    int count = 0;
    int guess;
    do {
      printf("Guess the number (between 1 and 1000): ");
      scanf("%d", &guess);
      count++;
      if (guess < number) {
        printf("Too low. Guess again.\n");
      } else if (guess > number) {
        printf("Too high. Guess again.\n");
      } else {
        printf("Congratulations! You guessed the number in %d attempts.\n", count);
      }
    } while (guess != number);

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &choice);
  } while (choice == 'y');
  return 0;
}