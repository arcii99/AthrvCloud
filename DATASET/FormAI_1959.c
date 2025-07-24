//FormAI DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int player1_score = 0, player2_score = 0;
  int dice1, dice2;
  char choice;

  srand(time(NULL));

  printf("Welcome to C Table Game!\n");

  do {
    printf("Player 1, press Enter to roll the dice:");
    getchar();
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    printf("You have rolled %d and %d\n", dice1, dice2);
    player1_score += (dice1 + dice2);

    printf("Player 2, press Enter to roll the dice:");
    getchar();
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    printf("You have rolled %d and %d\n", dice1, dice2);
    player2_score += (dice1 + dice2);

    printf("Player 1 Score: %d\t Player 2 Score: %d\n", player1_score, player2_score);

    printf("Do you want to continue (Y/N)? ");
    scanf(" %c", &choice);
  } while(choice == 'Y' || choice == 'y');

  if(player1_score > player2_score)
    printf("Player 1 wins!\n");
  else if(player2_score > player1_score)
    printf("Player 2 wins!\n");
  else
    printf("It's a tie!\n");

  return 0;
}