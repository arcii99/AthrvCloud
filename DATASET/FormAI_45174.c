//FormAI DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  //initialize variables
  int guess, num, count = 0;
  srand(time(NULL));
  num = rand() % 100 + 1;

  printf("Welcome to the Guessing Game!\n");
  printf("I'm thinking of a number between 1-100\n");
  
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    count++;

    if(guess > num){
      printf("Too high! Guess again.\n");
    }
    else if(guess < num){
      printf("Too low! Guess again.\n");
    }
    else{
      printf("Congratulations! You guessed the number in %d tries!\n", count);
    }

  } while(guess != num);
  
  return 0;
}