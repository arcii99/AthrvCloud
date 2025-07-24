//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_ROUNDS 10

int rollDice(void);
void printBoard(int board[][BOARD_SIZE], int currPlayer);
void playRound(int board[][BOARD_SIZE], int scores[], int currPlayer);

int main(void) {
  int board[BOARD_SIZE][BOARD_SIZE];
  int scores[2] = {0, 0};
  int currPlayer = 0;

  srand(time(NULL));

  // initialize board with random values
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = rand() % 100;
    }
  }

  // play NUM_ROUNDS rounds
  for (int i = 0; i < NUM_ROUNDS; i++) {
    printf("ROUND %d\n", i + 1);
    playRound(board, scores, currPlayer);
    currPlayer = (currPlayer + 1) % 2; // switch player
  }

  // print final scores
  printf("FINAL SCORES\n");
  printf("Player 1: %d\n", scores[0]);
  printf("Player 2: %d\n", scores[1]);

  return 0;
}

int rollDice(void) {
  return (rand() % 6) + 1;
}

void printBoard(int board[][BOARD_SIZE], int currPlayer) {
  printf("  ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%2d ", i);
  }
  printf("\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%2d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (currPlayer == 0) {
        printf("%2d ", board[i][j]);
      } else {
        printf(" X ");
      }
    }
    printf("\n");
  }
}

void playRound(int board[][BOARD_SIZE], int scores[], int currPlayer) {
  int row, col;
  int numMoves = rollDice();
  printf("Player %d, you rolled a %d. You have %d moves.\n", currPlayer + 1, numMoves, numMoves);

  printBoard(board, currPlayer);

  // make numMoves moves
  for (int i = 0; i < numMoves; i++) {
    // get user input for new position
    printf("Player %d, enter new position (row column): ", currPlayer + 1);
    scanf("%d %d", &row, &col);

    // check if new position is valid
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE ||
        (currPlayer == 1 && board[row][col] == 0)) {
      printf("Invalid position, please try again.\n");
      i--;
      continue;
    }

    // update scores and board
    scores[currPlayer] += board[row][col];
    board[row][col] = 0;
  }

  // print updated scores
  printf("Player %d, your new score is %d.\n", currPlayer + 1, scores[currPlayer]);
}