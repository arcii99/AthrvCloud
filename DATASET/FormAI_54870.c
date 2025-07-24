//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int num, guess, attempts=0;
  srand(time(0)); //seed for random number generator
  num = rand() % 100 + 1; //generates random number between 1 and 100

  printf("Welcome to the Number Guessing Game!\n");
  printf("The computer has generated a number between 1 and 100.\n");
  printf("Guess the number! You have 5 attempts.\n");

  //loop to allow user to guess the number five times
  while(attempts<5) { 
    scanf("%d", &guess); //take input from user
    attempts++; //increment attempts counter

    if(guess == num) { //if number guessed correctly
      printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
      break; //exit loop
    }
    else if(guess > num) { //if guess is greater than generated number
      printf("Too high! Guess again. ");
    }
    else { //if guess is lower than generated number
      printf("Too low! Guess again. ");
    }

    //if user has used all five attempts and not guessed correctly
    if(attempts == 5) {
      printf("Sorry, you did not guess the number. The answer was %d.\n", num);
    }
  }

  return 0;
}