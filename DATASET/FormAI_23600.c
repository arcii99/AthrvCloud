//FormAI DATASET v1.0 Category: Game ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  srand(time(NULL)); //Seed for the random number generator
  int user_input;
  int random_number = rand() % 100 + 1; //Generate a random number between 1 and 100
  int num_of_guesses = 0; //Initialize the number of guesses to 0
  printf("Welcome to the Number Guessing Game!\n\n");
  printf("I am thinking of a number between 1 and 100.\n");
  printf("Try to guess my number by entering a number between 1 and 100.\n");

  do {
    printf("\nEnter your guess: ");
    scanf("%d", &user_input); //Get user input
    num_of_guesses++; //Increment the number of guesses
    if(user_input < random_number) {
      printf("Too low!\n");
    }
    else if(user_input > random_number) {
      printf("Too high!\n");
    }
    else {
      printf("\nCongratulations! You guessed my number in %d guesses!\n", num_of_guesses);
    }
  } while(user_input != random_number);

  return 0;
}