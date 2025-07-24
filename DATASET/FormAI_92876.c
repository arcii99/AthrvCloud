//FormAI DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 6
int roll_dice() {
  return (rand() % 6) + 1;
}

int main() {
  int player1_pos = 1; // Starting position of player 1
  int player2_pos = 1; // Starting position of player 2
  
  // Seed the random number generator using the current time
  srand(time(NULL));
  
  printf("Welcome to the C Table Game!\n");
  
  // Loop until one of the players reaches the end (position 100)
  while (player1_pos < 100 && player2_pos < 100) {
    int roll1 = roll_dice(); // Roll of player 1
    int roll2 = roll_dice(); // Roll of player 2
    
    printf("Player 1 rolled a %d! ", roll1);
    printf("Player 2 rolled a %d!\n", roll2);
    
    player1_pos += roll1; // Move player 1
    player2_pos += roll2; // Move player 2
    
    // Check if player 1 has landed on a ladder or snake
    switch (player1_pos) {
      case 4:
        player1_pos = 14;
        printf("Player 1 landed on a ladder! Climbing to position 14.\n");
        break;
      case 9:
        player1_pos = 31;
        printf("Player 1 landed on a ladder! Climbing to position 31.\n");
        break;
      case 17:
        player1_pos = 7;
        printf("Player 1 landed on a snake! Sliding down to position 7.\n");
        break;
      case 20:
        player1_pos = 38;
        printf("Player 1 landed on a ladder! Climbing to position 38.\n");
        break;
      case 28:
        player1_pos = 84;
        printf("Player 1 landed on a ladder! Climbing to position 84.\n");
        break;
      case 40:
        player1_pos = 59;
        printf("Player 1 landed on a ladder! Climbing to position 59.\n");
        break;
      case 51:
        player1_pos = 67;
        printf("Player 1 landed on a ladder! Climbing to position 67.\n");
        break;
      case 54:
        player1_pos = 34;
        printf("Player 1 landed on a snake! Sliding down to position 34.\n");
        break;
      case 62:
        player1_pos = 19;
        printf("Player 1 landed on a snake! Sliding down to position 19.\n");
        break;
      case 63:
        player1_pos = 81;
        printf("Player 1 landed on a ladder! Climbing to position 81.\n");
        break;
      case 64:
        player1_pos = 60;
        printf("Player 1 landed on a snake! Sliding down to position 60.\n");
        break;
      case 71:
        player1_pos = 91;
        printf("Player 1 landed on a ladder! Climbing to position 91.\n");
        break;
      case 87:
        player1_pos = 24;
        printf("Player 1 landed on a snake! Sliding down to position 24.\n");
        break;
      case 93:
        player1_pos = 73;
        printf("Player 1 landed on a snake! Sliding down to position 73.\n");
        break;
      case 95:
        player1_pos = 75;
        printf("Player 1 landed on a snake! Sliding down to position 75.\n");
        break;
      case 99:
        player1_pos = 78;
        printf("Player 1 landed on a snake! Sliding down to position 78.\n");
        break;
    }
    
    // Check if player 2 has landed on a ladder or snake
    switch (player2_pos) {
      case 4:
        player2_pos = 14;
        printf("Player 2 landed on a ladder! Climbing to position 14.\n");
        break;
      case 9:
        player2_pos = 31;
        printf("Player 2 landed on a ladder! Climbing to position 31.\n");
        break;
      case 17:
        player2_pos = 7;
        printf("Player 2 landed on a snake! Sliding down to position 7.\n");
        break;
      case 20:
        player2_pos = 38;
        printf("Player 2 landed on a ladder! Climbing to position 38.\n");
        break;
      case 28:
        player2_pos = 84;
        printf("Player 2 landed on a ladder! Climbing to position 84.\n");
        break;
      case 40:
        player2_pos = 59;
        printf("Player 2 landed on a ladder! Climbing to position 59.\n");
        break;
      case 51:
        player2_pos = 67;
        printf("Player 2 landed on a ladder! Climbing to position 67.\n");
        break;
      case 54:
        player2_pos = 34;
        printf("Player 2 landed on a snake! Sliding down to position 34.\n");
        break;
      case 62:
        player2_pos = 19;
        printf("Player 2 landed on a snake! Sliding down to position 19.\n");
        break;
      case 63:
        player2_pos = 81;
        printf("Player 2 landed on a ladder! Climbing to position 81.\n");
        break;
      case 64:
        player2_pos = 60;
        printf("Player 2 landed on a snake! Sliding down to position 60.\n");
        break;
      case 71:
        player2_pos = 91;
        printf("Player 2 landed on a ladder! Climbing to position 91.\n");
        break;
      case 87:
        player2_pos = 24;
        printf("Player 2 landed on a snake! Sliding down to position 24.\n");
        break;
      case 93:
        player2_pos = 73;
        printf("Player 2 landed on a snake! Sliding down to position 73.\n");
        break;
      case 95:
        player2_pos = 75;
        printf("Player 2 landed on a snake! Sliding down to position 75.\n");
        break;
      case 99:
        player2_pos = 78;
        printf("Player 2 landed on a snake! Sliding down to position 78.\n");
        break;
    }
    
    // Make sure the players don't go past position 100
    if (player1_pos > 100) {
      player1_pos = 100;
    }
    if (player2_pos > 100) {
      player2_pos = 100;
    }
    
    // Print the positions of both players
    printf("Player 1 is now at position %d. ", player1_pos);
    printf("Player 2 is now at position %d.\n", player2_pos);
  }
  
  // Check which player won
  if (player1_pos >= 100) {
    printf("Player 1 won the game!\n");
  }
  else {
    printf("Player 2 won the game!\n");
  }
  
  return 0;
}