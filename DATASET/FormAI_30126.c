//FormAI DATASET v1.0 Category: Memory Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(char board[][BOARD_SIZE]) {
  // Print the current state of the board
  printf("\n");
  printf("\t1\t2\t3\t4\n");
  printf("--------------------------------------\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d |\t%c\t%c\t%c\t%c\n", i + 1, board[i][0], board[i][1], board[i][2], board[i][3]);
  }
  printf("\n");
}

void generate_board(char board[][BOARD_SIZE]) {
  // Set the board with random letters
  char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
  int letter_count[] = {0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      int index = rand() % 8;
      while (letter_count[index] == 2) {
        index = rand() % 8;
      }
      board[i][j] = letters[index];
      letter_count[index]++;
    }
  }
}

int get_input(char *message) {
  // Get player input for row or column
  printf("%s", message);
  int input = -1;
  scanf("%d", &input);
  return input;
}

void make_move(char board[][BOARD_SIZE], int r1, int c1, int r2, int c2) {
  // Switch the letters of two cells on the board
  char temp = board[r1][c1];
  board[r1][c1] = board[r2][c2];
  board[r2][c2] = temp;
}

int check_match(char board[][BOARD_SIZE], int r1, int c1, int r2, int c2) {
  // Check whether two cells on the board contain matching letters
  if (board[r1][c1] == board[r2][c2]) {
    board[r1][c1] = ' ';
    board[r2][c2] = ' ';
    return 1;
  } else {
    return 0;
  }
}

int check_win(char board[][BOARD_SIZE]) {
  // Check if the game is won by checking that all cells are empty
  int empty_count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        empty_count++;
      }
    }
  }
  if (empty_count == BOARD_SIZE * BOARD_SIZE) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char board[BOARD_SIZE][BOARD_SIZE];
  int moves = 0;

  // Initialize random number generator
  srand(time(NULL));

  // Generate the initial state of the board
  generate_board(board);
  
  // Game loop
  while (1) {
    // Print the current state of the board
    print_board(board);

    // Get the player's first cell selection
    int row1 = get_input("Enter the row of the first cell (1-4): ") - 1;
    int col1 = get_input("Enter the column of the first cell (1-4): ") - 1;

    // Get the player's second cell selection
    int row2 = get_input("Enter the row of the second cell (1-4): ") - 1;
    int col2 = get_input("Enter the column of the second cell (1-4): ") - 1;

    // Check if the player has selected two different cells
    if (row1 == row2 && col1 == col2) {
      printf("\nYou must select two different cells! Try again.\n\n");
      continue;
    }

    // Check if the selected cells are adjacent horizontally or vertically
    if (abs(row1 - row2) + abs(col1 - col2) != 1) {
      printf("\nThe selected cells are not adjacent! Try again.\n\n");
      continue;
    }

    // Make a move by switching the letters of the two cells and checking for a match
    make_move(board, row1, col1, row2, col2);
    moves++;

    // Check if the move resulted in a match
    if (check_match(board, row1, col1, row2, col2)) {
      printf("\nMatch found! You have %d moves remaining.\n\n", (BOARD_SIZE * BOARD_SIZE / 2) - moves);
    } else {
      printf("\nNo match found. You have %d moves remaining.\n\n", (BOARD_SIZE * BOARD_SIZE / 2) - moves);
    }

    // Check if the game has been won
    if (check_win(board)) {
      printf("Congratulations! You have won the game in %d moves!\n\n", moves);
      break;
    }

    // Check if the player has run out of moves
    if (moves == BOARD_SIZE * BOARD_SIZE / 2) {
      printf("Game over! You have run out of moves. Better luck next time.\n\n");
      break;
    }
  }

  return 0;
}