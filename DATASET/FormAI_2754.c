//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void printTable(char table[][3]);
void initTable(char table[][3]);
int checkWin(char table[][3], char player);
int checkHorizontal(char table[][3], char player);
int checkVertical(char table[][3], char player);
int checkDiagonal(char table[][3], char player);
void playerMove(char table[][3], char player);
void computerMove(char table[][3]);
int checkTie(char table[][3]);

int main() {
  srand(time(NULL));     // seed the random number generator
  char table[3][3];
  char player = 'X';
  int win, tie;           // flags for win and tie
  
  initTable(table);       // initialize the table
  printTable(table);      // display the initial table

  // game loop
  while (1) {
    playerMove(table, player);      // player moves first
    win = checkWin(table, player);  // check if player won
    tie = checkTie(table);          // check if tie
    if (win || tie) break;          // if game is over, break out of loop

    computerMove(table);            // computer moves second
    win = checkWin(table, 'O');      // check if computer won
    tie = checkTie(table);          // check if tie
    if (win || tie) break;          // if game is over, break out of loop
  }

  // print out message depending on result of game
  if (win) {
    if (player == 'X')
      printf("Congratulations! You won!\n");
    else
      printf("Sorry, you lost. Better luck next time!\n");
  } else {
    printf("The game ends in a tie.\n");
  }

  return 0;
}

// prints out the table
void printTable(char table[][3]) {
  printf("\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%c\t", table[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// initializes the table to empty spaces
void initTable(char table[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      table[i][j] = ' ';
    }
  }
}

// checks if either player has won
int checkWin(char table[][3], char player) {
  if (checkHorizontal(table, player)) return 1;
  if (checkVertical(table, player)) return 1;
  if (checkDiagonal(table, player)) return 1;
  return 0;
}

// checks if there is a winning horizontal row
int checkHorizontal(char table[][3], char player) {
  for (int i = 0; i < 3; i++) {
    if (table[i][0] == player && table[i][1] == player && table[i][2] == player)
      return 1;
  }
  return 0;
}

// checks if there is a winning vertical row
int checkVertical(char table[][3], char player) {
  for (int i = 0; i < 3; i++) {
    if (table[0][i] == player && table[1][i] == player && table[2][i] == player)
      return 1;
  }
  return 0;
}

// checks if there is a winning diagonal
int checkDiagonal(char table[][3], char player) {
  if (table[0][0] == player && table[1][1] == player && table[2][2] == player)
    return 1;
  if (table[0][2] == player && table[1][1] == player && table[2][0] == player)
    return 1;
  return 0;
}

// handles the player's move
void playerMove(char table[][3], char player) {
  int row, col;
  printf("Enter the row and column where you want to place your '%c': ", player);
  scanf("%d %d", &row, &col);

  // check if the move is valid
  while (row < 1 || row > 3 || col < 1 || col > 3 || table[row-1][col-1] != ' ') {
    printf("Invalid move. Please try again.\n");
    printf("Enter the row and column where you want to place your '%c': ", player);
    scanf("%d %d", &row, &col);
  }

  // set the move on the table
  table[row-1][col-1] = player;
  printTable(table);  // display the updated table
}

// handles the computer's move
void computerMove(char table[][3]) {
  int row, col;

  // keep generating random moves until a valid one is found
  while (1) {
    row = rand() % 3;
    col = rand() % 3;
    if (table[row][col] == ' ') break;
  }

  // set the move on the table
  table[row][col] = 'O';
  printf("The computer places an 'O' at row %d, column %d.\n", row+1, col+1);
  printTable(table);  // display the updated table
}

// checks if the game is a tie
int checkTie(char table[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (table[i][j] == ' ')  // if any empty space is found, game is not over
        return 0;
    }
  }
  return 1;  // if no empty spaces found, game is a tie
}