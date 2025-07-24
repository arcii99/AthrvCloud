//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void display_board(int board[ROWS][COLS]);
int check_bingo(int board[ROWS][COLS]);

int main() {
  int board[ROWS][COLS];
  int num_calls = 0;
  int play_again = 1;
  srand(time(NULL));
  
  printf("Welcome to BINGO SIMULATOR!\n");

  while (play_again) {
    // Initialize board
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        board[i][j] = rand() % 11 + (j * 10);
      }
    }

    // Display board
    printf("\n\nHere is your bingo board:\n");
    display_board(board);
    
    // Play the game
    int winner = 0;
    while (!winner) {
      int call = rand() % 51;
      num_calls++;

      // Check for called number on board
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          if (board[i][j] == call) {
            board[i][j] = -1;
          }
        }
      }

      // Display called number
      printf("\n\nThe number called is %d.\n", call);

      // Display updated board
      display_board(board);

      // Check for winner
      winner = check_bingo(board);
    }

    // Display winner message and stats
    printf("\n\nBINGO!!!\n\n");
    if (num_calls == 1) {
      printf("It took %d call to get a bingo!\n", num_calls);
    }
    else {
      printf("It took %d calls to get a bingo!\n", num_calls);
    }

    // Prompt to play again
    char play_again_input;
    printf("\n\nWould you like to play again? (y/n): ");
    scanf(" %c", &play_again_input);
    if (play_again_input == 'n') {
      play_again = 0;
      printf("\n\nThanks for playing Bingo Simulator!\n");
    }
    
    num_calls = 0;
  }

  return 0;
}

// Display the Bingo board
void display_board(int board[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    printf("--------------------\n|");
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == -1) {
        printf("  X ");
      }
      else {
        printf(" %2d ", board[i][j]);
      }
      printf("|");
    }
    printf("\n");
  }
  printf("--------------------\n");
}

// Check for Bingo
int check_bingo(int board[ROWS][COLS]) {
  int bingo = 0;
  
  // Check for horizontal bingo
  for (int i = 0; i < ROWS; i++) {
    int count = 0;
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == -1) {
        count++;
      }
    }
    if (count == 5) {
      bingo = 1;
    }
  }

  // Check for vertical bingo
  for (int i = 0; i < COLS; i++) {
    int count = 0;
    for (int j = 0; j < ROWS; j++) {
      if (board[j][i] == -1) {
        count++;
      }
    }
    if (count == 5) {
      bingo = 1;
    }
  }

  // Check for diagonal bingos
  if ((board[0][0] == -1) && (board[1][1] == -1) && (board[2][2] == -1) && (board[3][3] == -1) && (board[4][4] == -1)) {
    bingo = 1;
  }
  if ((board[0][4] == -1) && (board[1][3] == -1) && (board[2][2] == -1) && (board[3][1] == -1) && (board[4][0] == -1)) {
    bingo = 1;
  }

  return bingo;
}