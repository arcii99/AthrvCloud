//FormAI DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); //seed the random number generator

  int player_score = 0;
  int computer_score = 0;

  printf("Welcome to the C Table Game!\n");

  printf("You will play against the computer. The goal is to score as close to 21 as possible without going over.\n");

  //game loop
  while(1) {
    printf("\nYour score: %d\n", player_score);
    printf("Computer score: %d\n\n", computer_score);

    //player's turn
    int player_roll = rand() % 11 + 1; //roll a random number between 1 and 11
    printf("Press enter to roll...\n");
    getchar(); //wait for user to press enter
    printf("You rolled a %d\n", player_roll);
    player_score += player_roll;

    if(player_score > 21) {
      printf("You went over 21! You lose.\n");
      break;
    }

    //computer's turn
    int computer_roll = rand() % 11 + 1;
    printf("The computer rolled a %d\n", computer_roll);
    computer_score += computer_roll;

    if(computer_score > 21) {
      printf("The computer went over 21! You win.\n");
      break;
    }

    //determine the winner
    if(player_score == 21 || computer_score == 21 || (player_score > computer_score && player_score <= 21)) {
      printf("Congratulations, you win!\n");
      break;
    }
    else if(computer_score > player_score && computer_score <= 21) {
      printf("Sorry, you lose.\n");
      break;
    }
  }

  return 0; //end the program
}