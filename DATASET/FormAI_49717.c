//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int board[5][5]) {
  printf("\nB   I   N   G   O\n");
  for (int row = 0; row < 5; row++) {
    printf("-----------------\n");
    for (int col = 0; col < 5; col++) {
      if (row == 2 && col == 2) {
        printf("| * ");
      } else {
        printf("| %d ", board[row][col]);
      }
    }
    printf("|\n");
  }
  printf("-----------------\n");
}

int check_bingo(int board[5][5]) {
  int count = 0;
  // check rows
  for (int row = 0; row < 5; row++) {
    int sum = 0;
    for (int col = 0; col < 5; col++) {
      sum += board[row][col];
    }
    if (sum == 0) {
      count++;
    }
  }
  // check columns
  for (int col = 0; col < 5; col++) {
    int sum = 0;
    for (int row = 0; row < 5; row++) {
      sum += board[row][col];
    }
    if (sum == 0) {
      count++;
    }
  }
  // check diagonals
  if (board[0][0] + board[1][1] + board[2][2] + board[3][3] + board[4][4] == 0) {
    count++;
  }
  if (board[0][4] + board[1][3] + board[2][2] + board[3][1] + board[4][0] == 0) {
    count++;
  }
  return count;
}

int is_unique(int board[5][5], int num) {
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 5; col++) {
      if (board[row][col] == num) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  srand(time(NULL));
  int board[5][5] = {0};
  int num_called[75] = {0};
  int num_called_index = 0;
  int num_calls = 0;
  while (1) {
    int num = rand() % 75 + 1;
    if (is_unique(board, num)) {
      printf("Number called: %d\n", num);
      num_calls++;
      num_called[num_called_index] = num;
      num_called_index++;
      for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
          if (board[row][col] == num) {
            board[row][col] = 0;
          }
        }
      }
      // fill in board
      for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
          if (num == board[row][col]) {
            board[row][col] = 0;
          }
        }
      }
      // check if all numbers called
      if (num_called[74] != 0) {
        break;
      }
      // check if bingo
      print_board(board);
      int bingo_count = check_bingo(board);
      printf("\nBINGO count: %d\n", bingo_count);
      if (bingo_count >= 5) {
        printf("\nBINGO! You won in %d calls.\n", num_calls);
        break;
      }
      printf("\nPress enter to call next number...");
      getchar();
    }
  }
  return 0;
}