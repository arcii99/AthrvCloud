//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10
#define BULLET_ROW 2
#define BULLET_COL 4

void drawBoard(char board[ROWS][COLS]) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char board[ROWS][COLS];
  int i, j;
  
  // initialize board with blank spaces
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      board[i][j] = ' ';
    }
  }
  
  // initialize player
  int playerRow = ROWS-1;
  int playerCol = COLS/2;
  board[playerRow][playerCol] = 'P';
  
  // initialize bullets
  int bulletRow = BULLET_ROW;
  int bulletCol = BULLET_COL;
  board[bulletRow][bulletCol] = '*';
  
  // initialize enemies
  srand(time(0));
  int randRow, randCol;
  for (i = 0; i < ROWS-1; i++) {
    randRow = rand() % (ROWS-1);
    randCol = rand() % COLS;
    board[randRow][randCol] = 'E';
  }
  
  // print initial board
  drawBoard(board);
  
  // main game loop
  char input;
  while (1) {
    input = getchar();
    switch (input) {
      case 'a': 
        if (playerCol > 0) {
          board[playerRow][playerCol] = ' ';
          playerCol--;
          board[playerRow][playerCol] = 'P';
        }
        break;
        
      case 'd': 
        if (playerCol < COLS-1) {
          board[playerRow][playerCol] = ' ';
          playerCol++;
          board[playerRow][playerCol] = 'P';
        }
        break;
        
      case 'w': 
        board[bulletRow][bulletCol] = ' ';
        bulletRow--;
        board[bulletRow][bulletCol] = '*';
        break;
        
      case 'q': 
        exit(0);
        break;
    }
    
    // update enemy positions
    for (i = 0; i < ROWS-1; i++) {
      for (j = 0; j < COLS; j++) {
        if (board[i][j] == 'E') {
          board[i][j] = ' ';
          board[i+1][j] = 'E';
        }
      }
    }
    
    // check for bullet collisions
    if (board[bulletRow][bulletCol] == 'E') {
      board[bulletRow][bulletCol] = ' ';
      bulletRow = BULLET_ROW;
      bulletCol = playerCol;
      board[bulletRow][bulletCol] = '*';
    }
    
    // check for player collisions
    if (board[playerRow][playerCol] == 'E') {
      printf("Game over!\n");
      exit(0);
    }
    
    // print updated board
    printf("\033[H\033[J");
    drawBoard(board);
  }
  
  return 0;
}