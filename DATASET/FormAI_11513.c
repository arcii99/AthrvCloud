//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate a random number
int generateRandomNum(int max) {
  int num;
  srand(time(0));
  num = rand() % max;
  return num;
}

int main() {
   int secretNum, guessNum, numTries = 0;
   secretNum = generateRandomNum(100);
   printf("Welcome to the Guess the Number Game!\n");
   printf("You have 10 tries to guess the secret number between 0 and 100.\n");
   do {
      printf("Enter your guess: ");
      scanf("%d", &guessNum);
      numTries++; //increment the number of tries
      if (guessNum > secretNum) {
         printf("Too high. Try again!\n");
      } else if (guessNum < secretNum) {
         printf("Too low. Try again!\n");
      } else {
         printf("Congratulations! You guessed the secret number in %d tries.\n", numTries);
      }
   } while (guessNum != secretNum && numTries < 10); //continue until the secret number is guessed or 10 tries have been made
   if (numTries >= 10) {
      printf("Game over! You have failed to guess the secret number in 10 tries.\nThe secret number was %d.\n", secretNum);
   }
   return 0;
}