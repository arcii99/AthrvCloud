//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
  printf("Welcome to Bingo Simulator!\n");

  // Generate bingo card numbers from 1 to 25
  int card[ROWS][COLS];
  srand(time(NULL));
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      card[i][j] = rand() % 25 + 1;
    }
  }

  printf("\nYour bingo card:\n");
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printf("%d\t", card[i][j]);
    }
    printf("\n");
  }

  // Generate random bingo numbers from 1 to 25
  int bingoNumbers[25];
  for(int i = 0; i < 25; i++) {
    bingoNumbers[i] = i + 1;
  }
  for(int i = 0; i < 25; i++) {
    int temp = bingoNumbers[i];
    int randomIndex = rand() % 25;
    bingoNumbers[i] = bingoNumbers[randomIndex];
    bingoNumbers[randomIndex] = temp;
  }

  // Check if any bingo numbers match card numbers
  int matchedCount = 0;
  for(int i = 0; i < 25; i++) {
    printf("\nBingo number: %d\n", bingoNumbers[i]);
    for(int j = 0; j < ROWS; j++) {
      for(int k = 0; k < COLS; k++) {
        if(bingoNumbers[i] == card[j][k]) {
          card[j][k] = 0;
          matchedCount++;
          break;
        }
      }
    }
    if(matchedCount == ROWS * COLS) {
      printf("\nBINGO! You win!\n");
      return 0;
    }
  }

  printf("\nSorry, you didn't get a BINGO.\n");

  return 0;
}