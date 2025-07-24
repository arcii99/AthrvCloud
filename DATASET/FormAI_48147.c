//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, num, tries = 0;
  srand(time(0));
  num = rand() % 100 + 1;

  printf("\n\n\nWow, let's play a game!\n");
  printf("I'm thinking of a number between 1 and 100.\n");
  printf("Can you guess what it is?\n\n\n");

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    tries++;

    if (guess > num) {
      printf("Wowser! The number is smaller than %d.\n", guess);
    } else if (guess < num) {
      printf("Whoa! The number is larger than %d.\n", guess);
    } else {
      printf("\n\nCongratulations! You've got it right in %d tries.\n\n\n", tries);
    }
  } while (guess != num);

  printf("Thanks for playing. Have a great day!\n\n");

  return 0;
}