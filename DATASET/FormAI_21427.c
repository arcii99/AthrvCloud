//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include <stdio.h>

int main() {
  printf("Surprise! I created a guessing game.\n");
  
  int secret_number = 7;
  int user_guess;
  int num_guesses = 0;
  
  while (user_guess != secret_number) {
    printf("Guess a number between 1 and 10: ");
    scanf("%d", &user_guess);
    num_guesses++;
    
    if(user_guess < secret_number) {
      printf("Too low!\n");
    }
    else if(user_guess > secret_number) {
      printf("Too high!\n");
    }
    else {
      printf("Congratulations! You guessed the secret number in %d guesses.\n", num_guesses);
    }
    
    if(num_guesses == 3) {
      printf("Wow, you really suck at this game. Better luck next time!\n");
      return 0;
    }
  }
  
  return 0;
}