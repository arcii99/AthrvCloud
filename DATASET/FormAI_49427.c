//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdio.h>

char board[3][3];
char player = 'X';

void print_board() {
  printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int check_win() {
  int i, j;

  for (i = 0; i < 3; i++)
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
      return board[i][0];

  for (i = 0; i < 3; i++)
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
      return board[0][i];

  if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    return board[0][0];

  if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return board[0][2];

  return '\0';
}

int minimax(char player) {
  int i, j, score;
  char winner = check_win();

  if (winner == 'X') return 10;
  if (winner == 'O') return -10;

  int move_i = -1, move_j = -1;
  int best_score = (player == 'X') ? -100 : 100;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = player;
        if (player == 'X') {
          score = minimax('O');
          if (score > best_score) {
            best_score = score;
            move_i = i;
            move_j = j;
          }
        } else {
          score = minimax('X');
          if (score < best_score) {
            best_score = score;
            move_i = i;
            move_j = j;
          }
        }
        board[i][j] = ' ';
      }
    }
  }

  if (player == 'X') {
    return best_score;
  } else {
    return best_score;
  }
}

int main() {
  int x, y;

  for (x = 0; x < 3; x++)
    for (y = 0; y < 3; y++)
      board[x][y] = ' ';

  // The following is the game loop
  while (1) {
    printf("\n");
    print_board();
    printf("\nEnter x, y coordinates: ");
    scanf("%d %d", &x, &y);

    if (board[x][y] != ' ') {
      printf("Invalid move! Try again.\n");
    } else {
      board[x][y] = 'X';
      if (check_win() == 'X') {
        printf("\nYou win!\n");
        print_board();
        break;
      }
    
      printf("Computer is thinking...");
      
      minimax('O');

      int best_score = -100;
      int move_i = -1, move_j = -1;
      
      for (x = 0; x < 3; x++) {
        for (y = 0; y < 3; y++) {
          if (board[x][y] == ' ') {
            board[x][y] = 'O';
            int score = minimax('X');
            if (score > best_score) {
              best_score = score;
              move_i = x;
              move_j = y;
            }
            board[x][y] = ' ';
          }
        }
      }

      board[move_i][move_j] = 'O';

      if (check_win() == 'O') {
        printf("\nComputer wins!\n");
        print_board();
        break;
      }
    }
  }

  return 0;
}