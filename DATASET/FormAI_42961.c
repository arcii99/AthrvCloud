//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(int board[4][4]) {
  printf("   1  2  3  4\n");
  for (int i = 0; i < 4; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < 4; j++) {
      printf("[%d]", board[i][j]);
    }
    printf("\n");
  }
}

void play_game() {
  int board[4][4] = {{0}};
  int score = 0;
  int highest_tile = 0;
  int moves = 0;
  
  srand(time(NULL));
  
  // Add two random tiles to start the game
  for (int i = 0; i < 2; i++) {
    int row, col;
    do {
      row = rand() % 4;
      col = rand() % 4;
    } while (board[row][col]);
    board[row][col] = 2;
  }
  
  while (1) {
    printf("\nScore: %d\n", score);
    print_board(board);
    
    // Check for game over
    int game_over = 1;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (!board[i][j]) {
          game_over = 0;
          break;
        }
        if (i < 3 && board[i][j] == board[i+1][j]) {
          game_over = 0;
          break;
        }
        if (j < 3 && board[i][j] == board[i][j+1]) {
          game_over = 0;
          break;
        }
      }
    }
    if (game_over) {
      printf("\nGame over! Your final score is %d.\n", score);
      break;
    }
    
    // Get user input
    printf("\nEnter a move (wasd): ");
    char move;
    scanf(" %c", &move);
    
    // Move tiles
    int moved = 0;
    switch (move) {
      case 'w': // Up
        for (int col = 0; col < 4; col++) {
          for (int row = 1; row < 4; row++) {
            if (!board[row][col])
              continue;
            int new_row = row;
            while (new_row > 0 && !board[new_row-1][col]) {
              new_row--;
            }
            if (new_row != row) {
              board[new_row][col] = board[row][col];
              board[row][col] = 0;
              moved = 1;
            } else if (new_row > 0 && board[new_row-1][col] == board[row][col]) {
              board[new_row-1][col] *= 2;
              score += board[new_row-1][col];
              board[row][col] = 0;
              if (board[new_row-1][col] > highest_tile) {
                highest_tile = board[new_row-1][col];
              }
              moved = 1;
            }
          }
        }
        break;
        
      case 's': // Down
        for (int col = 0; col < 4; col++) {
          for (int row = 2; row >= 0; row--) {
            if (!board[row][col])
              continue;
            int new_row = row;
            while (new_row < 3 && !board[new_row+1][col]) {
              new_row++;
            }
            if (new_row != row) {
              board[new_row][col] = board[row][col];
              board[row][col] = 0;
              moved = 1;
            } else if (new_row < 3 && board[new_row+1][col] == board[row][col]) {
              board[new_row+1][col] *= 2;
              score += board[new_row+1][col];
              board[row][col] = 0;
              if (board[new_row+1][col] > highest_tile) {
                highest_tile = board[new_row+1][col];
              }
              moved = 1;
            }
          }
        }
        break;
        
      case 'a': // Left
        for (int row = 0; row < 4; row++) {
          for (int col = 1; col < 4; col++) {
            if (!board[row][col])
              continue;
            int new_col = col;
            while (new_col > 0 && !board[row][new_col-1]) {
              new_col--;
            }
            if (new_col != col) {
              board[row][new_col] = board[row][col];
              board[row][col] = 0;
              moved = 1;
            } else if (new_col > 0 && board[row][new_col-1] == board[row][col]) {
              board[row][new_col-1] *= 2;
              score += board[row][new_col-1];
              board[row][col] = 0;
              if (board[row][new_col-1] > highest_tile) {
                highest_tile = board[row][new_col-1];
              }
              moved = 1;
            }
          }
        }
        break;
        
      case 'd': // Right
        for (int row = 0; row < 4; row++) {
          for (int col = 2; col >= 0; col--) {
            if (!board[row][col])
              continue;
            int new_col = col;
            while (new_col < 3 && !board[row][new_col+1]) {
              new_col++;
            }
            if (new_col != col) {
              board[row][new_col] = board[row][col];
              board[row][col] = 0;
              moved = 1;
            } else if (new_col < 3 && board[row][new_col+1] == board[row][col]) {
              board[row][new_col+1] *= 2;
              score += board[row][new_col+1];
              board[row][col] = 0;
              if (board[row][new_col+1] > highest_tile) {
                highest_tile = board[row][new_col+1];
              }
              moved = 1;
            }
          }
        }
        break;
    }
    
    // Add a new random tile if a move was made
    if (moved) {
      int row, col;
      do {
        row = rand() % 4;
        col = rand() % 4;
      } while (board[row][col]);
      board[row][col] = (rand() % 10 == 0) ? 4 : 2;
      moves++;
    }
  }
}

int main() {
  printf("Welcome to 2048!\n\n");
  printf("Instructions: Use the wasd keys to move all tiles in one direction. When two tiles with the same number touch, they merge into one!\n\n");
  
  while (1) {
    printf("Press enter to play a game, or q to quit.\n");
    char input[10];
    fgets(input, 10, stdin);
    if (input[0] == 'q') {
      break;
    } else {
      play_game();
    }
  }
  
  return 0;
}