//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The Bingo board is represented as a 2D array.
int board[5][5];

// Function to print the Bingo board.
void print_board() {
  for(int row=0; row<5; row++) {
    for(int col=0; col<5; col++) {
      printf("| ");
      if(board[row][col] == -1) {
        printf("  ");
      } else {
        printf("%d ", board[row][col]);
      }
    }
    printf("|\n");
  }
  printf("\n");
}

// Function to check if the board has a Bingo.
int bingo() {
  for(int row=0; row<5; row++) {
    int row_count = 0;
    for(int col=0; col<5; col++) {
      if(board[row][col] == -1) {
        row_count++;
      }
    }
    if(row_count == 5) {
      return 1;
    }
  }

  for(int col=0; col<5; col++) {
    int col_count = 0;
    for(int row=0; row<5; row++) {
      if(board[row][col] == -1) {
        col_count++;
      }
    }
    if(col_count == 5) {
      return 1;
    }
  }

  int diag_count1 = 0;
  for(int i=0; i<5; i++) {
    if(board[i][i] == -1) {
      diag_count1++;
    }
  }
  if(diag_count1 == 5) {
    return 1;
  }

  int diag_count2 = 0;
  for(int i=0; i<5; i++) {
    if(board[i][4-i] == -1) {
      diag_count2++;
    }
  }
  if(diag_count2 == 5) {
    return 1;
  }

  return 0;
}

// Main function
int main() {
  // Initialize the board with random numbers.
  srand(time(NULL));
  for(int row=0; row<5; row++) {
    for(int col=0; col<5; col++) {
      board[row][col] = 15*row + rand()%15 + 1;
    }
  }
  board[2][2] = -1; // Mark the center as "FREE".

  // Print the initial board.
  printf("Let's play Bingo!\n");
  print_board();

  // Play the game.
  int count = 0;
  while(!bingo()) {
    int num = rand()%75 + 1;
    printf("Next number: %d\n", num);
    for(int row=0; row<5; row++) {
      for(int col=0; col<5; col++) {
        if(board[row][col] == num) {
          board[row][col] = -1;
          count++;
        }
      }
    }
    printf("Numbers called: %d\n", count);
    print_board();
  }

  // End of game.
  printf("Bingo! You win!\n");

  return 0;
}