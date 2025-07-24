//FormAI DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_ATTEMPTS 8

char board[BOARD_SIZE][BOARD_SIZE];

/**
 * Initializes the board with question marks to represent hidden
 * values.
 */
void init_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '?';
    }
  }
}

/**
 * Prints the current board state to the console.
 */
void print_board() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

/**
 * Populates the board with pairs of randomly generated letters.
 */
void populate_board() {
  char available_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int num_available_letters = sizeof(available_letters) / sizeof(char);
  int num_pairs = BOARD_SIZE * BOARD_SIZE / 2;

  srand(time(NULL));
  for (int i = 0; i < num_pairs; i++) {
    char letter = available_letters[rand() % num_available_letters];
    int num_placed = 0;
    while (num_placed < 2) {
      int row = rand() % BOARD_SIZE;
      int col = rand() % BOARD_SIZE;
      if (board[row][col] == '?') {
        board[row][col] = letter;
        num_placed++;
      }
    }
  }
}

/**
 * Prompts the user to input a row and column index to reveal the
 * value at that cell.
 */
void prompt_user() {
  int row, col;
  printf("Enter row and col: ");
  scanf("%d %d", &row, &col);

  if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
    printf("Value at (%d, %d): %c\n", row, col, board[row][col]);
  } else {
    printf("Invalid input\n");
  }
}

int main() {
  int num_attempts = 0;

  init_board();
  populate_board();
  print_board();

  while (num_attempts < MAX_ATTEMPTS) {
    prompt_user();
    num_attempts++;
  }

  printf("Game over!\n");

  return 0;
}