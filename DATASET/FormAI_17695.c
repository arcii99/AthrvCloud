//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_RAND_NUM 75

void genUniqueRandNum(int *list, int size);
void initBingoBoard(int board[][COLS], int *numList, int size);
void printBingoBoard(int board[][COLS]);

int main() {
  int bingoBoard[ROWS][COLS];
  int randNumList[MAX_RAND_NUM];
  
  srand(time(NULL));

  // Fill up an array with unique random numbers
  genUniqueRandNum(randNumList, MAX_RAND_NUM);

  // Initialize the bingo board
  initBingoBoard(bingoBoard, randNumList, MAX_RAND_NUM);
  
  // Print out the initialized bingo board
  printBingoBoard(bingoBoard);
  
  return 0;
}

// This function accepts an array and its size
// and fills it up with unique random numbers 
void genUniqueRandNum(int *list, int size) {
  for (int i = 0; i < size; i++) {
    int num = (rand() % size) + 1;
    for (int j = 0; j < i; j++) {
      if (list[j] == num) {
        num = (rand() % size) + 1;
        j = -1;
      }
    }
    list[i] = num;
  }
}

// This function accepts an empty bingo board, an array of unique random numbers,
// and the size of the array. It then initializes the bingo board with the random numbers.
void initBingoBoard(int board[][COLS], int *numList, int size) {
  int numCounter = 0;

  // Initialize the board with 0's
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      board[row][col] = 0;
    }
  }

  // Place the random numbers in the first column of the board in ascending order
  for (int row = 0; row < ROWS; row++) {
    board[row][0] = numList[numCounter];
    numCounter++;
  }
  
  // Shuffle the rest of the numbers and place them on the board
  for (int col = 1; col < COLS; col++) {
    genUniqueRandNum(numList, size);
    for (int row = 0; row < ROWS; row++) {
      board[row][col] = numList[numCounter];
      numCounter++;
    }
  }

  // Replace the center free space with a "FREE" string
  board[ROWS / 2][COLS / 2] = -1;
}

// This function accepts the bingo board and prints it out in a nice formatted way
void printBingoBoard(int board[][COLS]) {
  printf("\nBINGO BOARD\n");
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (board[row][col] == -1) {
        printf("%-8s", "FREE");
      } else {
        printf("%-8d", board[row][col]);
      }
    }
    printf("\n");
  }
}