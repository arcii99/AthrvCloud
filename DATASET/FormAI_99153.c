//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  Bingo Simulator Example Program in C

  This program simulates a bingo game where players
  randomly get numbers and match them on their bingo
  card until they get a complete line to win.

  Created by [Your Name]
*/

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Define the number of players and bingo card size
  const int NUM_PLAYERS = 5;
  const int CARD_SIZE = 5;

  // Define the bingo card
  int bingoCard[NUM_PLAYERS][CARD_SIZE * CARD_SIZE];

  // Initialize the bingo card with random numbers
  for (int i = 0; i < NUM_PLAYERS; i++) {
    for (int j = 0; j < CARD_SIZE * CARD_SIZE; j++) {
      bingoCard[i][j] = rand() % 75 + 1;
    }
  }

  // Print the bingo card
  printf("Bingo Card:\n");
  for (int i = 0; i < NUM_PLAYERS; i++) {
    printf("Player %d: ", i + 1);
    for (int j = 0; j < CARD_SIZE * CARD_SIZE; j++) {
      printf("%d ", bingoCard[i][j]);
      if ((j + 1) % CARD_SIZE == 0) printf("\n           ");
    }
    printf("\n");
  }
  printf("\n");

  // Define the bingo numbers
  int bingoNumbers[75];
  for (int i = 0; i < 75; i++) {
    bingoNumbers[i] = i + 1;
  }

  // Play the game until someone wins
  int winner = -1;
  int numTurns = 0;
  while (winner == -1) {
    // Pick a random number
    int bingoNumber = bingoNumbers[rand() % 75];

    // Mark the number on each player's card
    for (int i = 0; i < NUM_PLAYERS; i++) {
      for (int j = 0; j < CARD_SIZE * CARD_SIZE; j++) {
        if (bingoCard[i][j] == bingoNumber) {
          bingoCard[i][j] = 0;  // Mark the number as matched
        }
      }
    }

    // Check if any player has a complete line
    for (int i = 0; i < NUM_PLAYERS; i++) {
      // Check rows
      for (int j = 0; j < CARD_SIZE; j++) {
        int rowMatched = 1;
        for (int k = 0; k < CARD_SIZE; k++) {
          if (bingoCard[i][j * CARD_SIZE + k] != 0) {
            rowMatched = 0;
            break;
          }
        }
        if (rowMatched) {
          winner = i;
          break;
        }
      }
      if (winner != -1) break;

      // Check columns
      for (int j = 0; j < CARD_SIZE; j++) {
        int colMatched = 1;
        for (int k = 0; k < CARD_SIZE; k++) {
          if (bingoCard[i][k * CARD_SIZE + j] != 0) {
            colMatched = 0;
            break;
          }
        }
        if (colMatched) {
          winner = i;
          break;
        }
      }
      if (winner != -1) break;

      // Check diagonals
      int diagMatched = 1;
      for (int j = 0; j < CARD_SIZE; j++) {
        if (bingoCard[i][j * CARD_SIZE + j] != 0) {
          diagMatched = 0;
          break;
        }
      }
      if (diagMatched) {
        winner = i;
        break;
      }

      diagMatched = 1;
      for (int j = 0; j < CARD_SIZE; j++) {
        if (bingoCard[i][j * CARD_SIZE + (CARD_SIZE - j - 1)] != 0) {
          diagMatched = 0;
          break;
        }
      }
      if (diagMatched) {
        winner = i;
        break;
      }
    }

    numTurns++;
  }

  // Print the winner and number of turns
  printf("Winner: Player %d\n", winner + 1);
  printf("Number of Turns: %d", numTurns);

  return 0;
}