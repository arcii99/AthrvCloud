//FormAI DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Sherlock Holmes Memory Game!\n");
  printf("You will be shown a sequence of characters. Remember the sequence and repeat it back correctly to win.\n\n");

  srand(time(NULL));

  char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int sequence[10];
  int i, j, guess;

  for (i = 0; i < 10; i++) {
    sequence[i] = rand() % 26;
  }

  printf("Pay close attention to this sequence:\n");

  for (i = 0; i < 10; i++) {
    printf("%c ", alphabet[sequence[i]]);
  }

  printf("\n\nRepeat the sequence back using numbers 0-25 (i.e. 0 = A, 1 = B, etc.):\n");

  for (i = 0; i < 10; i++) {
    scanf("%d", &guess);
    if (guess == sequence[i]) {
      printf("Correct! Next character:\n");
    } else {
      printf("Incorrect! The correct answer was %c.\n", alphabet[sequence[i]]);
      printf("You lost the game. Better luck next time!\n");
      return 0;
    }
  }

  printf("Congratulations, you won the Sherlock Holmes Memory Game!\n");

  return 0;
}