//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void init_board(int board[ROWS][COLS]);
int generate_number(int previous_numbers[], int count);
int check_bingo(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);

int main() {
  srand(time(NULL)); // seed random number generator with current time

  int board[ROWS][COLS];
  int previous_numbers[ROWS*COLS] = { 0 }; // array to keep track of previous numbers
  int count = 0; // count of numbers generated

  init_board(board);

  while (!check_bingo(board)) {
    int number = generate_number(previous_numbers, count);
    previous_numbers[count] = number;
    count++;

    printf("The next number is: %d\n", number);
    printf("Press return to continue...");
    getchar();

    // check if number is on the board and mark it if it is
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (board[i][j] == number) {
          board[i][j] = -1; // mark as checked
        }
      }
    }

    print_board(board);
  }

  printf("BINGO!!!\n");

  return 0;
}

void init_board(int board[ROWS][COLS]) {
  // fill board with numbers 1-25 in random order
  int numbers[ROWS*COLS];
  for (int i = 0; i < ROWS*COLS; i++) {
    numbers[i] = i+1;
  }
  for (int i = 0; i < ROWS*COLS; i++) {
    int j = rand() % (ROWS*COLS-i) + i;
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
  }

  // copy numbers to board
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = numbers[i*ROWS+j];
    }
  }
}

int generate_number(int previous_numbers[], int count) {
  int number;
  do {
    number = rand() % 25 + 1;
  } while (count < ROWS*COLS && previous_numbers[count-1] == number);
  return number;
}

int check_bingo(int board[ROWS][COLS]) {
  // check rows
  for (int i = 0; i < ROWS; i++) {
    if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1 && board[i][3] == -1 && board[i][4] == -1) {
      return 1;
    }
  }

  // check columns
  for (int j = 0; j < COLS; j++) {
    if (board[0][j] == -1 && board[1][j] == -1 && board[2][j] == -1 && board[3][j] == -1 && board[4][j] == -1) {
      return 1;
    }
  }

  // check diagonals
  if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
    return 1;
  }
  if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
    return 1;
  }

  return 0;
}

void print_board(int board[ROWS][COLS]) {
  printf("\nBoard:\n\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == -1) {
        printf(" X ");
      } else {
        printf("%2d ", board[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}