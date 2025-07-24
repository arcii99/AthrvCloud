//FormAI DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES 20

void initializeBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS], int revealed[ROWS][COLS]);
void getMove(int *r1, int *c1, int *r2, int *c2);
void checkMove(char board[ROWS][COLS], int r1, int c1, int r2, int c2, int *correct, int revealed[ROWS][COLS]);
void revealTiles(char board[ROWS][COLS], int r1, int c1, int r2, int c2, int revealed[ROWS][COLS]);

int main() {
  char board[ROWS][COLS];
  int revealed[ROWS][COLS] = {0}; // 0 represents false and 1 represents true in this array
  int moves = 0;
  int correct = 0;

  printf("Welcome to the Memory Game!\n");
  printf("You have %d moves to match all tiles.\n", MAX_MOVES);
  printf("Good luck!\n");

  initializeBoard(board);
  while(moves < MAX_MOVES && correct < (ROWS * COLS) / 2){
    printBoard(board, revealed);
    int r1, c1, r2, c2;
    getMove(&r1, &c1, &r2, &c2);
    checkMove(board, r1, c1, r2, c2, &correct, revealed);
    revealTiles(board, r1, c1, r2, c2, revealed);
    moves++;
  }

  if (correct == (ROWS * COLS) / 2) {
    printf("You won in %d moves!\n", moves);
  } else {
    printf("You lost! Better luck next time.\n");
  }

  return 0;
}

void initializeBoard(char board[ROWS][COLS]){
  char letters[ROWS * COLS / 2] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
  int count[ROWS * COLS / 2] = {0};
  srand (time(NULL));

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int randomIndex = rand() % (ROWS * COLS / 2);
      while (count[randomIndex] == 2) {
        randomIndex = rand() % (ROWS * COLS / 2);
      }
      board[i][j] = letters[randomIndex];
      count[randomIndex]++;
    }
  }
}

void printBoard(char board[ROWS][COLS], int revealed[ROWS][COLS]) {
  printf("\n");

  // Header Row
  printf("  ");
  for (int i = 0; i < COLS; i++){
    printf("%d ", i + 1);
  }
  printf("\n");

  // Rows
  for (int i = 0; i < ROWS; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < COLS; j++) {
      if (revealed[i][j]){
        printf("%c ", board[i][j]);
      } else {
        printf("# ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void getMove(int *r1, int *c1, int *r2, int *c2) {
  printf("Enter first tile's row and column numbers.\n");
  scanf("%d %d", r1, c1);

  // Adjusting indexes to match array indexing
  *r1 -= 1;
  *c1 -= 1;

  printf("Enter second tile's row and column numbers.\n");
  scanf("%d %d", r2, c2);

  // Adjusting indexes to match array indexing
  *r2 -= 1;
  *c2 -= 1;
}

void checkMove(char board[ROWS][COLS], int r1, int c1, int r2, int c2, int *correct, int revealed[ROWS][COLS]) {
  if (board[r1][c1] == board[r2][c2]) {
    printf("Match found!\n");
    (*correct)++;
  } else {
    printf("No match found.\n");
  }
}

void revealTiles(char board[ROWS][COLS], int r1, int c1, int r2, int c2, int revealed[ROWS][COLS]) {
  revealed[r1][c1] = 1;
  revealed[r2][c2] = 1;
}