//FormAI DATASET v1.0 Category: Random ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int mystery_num, guess;
   int num_guesses = 0;
   srand(time(NULL));
   mystery_num = rand() % 100 + 1;  // Randomly selects a number between 1 and 100
   
   printf("Welcome to the Mystery Number Game!\n");
   printf("I have thought of a number between 1 and 100. Can you guess what it is?\n");
   
   do {
      printf("Enter your guess: ");
      scanf("%d", &guess);
      
      if (guess < mystery_num) {
         printf("Too low! Guess again.\n");
      } else if (guess > mystery_num) {
         printf("Too high! Guess again.\n");
      } else {
         printf("Congratulations! You guessed the number in %d tries!\n", num_guesses);
      }
      num_guesses++;  // Increment number of guesses
   } while (guess != mystery_num);
   
   return 0;
}