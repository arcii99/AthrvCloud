//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIDE 3 // Size of the board

char board[SIDE][SIDE];
char computer = 'O';
char player = 'X';
bool isGameOver = false;

void initBoard() {
  for (int i = 0; i < SIDE; i++) {
    for (int j = 0; j < SIDE; j++) {
      board[i][j] = '-';
    }
  }
}

void showBoard() {
  printf("\n\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
  printf("     |     |     \n");
  printf("\n\n");
}

bool isMovesLeft() {
  for (int i = 0; i < SIDE; i++) {
    for (int j = 0; j < SIDE; j++) {
      if (board[i][j] == '-') {
        return true;
      }
    }
  }
  return false;
}

bool checkWin(char player) {
  // Check rows
  for (int i = 0; i < SIDE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }

  // Check columns
  for (int j = 0; j < SIDE; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

int evaluate() {
  // Check for a win
  if (checkWin(computer)) {
    return 10;
  } else if (checkWin(player)) {
    return -10;
  } else {
    return 0;
  }
}

int minimax(int depth, bool isMaximizer) {
  int score = evaluate();

  if (score == 10) return score;
  if (score == -10) return score;

  // No moves left
  if (!isMovesLeft()) return 0;

  if (isMaximizer) {
    int best = -1000;
    for (int i = 0; i < SIDE; i++) {
      for (int j = 0; j < SIDE; j++) {
        if (board[i][j] == '-') {
          board[i][j] = computer;
          best = fmax(best, minimax(depth + 1, !isMaximizer));
          board[i][j] = '-';
        }
      }
    }
    return best;
  } else {
    int best = 1000;
    for (int i = 0; i < SIDE; i++) {
      for (int j = 0; j < SIDE; j++) {
        if (board[i][j] == '-') {
          board[i][j] = player;
          best = fmin(best, minimax(depth + 1, !isMaximizer));
          board[i][j] = '-';
        }
      }
    }
    return best;
  }
}

void computerMove() {
  int bestVal = -1000;
  int row = -1;
  int col = -1;

  for (int i = 0; i < SIDE; i++) {
    for (int j = 0; j < SIDE; j++) {
      if (board[i][j] == '-') {
        board[i][j] = computer;
        int moveVal = minimax(0, false);
        board[i][j] = '-';

        if (moveVal > bestVal) {
          row = i;
          col = j;
          bestVal = moveVal;
        }
      }
    }
  }

  board[row][col] = computer;
}

void playerMove() {
  int row, col;
  printf("Enter row and column (0 - 2): ");
  scanf("%d %d", &row, &col);

  while (row < 0 || row >= SIDE || col < 0 || col >= SIDE || board[row][col] != '-') {
    printf("Invalid move. Try again.\n");
    printf("Enter row and column (0 - 2): ");
    scanf("%d %d", &row, &col);
  }

  board[row][col] = player;
}

void playGame() {
  bool playerTurn = true;
  int moves = 0;

  initBoard();
  showBoard();

  while (!isGameOver) {
    if (playerTurn) {
      playerMove();
    } else {
      computerMove();
    }

    showBoard();
    moves++;

    if (checkWin(player)) {
      printf("Congratulations! You win!\n");
      isGameOver = true;
    } else if (checkWin(computer)) {
      printf("Sorry, you lose. Try again!\n");
      isGameOver = true;
    } else if (!isMovesLeft()) {
      printf("It's a tie!\n");
      isGameOver = true;
    } else {
      playerTurn = !playerTurn;
    }
  }
}

int main() {
  printf("Welcome to Tic Tac Toe AI - Expert Level!\n");
  printf("-----------------------------------------\n\n");

  playGame();

  return 0;
}