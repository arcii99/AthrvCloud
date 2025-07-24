//FormAI DATASET v1.0 Category: Memory Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void print_board(char board[][SIZE]) {
  printf("\n--------\n");
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      printf("| %c ", board[row][col]);
    }
    printf("|\n--------\n");
  }
}

void populate_board(char board[][SIZE]) {
  int values[SIZE * SIZE / 2];
  int index = 0;

  // populate values array with pairs of characters
  for (int i = 0; i < SIZE * SIZE / 2; i++) {
    values[i] = 65 + i;
  }

  // shuffle values array
  srand(time(NULL));
  for (int i = 0; i < SIZE * SIZE / 2; i++) {
    int random_index = rand() % (SIZE * SIZE / 2);
    int temp = values[i];
    values[i] = values[random_index];
    values[random_index] = temp;
  }

  // populate board with shuffled values
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      board[row][col] = (char)values[index];
      index++;
      if (index == SIZE * SIZE / 2) {
        index = 0;
      }
    }
  }
}

int is_game_over(char board[][SIZE], int num_guesses) {
  if (num_guesses == SIZE * SIZE / 2) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char board[SIZE][SIZE];
  populate_board(board);
  int pairs_found = 0;
  int num_guesses = 0;
  int first_row, first_col, second_row, second_col;

  while (!is_game_over(board, num_guesses)) {
    print_board(board);

    // get first guess
    printf("Enter first guess (row col): ");
    scanf("%d %d", &first_row, &first_col);
    while (board[first_row][first_col] == '-') {
      printf("Invalid guess. Enter first guess (row col): ");
      scanf("%d %d", &first_row, &first_col);
    }
    printf("First guess: %c\n", board[first_row][first_col]);
    board[first_row][first_col] = '-';

    // get second guess
    printf("Enter second guess (row col): ");
    scanf("%d %d", &second_row, &second_col);
    while (board[second_row][second_col] == '-') {
      printf("Invalid guess. Enter second guess (row col): ");
      scanf("%d %d", &second_row, &second_col);
    }
    printf("Second guess: %c\n", board[second_row][second_col]);
    printf("\n");

    num_guesses++;

    if (board[first_row][first_col] == board[second_row][second_col]) {
      printf("Pairs found!\n");
      pairs_found++;
      if (pairs_found == SIZE * SIZE / 2) {
        printf("Congratulations, you won!\n");
        break;
      }
    } else {
      board[first_row][first_col] = board[second_row][second_col] = '*';
      printf("Sorry, not a pair.\n");
    }
  }
  
  return 0;
}