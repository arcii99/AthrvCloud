//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void print_board(int board[5][5]);
void generate_numbers(int nums[75]);
int check_win(int board[5][5]);

int main() {
  int board[5][5] = {0}; // initialize the board with zeros
  int nums[75]; // array to store the 75 bingo numbers
  int called[75] = {0}; // array to keep track of called numbers
  int num_calls = 0; // count of number of times numbers are called

  // seed the random number generator
  srand(time(NULL));

  // generate the 75 bingo numbers randomly
  generate_numbers(nums);

  // print out the board and start calling bingo numbers
  printf("Let's play Bingo!\n");
  print_board(board);
  while (1) {
    // generate a random number
    int index = rand() % 75;
    int num = nums[index];

    // check if the number has already been called
    if (called[num]) {
      continue;
    }

    // mark the number as called
    called[num] = 1;
    num_calls++;

    // print out the called number and update the board
    printf("Called number: %d\n", num);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (board[i][j] == num) {
          board[i][j] = -1;
        }
      }
    }
    print_board(board);

    // check if there is a winner
    int winner = check_win(board);
    if (winner) {
      printf("Bingo! Congratulations on winning!\n");
      break;
    }

    // check if all numbers have been called
    if (num_calls == 75) {
      printf("All numbers have been called. No winner.\n");
      break;
    }
  }

  return 0;
}

// function to print out the board
void print_board(int board[5][5]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (board[i][j] == -1) {
        printf("X ");
      } else {
        printf("%d ", board[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

// function to generate the 75 bingo numbers
void generate_numbers(int nums[75]) {
  for (int i = 0; i < 75; i++) {
    nums[i] = i + 1;
  }
  for (int i = 0; i < 75; i++) {
    int j = rand() % 75;
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}

// function to check if there is a winner
int check_win(int board[5][5]) {
  // check rows
  for (int i = 0; i < 5; i++) {
    if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1 && board[i][3] == -1 && board[i][4] == -1) {
      return 1;
    }
  }

  // check columns
  for (int i = 0; i < 5; i++) {
    if (board[0][i] == -1 && board[1][i] == -1 && board[2][i] == -1 && board[3][i] == -1 && board[4][i] == -1) {
      return 1;
    }
  }

  // check diagonal
  if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
    return 1;
  }
  if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
    return 1;
  }

  // if no winner yet
  return 0;
}