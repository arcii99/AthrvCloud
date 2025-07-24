//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define FREE_SPACE_VALUE 0

// Function to print the bingo board
void printBoard(int board[ROWS][COLS], bool isShowFreeSpace) {
  printf("\n---------------------------\n");
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (board[row][col] == FREE_SPACE_VALUE && !isShowFreeSpace) {
        printf("|  ");
      } else {
        printf("| %d", board[row][col]);
      }
    }
    printf("|\n---------------------------\n");
  }
}

// Function to check if a number is already called
bool isCalled(int calledNumbers[], int calledNumbersCount, int number) {
  for (int i = 0; i < calledNumbersCount; i++) {
    if (calledNumbers[i] == number) {
      return true;
    }
  }
  return false;
}

// Function to mark a number called in the board
void markNumberCalled(int board[ROWS][COLS], int number) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (board[row][col] == number) {
        board[row][col] = FREE_SPACE_VALUE;
      }
    }
  }
}

// Function to check if a row has all its numbers marked
bool isRowMarked(int board[ROWS][COLS], int row) {
  for (int col = 0; col < COLS; col++) {
    if (board[row][col] != FREE_SPACE_VALUE) {
      return false;
    }
  }
  return true;
}

// Function to check if a column has all its numbers marked
bool isColumnMarked(int board[ROWS][COLS], int col) {
  for (int row = 0; row < ROWS; row++) {
    if (board[row][col] != FREE_SPACE_VALUE) {
      return false;
    }
  }
  return true;
}

// Function to check if a diagonal has all its numbers marked
bool isDiagonalMarked(int board[ROWS][COLS], bool isMainDiagonal) {
  for (int i = 0; i < ROWS; i++) {
    int j = isMainDiagonal ? i : ROWS - i - 1;
    if (board[i][j] != FREE_SPACE_VALUE) {
      return false;
    }
  }
  return true;
}

int main() {
  int board[ROWS][COLS] = {
      {5, 10, 0, 20, 25},
      {4, 9, 0, 19, 24},
      {3, 8, 0, 18, 23},
      {2, 7, 0, 17, 22},
      {1, 6, 0, 16, 21},
  };
  int calledNumbers[ROWS * COLS] = {0};
  int calledNumbersCount = 0;
  srand(time(NULL));

  printf("Welcome to Bingo Simulator!\n\n");

  // Print the initial board
  printf("This is your Bingo board:\n");
  printBoard(board, false);

  // Keep calling numbers until someone wins
  int counter=1;
  while (true) {
    int number = rand() % (ROWS * COLS) + 1;
    if (isCalled(calledNumbers, calledNumbersCount, number)) {
      continue;
    }
    calledNumbers[calledNumbersCount++] = number;
    printf("\n%d. The number called is: %d",counter++, number);
    markNumberCalled(board, number);

    // Check for winning conditions
    bool isWinner = false;
    for (int i = 0; i < ROWS; i++) {
      if (isRowMarked(board, i)) {
        printf("\nBINGO! Row %d is marked!", i + 1);
        isWinner = true;
        break;
      }
    }
    if (!isWinner) {
      for (int i = 0; i < COLS; i++) {
        if (isColumnMarked(board, i)) {
          printf("\nBINGO! Column %d is marked!", i + 1);
          isWinner = true;
          break;
        }
      }
    }
    if (!isWinner) {
      if (isDiagonalMarked(board, true)) {
        printf("\nBINGO! The main diagonal is marked!");
        isWinner = true;
      } else if (isDiagonalMarked(board, false)) {
        printf("\nBINGO! The secondary diagonal is marked!");
        isWinner = true;
      }
    }
    if (isWinner) {
      printf("\nCongratulations, you are the winner!\n");
      break;
    }

    // Print the board after marking the number called
    printf("\nThis is your updated Bingo board:\n");
    printBoard(board, true);

    // Ask the player if they want to continue or quit
    char answer;
    printf("\nDo you want to continue (Y/N)? ");
    scanf(" %c", &answer);
    if (answer == 'N' || answer == 'n') {
      printf("\nThanks for playing Bingo Simulator!\n");
      break;
    }
  }

  return 0;
}