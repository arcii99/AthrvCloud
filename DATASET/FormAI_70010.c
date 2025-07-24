//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

char board[8][8] = {{' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
                    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
                    {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
                    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
                    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '}};

void print_board() {
  printf(" -----------------\n");
  for (int i = 0; i < 8; i++) {
    printf("%d|", i+1);
    for (int j = 0; j < 8; j++) {
      printf("%c|", board[i][j]);
    }
    printf("\n");
    printf(" -----------------\n");
  }
  printf("   a b c d e f g h\n");
}

// function to check if move is valid
int is_valid_move(int player, int x1, int y1, int x2, int y2) {
  if (board[x2][y2] != ' ' || (x1 + y1) % 2 != (x2 + y2) % 2 || board[x1][y1] == ' ')
    return 0;

  // check if regular move
  if (abs(x2 - x1) == 1) {
    if (player == 1 && x2 > x1)
      return 0;
    if (player == -1 && x2 < x1)
      return 0;
    if (abs(y2 - y1) == 1)
      return 1;
    // check if jump
    if (abs(y2 - y1) == 2 && board[(x1 + x2) / 2][(y1 + y2) / 2] * player < 0)
      return 1;
  } else if (abs(x2 - x1) == 2) {
    if (player == 1 && x2 > x1)
      return 0;
    if (player == -1 && x2 < x1)
      return 0;
    if (abs(y2 - y1) == 2 && board[(x1 + x2) / 2][(y1 + y2) / 2] * player < 0)
      return 1;
  }
  return 0;
}

// function to make a move
void make_move(int player, int x1, int y1, int x2, int y2) {
  if (is_valid_move(player, x1, y1, x2, y2)) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = ' ';
    if (abs(x2 - x1) == 2) {
      board[(x1 + x2) / 2][(y1 + y2) / 2] = ' ';
    }
  }
}

// function to check if the game has ended
int game_ended() {
  int white = 0, black = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == 'b' || board[i][j] == 'B')
        black++;
      else if (board[i][j] == 'r' || board[i][j] == 'R')
        white++;
    }
  }
  if (white == 0 || black == 0)
    return 1;
  else
    return 0;
}

int convert(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c - 'A';
  } else {
    return c - 'a';
  }
}

int main() {
  int turns = 0, x1, y1, x2, y2;
  int player = 1;
  print_board();
  while (!game_ended()) {
    printf("Turn %d: Player %d\n", turns, player);
    printf("Enter move (e.g. a3 b4): ");
    scanf("%c%d %c%d", &y1, &x1, &y2, &x2);
    if (x1 < 1 || y1 < 0 || x2 < 1 || y2 < 0 || x1 > 8 || y1 > 7 || x2 > 8 || y2 > 7) {
      printf("Invalid move\n");
    } else {
      x1--;
      y1 = convert(y1);
      x2--;
      y2 = convert(y2);
      if (board[x1][y1] * player <= 0)
        printf("Invalid move\n");
      else {
        make_move(player, x1, y1, x2, y2);
        if (abs(x2 - x1) == 2) {
          // check for multiple jumps
          do {
            print_board();
            printf("Continue jump: ");
            scanf("%c%d %c%d", &y1, &x1, &y2, &x2);
            x1--;
            y1 = convert(y1);
            x2--;
            y2 = convert(y2);
            make_move(player, x1, y1, x2, y2);
          } while (abs(x2 - x1) == 2);
        }
        turns++;
        player *= -1;

        print_board();
      }
    }
  }
  printf("Game ended!\n");
  return 0;
}