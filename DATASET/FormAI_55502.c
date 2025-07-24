//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n = 10; //number of rows/columns
  int board[n][n]; //declare game board
  int player_score = 0; //initialize player score
  int computer_score = 0; //initialize computer score

  //initialize game board randomly
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] = rand() % 3; //0 = empty, 1 = player, 2 = computer
    }
  }

  printf("Welcome to the C table game!\n");

  //player's turn
  printf("Player's turn:\n");
  printf("Score: %d\n", player_score);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 1) {
        printf("X ");
      } else {
        printf("- ");
      }
    }
    printf("\n");
  }

  int row, col;
  do {
    printf("Enter row and column (0-9): ");
    scanf("%d %d", &row, &col);
    if (board[row][col] != 0) {
      printf("Invalid move. Try again.\n");
    }
  } while (board[row][col] != 0);
  
  board[row][col] = 1; //mark player's move on board
  player_score++;

  //computer's turn
  printf("Computer's turn:\n");
  printf("Score: %d\n", computer_score);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 2) {
        printf("O ");
      } else {
        printf("- ");
      }
    }
    printf("\n");
  }

  do {
    row = rand() % n;
    col = rand() % n;
  } while (board[row][col] != 0);
  
  board[row][col] = 2; //mark computer's move on board
  computer_score++;

  //game loop
  while (player_score < n && computer_score < n) {
    //player's turn
    printf("Player's turn:\n");
    printf("Score: %d\n", player_score);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 1) {
          printf("X ");
        } else {
          printf("- ");
        }
      }
      printf("\n");
    }

    do {
      printf("Enter row and column (0-9): ");
      scanf("%d %d", &row, &col);
      if (board[row][col] != 0) {
        printf("Invalid move. Try again.\n");
      }
    } while (board[row][col] != 0);
    
    board[row][col] = 1; //mark player's move on board
    player_score++;

    //check for winner
    if (player_score == n) {
      printf("Player wins!\n");
      break;
    }

    //computer's turn
    printf("Computer's turn:\n");
    printf("Score: %d\n", computer_score);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 2) {
          printf("O ");
        } else {
          printf("- ");
        }
      }
      printf("\n");
    }

    do {
      row = rand() % n;
      col = rand() % n;
    } while (board[row][col] != 0);
    
    board[row][col] = 2; //mark computer's move on board
    computer_score++;

    //check for winner
    if (computer_score == n) {
      printf("Computer wins!\n");
      break;
    }
  }

  //game over
  printf("Game over.\n");
  printf("Final score: Player = %d, Computer = %d\n", player_score, computer_score);

  return 0;
}