//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

int main() {
  srand(time(NULL)); // seed the random number generator
  int board[ROWS][COLUMNS]; // the board

  // initialize the board with random numbers between 0 and 9
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLUMNS; j++) {
      board[i][j] = rand() % 10;
    }
  }

  int score = 0; // the player's score
  int turns = 5; // the number of turns the player has

  // loop through each turn
  for(int turn = 1; turn <= turns; turn++) {
    // print the board
    printf("Turn %d\n", turn);
    for(int i = 0; i < ROWS; i++) {
      for(int j = 0; j < COLUMNS; j++) {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }

    // ask the player for their move
    int row, column;
    printf("Enter the row and column of the number you want to remove:\n");
    scanf("%d %d", &row, &column);

    // check if the move is valid
    if(row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
      printf("Invalid move.\n");
      turn--; // the turn doesn't count
      continue;
    }

    // remove the number and add to the player's score
    int value = board[row][column];
    board[row][column] = 0;
    score += value;

    // shift the board down
    for(int i = ROWS - 2; i >= 0; i--) {
      for(int j = 0; j < COLUMNS; j++) {
        if(board[i][j] == 0) {
          int temp = board[i][j];
          board[i][j] = board[i + 1][j];
          board[i + 1][j] = temp;
        }
      }
    }
  }

  // print the final score
  printf("Final score: %d\n", score);

  return 0;
}