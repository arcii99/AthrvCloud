//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>

#define EASY 1
#define MEDIUM 2
#define HARD 3

int difficulty_level;
char board[3][3];

void init_board(void) {
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      board[i][j] = ' ';
}

void print_board(void) {
  printf("\n");
  printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
  printf("\n");
}

void get_input(int *row, int *col) {
  printf("Enter row (0-2): ");
  scanf("%d", row);
  printf("Enter column (0-2): ");
  scanf("%d", col);
}

int check_winner(void) {
  int i;

  /* check rows */
  for (i = 0; i < 3; i++) {
    if (board[i][0] != ' ' &&
        board[i][0] == board[i][1] &&
        board[i][0] == board[i][2])
      return 1;
  }

  /* check columns */
  for (i = 0; i < 3; i++) {
    if (board[0][i] != ' ' &&
        board[0][i] == board[1][i] &&
        board[0][i] == board[2][i])
      return 1;
  }

  /* check diagonals */
  if (board[0][0] != ' ' &&
      board[0][0] == board[1][1] &&
      board[0][0] == board[2][2])
    return 1;

  if (board[2][0] != ' ' &&
      board[2][0] == board[1][1] &&
      board[2][0] == board[0][2])
    return 1;

  return 0;
}

int minimax(int depth, int player) {
  int i, score, best_row = -1, best_col = -1;
  int max_score = (player == 1) ? 1 : -1;

  if (depth == 0 || check_winner()) {
    if (check_winner())
      return (player == 1) ? -1 : 1;
    return 0;
  }

  for (i = 0; i < 3; i++) {
    int j;
    for (j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = (player == 1) ? 'X' : 'O';
        score = minimax(depth - 1, -player);
        board[i][j] = ' ';

        if (player == 1 && score > max_score) {
          max_score = score;
          best_row = i;
          best_col = j;
        } else if (player == -1 && score < max_score) {
          max_score = score;
          best_row = i;
          best_col = j;
        }
      }
    }
  }

  if (depth == difficulty_level)
    return (best_row << 16) | (best_col << 8) | max_score;

  return max_score;
}

void computer_move(void) {
  int row, col, score;

  score = minimax(difficulty_level, 1);

  row = (score >> 16) & 0xff;
  col = (score >> 8) & 0xff;

  board[row][col] = 'O';
}

int main(void) {
  int turn;
  int row, col;
  init_board();
  printf("Enter difficulty level (1-easy, 2-medium, 3-hard): ");
  scanf("%d", &difficulty_level);
  turn = 0;

  while (!check_winner() && turn < 9) {
    print_board();

    if (turn % 2 == 0) {
      get_input(&row, &col);
      if (board[row][col] == ' ') {
        board[row][col] = 'X';
        turn++;
      } else {
        printf("That space is already taken. Try again!\n");
      }
    } else {
      printf("Computer's turn:\n");
      computer_move();
      turn++;
    }
  }

  print_board();

  if (check_winner())
    printf("Congratulations! You won!\n");
  else
    printf("The game is a draw.\n");

  return 0;
}