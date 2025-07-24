//FormAI DATASET v1.0 Category: Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  char answer;
  int num, guess, tries = 0;
  
  srand(time(NULL));
  num = rand() % 100 + 1;
  
  printf("Welcome to the guessing game!\n");
  printf("I'm thinking of a number between 1 and 100.\n");
  
  do {
    printf("Guess the number: ");
    scanf("%d", &guess);
    tries++;
    if (guess > num) {
      printf("Too high! Try again.\n");
    } else if (guess < num) {
      printf("Too low! Try again.\n");
    } else {
      printf("Congratulations, you got it in %d tries!\n", tries);
    }
    
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &answer);
    if (answer == 'y') {
      num = rand() % 100 + 1;
      tries = 0;
    }
  } while (answer == 'y');
  
  return 0;
}