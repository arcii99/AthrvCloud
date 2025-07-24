//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int guess, num, tries=5;
  srand(time(NULL));
  num = rand() % 100 + 1; // generating random number between 1 to 100
  
  printf("\nWelcome to the Number Guessing Game!\n");
  printf("You have 5 attempts to guess a number between 1 and 100.\n");
  printf("Let's begin!\n\n");

  while(tries > 0){ // loop to give user 5 attempts to guess
    printf("You have %d attempts remaining.\n", tries);
    printf("Guess the number: ");
    scanf("%d", &guess);
    
    if(guess == num){
      printf("\nCongratulations! You have guessed the number %d correctly!\n", num);
      return 0; // program termination if user guessed correctly
    }
    
    else if(guess < num){
      tries--;
      printf("The number is higher than %d. Try again.\n\n", guess);
    }
    
    else{
      tries--;
      printf("The number is lower than %d. Try again.\n\n", guess);
    }
    
  }
  
  printf("Oops! You have exhausted all your attempts..\n");
  printf("The number was %d. Better luck next time!\n", num);
  return 0; // program termination if user exhausted all attempts
  
}