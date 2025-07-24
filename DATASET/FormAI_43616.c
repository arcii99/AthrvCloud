//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Initialize variables
  int card[5][5];
  int numList[75], calledNum[75], numCalled = 0, i, j, k, win = 0;
  
  // Set 2D array to 0
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      card[i][j] = 0;
    }
  }

  // Populate array with numbers 1-75
  for (k = 0; k < 75; k++) {
    numList[k] = k + 1;
  }

  // Shuffle array for randomness
  for (i = 0; i < 75; i++) {
    int temp = numList[i];
    int randomIndex = rand() % 75;
    numList[i] = numList[randomIndex];
    numList[randomIndex] = temp;
  }
  
  // Display empty bingo card
  printf("B  I  N  G  O\n"); 
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (i == 2 && j == 2) {
        printf(" F ");
      } else {
        printf("%2d ", card[i][j]);
      }
    }
    printf("\n");
  }
  
  // Main game loop
  while (win == 0) {
    
    // Get next randomly called number
    int nextNum = numList[numCalled];
    calledNum[numCalled] = nextNum;
    numCalled++;
    
    // Check for number on bingo card and update card
    for (i = 0; i < 5; i++) {
      for (j = 0; j < 5; j++) {
        if (card[i][j] == nextNum) {
          card[i][j] = -1;
        }
      }
    }
    
    // Display updated bingo card
    printf("\nNext Number: %2d\n\n", nextNum);
    printf("B  I  N  G  O\n"); 
    for (i = 0; i < 5; i++) {
      for (j = 0; j < 5; j++) {
        if (card[i][j] == -1) {
          printf(" X ");
        } else if (i == 2 && j == 2) {
          printf(" F ");
        } else {
          printf("%2d ", card[i][j]);
        }
      }
      printf("\n");
    }
    
    // Check for win conditions
    int rowSum, colSum, diag1, diag2;
    for (i = 0; i < 5; i++) {
      
      // Check row
      rowSum = 0;
      for (j = 0; j < 5; j++) {
        rowSum += card[i][j];
      }
      if (rowSum == -5) {
        win = 1;
        printf("BINGO! You won on row %d.\n", i+1);
        break;
      }
      
      // Check column
      colSum = 0;
      for (j = 0; j < 5; j++) {
        colSum += card[j][i];
      }
      if (colSum == -5) {
        win = 1;
        printf("BINGO! You won on column %d.\n", i+1);
        break;
      }
      
      // Check diagonal 1
      diag1 += card[i][i];
      if (diag1 == -5) {
        win = 1;
        printf("BINGO! You won on diagonal 1.\n");
        break;
      }
      
      // Check diagonal 2
      diag2 += card[i][4-i];
      if (diag2 == -5) {
        win = 1;
        printf("BINGO! You won on diagonal 2.\n");
        break;
      }
    }
  }
  
  // Display called numbers
  printf("\nCalled Numbers: ");
  for (i = 0; i < 75; i++) {
    printf("%d ", calledNum[i]);
  }
  
  return 0;
}