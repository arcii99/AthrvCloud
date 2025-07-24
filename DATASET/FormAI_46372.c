//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printBoard(int board[ROWS][COLS], int nums[75]);

int main() {
  int board[ROWS][COLS];
  int nums[75];
  
  // Initialize board
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = 0;
    }
  }

  // Initialize nums 
  for (int i = 0; i < 75; i++) {
    nums[i] = i+1;
  }

  // Shuffle nums 
  srand(time(0));
  for (int i = 74; i > 0; i--) {
    int j = rand() % (i+1);
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  // Print initial board 
  printBoard(board, nums);

  // Play game
  int numCount = 0;
  while (numCount < 75) {
    printf("Enter next number (1-75): ");
    int num;
    scanf("%d", &num);

    // Validate input
    if (num < 1 || num > 75) {
      printf("Invalid input. Please enter a number between 1 and 75.\n");
      continue;
    }

    // Check if number is already called
    int called = 0;
    for (int i = 0; i < numCount; i++) {
      if (nums[i] == num) {
        printf("Number already called. Please enter a different number.\n");
        called = 1;
        break;
      }
    }
    if (called) {
      continue;
    }

    // Mark number on board 
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (board[i][j] == num) {
          board[i][j] = -1;
        }
      }
    }

    // Find and mark number on board
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (board[i][j] == 0 && nums[numCount] == num) {
          board[i][j] = num;
          numCount++;
          break;
        }
      }
      if (numCount == 75) {
        break;
      }
    }

    // Print updated board 
    printBoard(board, nums);
  }

  printf("Bingo! You win!\n");

  return 0;
}

void printBoard(int board[ROWS][COLS], int nums[75]) {
  printf("\n");
  for (int i = 0; i < ROWS; i++) {
    printf(" ");
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == -1) {
        printf("XX ");
      } else if (board[i][j] == 0) {
        printf("-- ");
      } else {
        printf("%02d ", board[i][j]);
      }
    }
    printf("\t\t");
    printf("%02d %02d %02d %02d %02d\n", nums[i], nums[i+15], nums[i+30], nums[i+45], nums[i+60]);
  }
  printf("\n");
}