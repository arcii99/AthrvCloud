//FormAI DATASET v1.0 Category: Random ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(){
  printf("Welcome to the randomizer game!\n");
  printf("Your job is to guess the random number I'm thinking of.\n\n");

  int correct_number = rand() % 100 + 1;
  int guessed_number, tries = 0;

  while(1){
    printf("Enter your guess (between 1-100): ");
    scanf("%d", &guessed_number);

    if(guessed_number == correct_number){
      printf("Congratulations! You guessed the correct number in %d tries.\n", tries);
      break;
    }else if(guessed_number > correct_number){
      printf("Too high! Try again.\n");
    }else{
      printf("Too low! Try again.\n");
    }
    tries++;
  }
  
  printf("Thanks for playing! If you want to play again, run the program again.\n");
  
  return 0;
}