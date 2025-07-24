//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5  // number of rows in the bingo card
#define COLS 5  // number of columns in the bingo card

int main() {
  int bingoCard[ROWS][COLS];  // declare the bingo card
  int i, j, num;
  int numCount[75] = {0};  // array to keep track of how many times each number has been called

  // initialize the random number generator
  srand(time(0));

  // fill the bingo card with random numbers
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      num = rand() % 75 + 1;  // generate a random number between 1 and 75
      bingoCard[i][j] = num;
    }
  }

  // print the initial bingo card
  printf("Initial Bingo Card:\n");
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%2d ", bingoCard[i][j]);
    }
    printf("\n");
  }
  
  // play the game
  int numCalled = 0;
  int bingo = 0;
  int rowSum, colSum, diagSum1 = 0, diagSum2 = 0;

  while (!bingo) {
    num = rand() % 75 + 1;  // generate a random number between 1 and 75
    if (numCount[num - 1] == 0) {
      numCount[num - 1] = 1;
      numCalled++;
      printf("Number called: %d\n", num);

      // check if the number is on the bingo card
      for (i = 0; i < ROWS; i++) {
        rowSum = 0;
        colSum = 0;
        for (j = 0; j < COLS; j++) {
          if (bingoCard[i][j] == num) {
            bingoCard[i][j] = 0;  // mark the number as called on the bingo card
          }
          rowSum += bingoCard[i][j];
          colSum += bingoCard[j][i];
          if (i == j) {
            diagSum1 += bingoCard[i][j];
          }
          if (i+j == ROWS-1) {
            diagSum2 += bingoCard[i][j];
          }
        }
        if (rowSum == 0 || colSum == 0) {
          bingo = 1;  // bingo! a row or column has been completed
          printf("Bingo! %s\n", rowSum == 0 ? "Row" : "Column");
          break;
        }
      }
      // check if a diagonal has been completed
      if (diagSum1 == 0 || diagSum2 == 0) {
        bingo = 1;
        printf("Bingo! Diagonal\n");
        break;
      }

      // print the updated bingo card
      printf("Updated Bingo Card:\n");
      for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
          printf("%2d ", bingoCard[i][j]);
        }
        printf("\n");
      }

      if (numCalled == 75) {
        printf("Game over; no one wins.\n");
        return 0;
      }
    }
  }

  printf("Game over; winner is found!\n");
  return 0;
}