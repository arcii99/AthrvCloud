//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main() {
  int i, j, r, c, temp, count, player, num_bingo;
  int bingo[ROWS][COLS];
  int picked[ROWS*COLS];
  player = 1;
  count = 0;
  num_bingo = 0;
  srand(time(NULL));
  
  // Initialize the bingo array with unique random numbers
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      do {
        temp = (rand() % 15) + j*15 + 1;
      } while (temp == bingo[0][j] || temp == bingo[1][j] || temp == bingo[2][j] || temp == bingo[3][j] || temp == bingo[4][j]);
      bingo[i][j] = temp;
    }
  }
  
  // Print the bingo board
  printf("---------BINGO BOARD---------\n");
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%d\t", bingo[i][j]);
    }
    printf("\n");
  }
  printf("-----------------------------\n\n");

  // Start the game
  while (num_bingo < 5) {
    // Print the player number
    printf("Player %d's turn\n", player);
    
    // Pick a random number
    do {
      temp = (rand() % 75) + 1;
    } while (picked[temp] == 1);
    printf("Picked number: %d\n", temp);
    picked[temp] = 1;
    
    // Check if the number exists on the bingo board
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
        if (bingo[i][j] == temp) {
          bingo[i][j] = -1; // Mark the number as picked
          count++;
          break;
        }
      }
    }
    
    // Print the updated bingo board
    printf("---------BINGO BOARD---------\n");
    for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
        if (bingo[i][j] == -1) {
          printf("X\t");
        } else {
          printf("%d\t", bingo[i][j]);
        }
      }
      printf("\n");
    }
    printf("-----------------------------\n\n");
    
    // Check if the player has a bingo
    if (count >= 5) {
      // Check rows
      for (i = 0; i < ROWS; i++) {
        int row_sum = 0;
        for (j = 0; j < COLS; j++) {
          row_sum += bingo[i][j];
        }
        if (row_sum == -5) {
          num_bingo++;
        }
      }
      
      // Check columns
      for (j = 0; j < COLS; j++) {
        int col_sum = 0;
        for (i = 0; i < ROWS; i++) {
          col_sum += bingo[i][j];
        }
        if (col_sum == -5) {
          num_bingo++;
        }
      }
      
      // Check diagonals
      if (bingo[0][0] == -1 && bingo[1][1] == -1 && bingo[2][2] == -1 && bingo[3][3] == -1 && bingo[4][4] == -1) {
        num_bingo++;
      }
      if (bingo[0][4] == -1 && bingo[1][3] == -1 && bingo[2][2] == -1 && bingo[3][1] == -1 && bingo[4][0] == -1) {
        num_bingo++;
      }
      
      // Print the result
      printf("***BINGO! Player %d has %d bingos!***\n", player, num_bingo);
      if (num_bingo == 5) {
        printf("***PLAYER %d WINS THE GAME!***\n", player);
        break;
      }
    }
    
    // Switch to the next player
    if (player == 1) {
      player = 2;
    } else {
      player = 1;
    }
  }
  
  return 0;
}