//FormAI DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8 // size of the game board

int board[SIZE][SIZE]; // game board
int revealed[SIZE][SIZE]; // flag to indicate if a cell has been revealed

// function to initialize the game board with random values
void init_board() {
  // fill each cell with a unique value
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = (i * SIZE + j) / 2;
      revealed[i][j] = 0;
    }
  }
  // shuffle the board
  srand(time(NULL));
  for (int i = 0; i < SIZE * SIZE; i++) {
    int x1 = rand() % SIZE;
    int y1 = rand() % SIZE;
    int x2 = rand() % SIZE;
    int y2 = rand() % SIZE;
    int temp = board[x1][y1];
    board[x1][y1] = board[x2][y2];
    board[x2][y2] = temp;
  }
}

// function to print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < SIZE; i++) {
    printf("+");
    for (int j = 0; j < SIZE; j++) {
      printf("---+");
    }
    printf("\n");
    printf("|");
    for (int j = 0; j < SIZE; j++) {
      if (revealed[i][j]) {
        printf(" %2d |", board[i][j]);
      } else {
        printf("    |");
      }
    }
    printf("\n");
  }
  printf("+");
  for (int j = 0; j < SIZE; j++) {
    printf("---+");
  }
  printf("\n");
}

// function to reveal a cell
void reveal(int x, int y) {
  if (revealed[x][y]) {
    return;
  }
  revealed[x][y] = 1;
  print_board();
  if (board[x][y] == -1) {
    printf("You lose.\n");
    exit(0);
  }
  int count = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (revealed[i][j]) {
        count++;
      }
    }
  }
  if (count == SIZE * SIZE) {
    printf("You win!\n");
    exit(0);
  }
}

// main function
int main() {
  init_board();
  print_board();
  while (1) {
    printf("Enter the row and column of the cell to reveal: ");
    int x, y;
    scanf("%d %d", &x, &y);
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
      printf("Invalid input.\n");
    } else {
      reveal(x, y);
    }
  }
  return 0;
}