//FormAI DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4

void generate_game_board(char game_board[][COL]) {
  int row, col;
  char alphabet = 'A';
  for(row = 0; row < ROW; row++) {
    for(col = 0; col < COL; col++) {
      game_board[row][col] = (char)(rand() % 26 + alphabet);
      printf("%c ", game_board[row][col]);
    }
    printf("\n");
  }
  printf("Alphabets generated. Time to shuffle things up...\n");
}

void shuffle_game_board(char game_board[][COL]) {
  int row1, col1, row2, col2;
  char temp;
  for(int count = 0; count < 20; count++) {
      row1 = rand() % ROW;
      col1 = rand() % COL;
      row2 = rand() % ROW;
      col2 = rand() % COL;

      temp = game_board[row1][col1];
      game_board[row1][col1] = game_board[row2][col2];
      game_board[row2][col2] = temp;
  }
  printf("Shuffling complete. Time to start the game...\n");
}

void display_game_board(char game_board[][COL], char hidden_board[][COL]) {
  int row, col;
  printf("\nCurrent game board: \n");
  for(row = 0; row < ROW; row++) {
    for(col = 0; col < COL; col++) {
      if(hidden_board[row][col] == ' ') {
        printf("%c ", game_board[row][col]);
      } else {
        printf("%c ", hidden_board[row][col]);
      }
    }
    printf("\n");
  }
}

int main(void) {
  char game_board[ROW][COL];
  char hidden_board[ROW][COL];
  int row1, col1, row2, col2;
  int moves = 0;
  int correct_matches = 0;
  char playagain;
  srand(time(NULL));
  generate_game_board(game_board);

  for(int i = 0; i < ROW; i++) {
    for(int j = 0; j < COL; j++) {
      hidden_board[i][j] = ' ';
    }
  }

  shuffle_game_board(game_board);

  do {
    while(correct_matches < 8) {
      printf("Enter coordinates of two different cards to turn over: ");
      scanf("%d%d%d%d", &row1, &col1, &row2, &col2);

      if(game_board[row1][col1] == game_board[row2][col2] && (row1 != row2 || col1 != col2)) {
        hidden_board[row1][col1] = game_board[row1][col1];
        hidden_board[row2][col2] = game_board[row2][col2];
        correct_matches++;
        printf("It's a match!\n");
        display_game_board(game_board, hidden_board);
        printf("Correct Matches: %d\n", correct_matches);
        printf("Moves: %d\n", ++moves);
      } else {
        printf("Sorry, it's not a match. Try again...\n");
        display_game_board(game_board, hidden_board);
        printf("Correct Matches: %d\n", correct_matches);
        printf("Moves: %d\n", ++moves);
      }
    }

    printf("Congratulations! You won the game in %d moves. Would you like to play again? (Y/N)\n", moves);
    scanf(" %c", &playagain);
    if(playagain == 'Y' || playagain == 'y') {
      printf("Starting a new game...\n");
      generate_game_board(game_board);
      shuffle_game_board(game_board);
      for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
          hidden_board[i][j] = ' ';
        }
      }
      moves = 0;
      correct_matches = 0;
    }
  } while (playagain == 'Y' || playagain == 'y');

  printf("Thanks for playing! Goodbye!");
  return 0;
}