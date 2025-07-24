//FormAI DATASET v1.0 Category: Memory Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void initBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(int board[BOARD_SIZE][BOARD_SIZE], int hidden[BOARD_SIZE][BOARD_SIZE]);
void selectTile(int board[BOARD_SIZE][BOARD_SIZE], int hidden[BOARD_SIZE][BOARD_SIZE]);
int checkPair(int board[BOARD_SIZE][BOARD_SIZE], int hidden[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2);
int checkWin(int hidden[BOARD_SIZE][BOARD_SIZE]);

int main() {
  int board[BOARD_SIZE][BOARD_SIZE];
  int hidden[BOARD_SIZE][BOARD_SIZE];
  int num_pairs = (BOARD_SIZE * BOARD_SIZE) / 2;

  // Initialize board and hidden board
  initBoard(board);
  initBoard(hidden);

  // Randomly select pairs and place them on the board
  srand(time(NULL));
  int x, y;
  for (int i = 0; i < num_pairs; i++) {
    // Select first tile
    do {
      x = rand() % BOARD_SIZE;
      y = rand() % BOARD_SIZE;
    } while (board[x][y] != 0);
    board[x][y] = i+1;

    // Select second tile
    do {
      x = rand() % BOARD_SIZE;
      y = rand() % BOARD_SIZE;
    } while (board[x][y] != 0);
    board[x][y] = i+1;
  }

  while (!checkWin(hidden)) {
    printBoard(board, hidden);
    selectTile(board, hidden);
  }

  printf("Congratulations, you won!\n");

  return 0;
}

// Initialize board with zeros
void initBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

// Prints the board, with hidden values showing only if revealed
void printBoard(int board[BOARD_SIZE][BOARD_SIZE], int hidden[BOARD_SIZE][BOARD_SIZE]) {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (hidden[i][j] == 0) {
        printf("|   ");
      }
      else {
        printf("| %d ", board[i][j]);
      }
    }
    printf("|\n");
  }
}

// Select a tile to reveal and check if it's a match
void selectTile(int board[BOARD_SIZE][BOARD_SIZE], int hidden[BOARD_SIZE][BOARD_SIZE]) {
  int x1, y1, x2, y2;

  printf("\nSelect a tile to reveal:\n");
  printf("Row:");
  scanf("%d", &x1);
  printf("Column:");
  scanf("%d", &y1);

  // Check if tile already revealed
  if (hidden[x1-1][y1-1] != 0) {
    printf("Tile already revealed. Please try again.\n");
    return;
  }

  hidden[x1-1][y1-1] = 1;
  printBoard(board, hidden);

  printf("\nSelect a second tile to reveal:\n");
  printf("Row:");
  scanf("%d", &x2);
  printf("Column:");
  scanf("%d", &y2);

  // Check if tile already revealed
  if (hidden[x2-1][y2-1] != 0) {
    printf("Tile already revealed. Please try again.\n");
    return;
  }

  hidden[x2-1][y2-1] = 1;
  printBoard(board, hidden);

  if (!checkPair(board, hidden, x1-1, y1-1, x2-1, y2-1)) {
    hidden[x1-1][y1-1] = 0;
    hidden[x2-1][y2-1] = 0;
  }
}

// Check if the selected tiles are a pair
int checkPair(int board[BOARD_SIZE][BOARD_SIZE], int hidden[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2) {
  if (board[x1][y1] != board[x2][y2]) {
    printf("Not a match.\n");
    return 0;
  }
  else {
    printf("Match found!\n");
    return 1;
  }
}

// Check if all tiles are revealed
int checkWin(int hidden[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (hidden[i][j] == 0) {
        return 0;
      }
    }
  }
  return 1;
}