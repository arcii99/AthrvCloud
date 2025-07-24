//FormAI DATASET v1.0 Category: Sudoku solver ; Style: interoperable
#include <stdio.h>

int board[9][9];

int row_check(int row, int num) {
  for (int col = 0; col < 9; col++) {
    if (board[row][col] == num) {
      return 0;
    }
  }
  return 1;
}

int col_check(int col, int num) {
  for (int row = 0; row < 9; row++) {
    if (board[row][col] == num) {
      return 0;
    }
  }
  return 1;
}

int square_check(int row, int col, int num) {
  int startRow = row - (row % 3);
  int startCol = col - (col % 3);
  for (int i = startRow; i < startRow + 3; i++) {
    for (int j = startCol; j < startCol + 3; j++) {
      if (board[i][j] == num) {
        return 0;
      }
    }
  }
  return 1;
}

int check_number(int row, int col, int num) {
  int rowOk = row_check(row, num);
  int colOk = col_check(col, num);
  int squareOk = square_check(row, col, num);
  return rowOk && colOk && squareOk;
}

int solve() {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == 0) {
        for (int num = 1; num <= 9; num++) {
          if (check_number(row, col, num)) {
            board[row][col] = num;
            if (solve()) {
              return 1;
            } else {
              board[row][col] = 0;
            }
          }
        }
        return 0;
      }
    }
  }
  return 1;
}

void print_board() {
  for (int i = 0; i < 9; i++) {
    if (i % 3 == 0 && i != 0) {
      printf("--------------------\n");
    }
    for (int j = 0; j < 9; j++) {
      if (j % 3 == 0 && j != 0) {
        printf("| ");
      }
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  //initialize the board with zeros
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j] = 0;
    }
  }
  
  //set the initial board values
  board[0][0] = 5;
  board[0][1] = 3;
  board[0][4] = 7;
  board[1][0] = 6;
  board[1][3] = 1;
  board[1][4] = 9;
  board[1][5] = 5;
  board[2][1] = 9;
  board[2][2] = 8;
  board[2][7] = 6;
  board[3][0] = 8;
  board[3][4] = 6;
  board[3][8] = 3;
  board[4][0] = 4;
  board[4][3] = 8;
  board[4][5] = 3;
  board[4][8] = 1;
  board[5][0] = 7;
  board[5][4] = 2;
  board[5][8] = 6;
  board[6][1] = 6;
  board[6][6] = 2;
  board[6][7] = 8;
  board[7][3] = 4;
  board[7][4] = 1;
  board[7][5] = 9;
  board[7][8] = 5;
  board[8][4] = 8;
  board[8][7] = 7;
  board[8][8] = 9;
  
  printf("Original board:\n");
  print_board();
  
  if (solve()) {
    printf("\n\nSolution:\n");
    print_board();
  } else {
    printf("\n\nNo solution found.\n");
  }

  return 0;
}