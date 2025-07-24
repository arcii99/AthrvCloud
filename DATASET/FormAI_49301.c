//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

int bingoBoard[ROWS][COLS];
int calledNumbers[MAX_NUM];
int calledNumbersCount = 0;

void initializeBoard() {
  int i, j, num = 1;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      bingoBoard[i][j] = num++;
    }
  }

  shuffleBoard();
}

void shuffleBoard() {
  int i, j, temp;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      int r = rand() % ROWS;
      int c = rand() % COLS;

      temp = bingoBoard[i][j];
      bingoBoard[i][j] = bingoBoard[r][c];
      bingoBoard[r][c] = temp;
    }
  }
}

void printBoard() {
  int i, j;

  printf("\n\n\tB\tI\tN\tG\tO\n\n");

  for (i = 0; i < ROWS; i++) {
    printf("%d\t", i+1);

    for (j = 0; j < COLS; j++) {
      if (bingoBoard[i][j] == -1) {
        printf("X\t");
      } else {
        printf("%d\t", bingoBoard[i][j]);
      }
    }

    printf("\n");
  }
}

void callNumber() {
  int num = rand() % MAX_NUM + 1;
  int i;

  // Check if number has already been called
  for (i = 0; i < calledNumbersCount; i++) {
    if (calledNumbers[i] == num) {
      callNumber();
      return;
    }
  }

  printf("\n\n\tThe number called is: %d\n\n", num);

  // Mark number on board
  for (i = 0; i < ROWS; i++) {
    int j;

    for (j = 0; j < COLS; j++) {
      if (bingoBoard[i][j] == num) {
        bingoBoard[i][j] = -1;
        calledNumbers[calledNumbersCount++] = num;
        return;
      }
    }
  }
}

int checkBingo() {
  int i, j;

  // Check rows
  for (i = 0; i < ROWS; i++) {
    int count = 0;

    for (j = 0; j < COLS; j++) {
      if (bingoBoard[i][j] == -1) {
        count++;
      }
    }

    if (count == COLS) {
      return 1;
    }
  }

  // Check columns
  for (i = 0; i < COLS; i++) {
    int count = 0;

    for (j = 0; j < ROWS; j++) {
      if (bingoBoard[j][i] == -1) {
        count++;
      }
    }

    if (count == ROWS) {
      return 1;
    }
  }

  // Check diagonals
  if (bingoBoard[0][0] == -1 && bingoBoard[1][1] == -1 && bingoBoard[2][2] == -1 && bingoBoard[3][3] == -1 && bingoBoard[4][4] == -1) {
    return 1;
  }

  if (bingoBoard[0][4] == -1 && bingoBoard[1][3] == -1 && bingoBoard[2][2] == -1 && bingoBoard[3][1] == -1 && bingoBoard[4][0] == -1) {
    return 1;
  }

  return 0;
}

int main() {
  char playAgain = 'Y';

  while (playAgain == 'Y') {
    // Initialize game
    initializeBoard();
    calledNumbersCount = 0;

    // Game loop
    while (!checkBingo()) {
      printBoard();
      callNumber();
    }

    // Print winning board and message
    printBoard();
    printf("\n\n\tBINGO!!!\n\n");

    // Ask to play again
    printf("\n\n\tPlay again? (Y/N): ");
    scanf(" %c", &playAgain);
  }

  return 0;
}