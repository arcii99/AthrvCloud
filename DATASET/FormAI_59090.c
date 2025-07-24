//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to display the bingo board
void displayBoard(int board[][COLS]) {
  printf("\tB\tI\tN\tG\tO\n");
  for(int i=0; i<ROWS; i++) {
    printf("%d\t", i+1);
    for(int j=0; j<COLS; j++) {
      printf("%d\t", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if there is a bingo
int checkBingo(int board[][COLS]) {
  // Check for horizontal bingo
  for(int i=0; i<ROWS; i++) {
    int count = 0;
    for(int j=0; j<COLS; j++) {
      if(board[i][j] == -1) {
        count++;
      }
    }
    if(count == COLS) {
      return 1;
    }
  }
  // Check for vertical bingo
  for(int i=0; i<COLS; i++) {
    int count = 0;
    for(int j=0; j<ROWS; j++) {
      if(board[j][i] == -1) {
        count++;
      }
    }
    if(count == ROWS) {
      return 1;
    }
  }
  // Check for diagonal bingo
  if(board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
    return 1;
  }
  if(board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
    return 1;
  }
  return 0;
}

int main() {
  printf("Welcome to the Bingo Simulator!\n");
  
  // Initialize the board
  int board[ROWS][COLS];
  for(int i=0; i<ROWS; i++) {
    for(int j=0; j<COLS; j++) {
      board[i][j] = -1;
    }
  }

  // Generate random numbers and mark them on the board
  srand(time(0));
  int num;
  int count = 0;
  while(count < 25) {
    num = rand() % 75 + 1;
    // Check if the number is already on the board
    int found = 0;
    for(int i=0; i<ROWS; i++) {
      for(int j=0; j<COLS; j++) {
        if(board[i][j] == num) {
          found = 1;
        }
      }
    }
    // Mark the number on the board if it is not already there
    if(!found) {
      printf("Number generated: %d\n", num);
      for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
          if(board[i][j] == num) {
            board[i][j] = -1;
          }
        }
      }
      count++;
    }
  }

  // Display the final board
  printf("Final Bingo Board:\n");
  displayBoard(board);
  
  // Check for bingo
  int bingo = checkBingo(board);
  if(bingo) {
    printf("Bingo! Congratulations!\n");
  } else {
    printf("Sorry, better luck next time!\n");
  }

  return 0;
}