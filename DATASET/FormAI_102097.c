//FormAI DATASET v1.0 Category: Game ; Style: detailed
#include<stdio.h>
#include<stdlib.h> // for rand() and srand()
#include<time.h> // for time()

int main() {
   int number, guess, attempts = 0;
   srand(time(0)); // using time as seed for random number generation
   number = rand() % 100 + 1; // generating a random number between 1-100
   printf("Welcome to the guessing game!\n");
   printf("I have generated a random number between 1-100. Can you guess what it is?\n");

   do {
      printf("Enter your guess: ");
      scanf("%d", &guess);
      attempts++; // counting the number of attempts

      if(guess > number) {
         printf("Too high. Try again.\n\n");
      } else if(guess < number) {
         printf("Too low. Try again.\n\n");
      } else {
         printf("Congratulations! You guessed the number in %d attempts!\n", attempts);
      }
   } while(guess != number);

   return 0;
}