//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, answer, num_guesses = 0;
  srand(time(NULL));
  answer = rand() % 101;
  printf("I am thinking of a number between 0 and 100. Can you guess the number?\n");
  
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    num_guesses++;

    if(guess < answer) {
      printf("Your guess is too low. Try again.\n");
    } else if(guess > answer) {
      printf("Your guess is too high. Try again.\n");
    } else {
      printf("Congratulations! You got it in %d guesses.\n", num_guesses);
    }
    
  } while(guess != answer);
  
  return 0;
}