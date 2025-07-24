//FormAI DATASET v1.0 Category: Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int guess, answer;
  char playAgain;
  
  srand(time(NULL));
  
  do {
    answer = rand() % 100 + 1;
    printf("I'm thinking of a number between 1 and 100.\n");
    
    do {
      printf("Guess what number I'm thinking of: ");
      scanf("%d", &guess);
      
      if (guess < answer) {
        printf("Too low. Guess again.\n");
      } else if (guess > answer) {
        printf("Too high. Guess again.\n");
      } else {
        printf("Congratulations, you guessed it!\n");
      }
    } while (guess != answer);
    
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);
    printf("\n");
  } while (playAgain == 'y');
  
  printf("Thanks for playing!\n");
  
  return 0;
}