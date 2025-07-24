//FormAI DATASET v1.0 Category: Game ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  srand(time(NULL));   // to initialize random seed

  printf("Welcome to Guess the Number Game!\n");
  printf("I'm thinking of a number between 1 and 100.\n");
  printf("Can you guess what it is?\n");

  int num = rand() % 100 + 1;   // generating the random number
  int guess, count = 0;

  do{
    printf("Enter your guess: ");
    scanf("%d", &guess);

    if(guess>num)
      printf("Too high. Try again.\n");
    else if(guess<num)
      printf("Too low. Try again.\n");

    count++;
  }while(guess!=num);

  printf("Congratulations! You guessed the number %d in %d guesses!\n", num, count);

  return 0;
}