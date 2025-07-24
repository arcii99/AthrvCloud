//FormAI DATASET v1.0 Category: Memory Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

void initialize_board(char board[][COLS]) {
  // initialize the board with values A-L
  char letter = 'A';
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      board[row][col] = letter;
      letter++;
    }
  }
}

void print_board(char board[][COLS], int revealed[][COLS]) {
  // print the board, showing revealed letters where applicable
  printf("\n");
  printf("  1 2 3 4 5\n");
  for (int row = 0; row < ROWS; row++) {
    printf("%d ", row+1);
    for (int col = 0; col < COLS; col++) {
      if (revealed[row][col]) {
        printf("%c ", board[row][col]);
      } else {
        printf("? ");
      }
    }
    printf("\n");
  }
}

void shuffle_board(char board[][COLS]) {
  // shuffle the board by swapping pairs of random elements
  for (int i = 0; i < 100; i++) {
    int row1 = rand() % ROWS;
    int col1 = rand() % COLS;
    int row2 = rand() % ROWS;
    int col2 = rand() % COLS;
    char temp = board[row1][col1];
    board[row1][col1] = board[row2][col2];
    board[row2][col2] = temp;
  }
}

int main() {
  char board[ROWS][COLS];
  int revealed[ROWS][COLS] = {0};
  int score = 0;
  
  srand(time(NULL));
  
  initialize_board(board);
  shuffle_board(board);
  
  while (score < 10) {
    print_board(board, revealed);
    
    int row1, col1, row2, col2;
    
    printf("Enter the row and column of the first card: ");
    scanf("%d %d", &row1, &col1);
    row1--;
    col1--;
    revealed[row1][col1] = 1;
    print_board(board, revealed);
    
    printf("Enter the row and column of the second card: ");
    scanf("%d %d", &row2, &col2);
    row2--;
    col2--;
    revealed[row2][col2] = 1;
    print_board(board, revealed);
    
    if (board[row1][col1] == board[row2][col2]) {
      printf("You found a match!\n");
      score++;
      revealed[row1][col1] = 2;
      revealed[row2][col2] = 2;
    } else {
      printf("Sorry, no match!\n");
      revealed[row1][col1] = 0;
      revealed[row2][col2] = 0;
    }
  }
  
  printf("Congratulations, you won with a score of %d!\n", score);
  
  return 0;
}