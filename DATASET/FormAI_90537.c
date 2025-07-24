//FormAI DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to roll the dice
int rollDice() {
  int roll = rand() % 6 + 1; //random number from 1-6
  return roll;
}

//Function to perform the player's turn
int playerTurn(int *playerScore) {
  int turnScore = 0;
  int roll;
  char choice = 'r';

  printf("=====PLAYER TURN=====\n");

  while(choice != 'h') {
    roll = rollDice();

    printf("You rolled a %d\n", roll);
    if(roll == 1) {
      printf("You rolled a 1! Turn over.\n");
      return 0;
    }

    turnScore += roll;
    printf("Turn score: %d\n", turnScore);

    printf("Enter 'h' to hold or 'r' to roll again: ");
    scanf(" %c", &choice);
  }

  //Add turn score to player's total score
  *playerScore += turnScore;

  printf("Total score: %d\n", *playerScore);

  return 1;
}

//Function to perform the computer's turn
int computerTurn(int *computerScore) {
  int turnScore = 0;
  int roll;

  printf("=====COMPUTER TURN=====\n");

  while(turnScore < 20) {
    roll = rollDice();

    printf("Computer rolled a %d\n", roll);
    if(roll == 1) {
      printf("Computer rolled a 1! Turn over.\n");
      return 0;
    }

    turnScore += roll;
    printf("Turn score: %d\n", turnScore);
  }

  //Add turn score to computer's total score
  *computerScore += turnScore;

  printf("Total score: %d\n", *computerScore);

  return 1;
}

//Function to check if a player has won
int checkWin(int playerScore, int computerScore) {
  if(playerScore >= 100) {
    printf("You win with a total score of %d!\n", playerScore);
    return 1;
  } else if(computerScore >= 100) {
    printf("Computer wins with a total score of %d!\n", computerScore);
    return 1;
  }

  return 0;
}

int main() {
  int playerScore = 0;
  int computerScore = 0;
  int win = 0;

  //Seed random number generator
  srand(time(NULL));

  printf("=====WELCOME TO THE GAME OF PIG!=====\n\n");

  while(!win) {
    printf("Player score: %d\n", playerScore);
    printf("Computer score: %d\n", computerScore);

    if(playerTurn(&playerScore)) {
      win = checkWin(playerScore, computerScore);
      if(win) break;
      if(computerTurn(&computerScore)) {
        win = checkWin(playerScore, computerScore);
      }
    }

    printf("\n");
  }

  return 0;
}