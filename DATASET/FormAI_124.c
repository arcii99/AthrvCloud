//FormAI DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum {EMPTY, BLACK, BLACK_KING, RED, RED_KING} Piece;

typedef struct {
  Piece board[BOARD_SIZE][BOARD_SIZE];
  int red_remaining;
  int black_remaining;
} Game;

void initialize_board(Game *game) {
  int i, j;

  // Initialize all pieces to empty
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      game->board[i][j] = EMPTY;
    }
  }

  // Initialize black pieces
  for (i = 0; i < 3; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (i % 2 == j % 2) {
        game->board[i][j] = BLACK;
        game->black_remaining++;
      }
    }
  }

  // Initialize red pieces
  for (i = 5; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      if (i % 2 == j % 2) {
        game->board[i][j] = RED;
        game->red_remaining++;
      }
    }
  }
}

void display(Game *game) {
  int i, j;

  printf("  ");
  for (i = 0; i < BOARD_SIZE; i++) {
    printf(" %d ", i + 1);
  }
  printf("\n");

  for (i = 0; i < BOARD_SIZE; i++) {
    printf(" %c ", 'a' + i);
    for (j = 0; j < BOARD_SIZE; j++) {
      switch (game->board[i][j]) {
        case BLACK:
          printf("|B ");
          break;
        case BLACK_KING:
          printf("|BK");
          break;
        case RED:
          printf("|R ");
          break;
        case RED_KING:
          printf("|RK");
          break;
        default:
          printf("|  ");
          break;
      }
    }
    printf("|\n");
  }
}

int is_legal_move(Game *game, int from_row, int from_col, int to_row, int to_col) {
  Piece piece = game->board[from_row][from_col];
  
  if (game->board[to_row][to_col] != EMPTY) {
    return 0; // Invalid move
  }

  if (piece == RED || piece == RED_KING) {
    if (to_row < from_row) {
      return 0; // Invalid move
    }
  }

  if (piece == BLACK || piece == BLACK_KING) {
    if (to_row > from_row) {
      return 0; // Invalid move
    }
  }
  
  // Check for jump move
  if (abs(from_row - to_row) == 2 && abs(from_col - to_col) == 2) {
    int jumped_row = (from_row + to_row) / 2;
    int jumped_col = (from_col + to_col) / 2;
    Piece jumped_piece = game->board[jumped_row][jumped_col];
    
    if ((piece == RED && (jumped_piece == BLACK || jumped_piece == BLACK_KING)) ||
        (piece == BLACK && (jumped_piece == RED || jumped_piece == RED_KING))) {
      return 1; // Valid jump move
    } else {
      return 0; // Invalid move
    }
  }
  
  // Check for regular move
  if (abs(from_row - to_row) == 1 && abs(from_col - to_col) == 1) {
    return 1; // Valid regular move
  } else {
    return 0; // Invalid move
  }
}

void make_move(Game *game, int from_row, int from_col, int to_row, int to_col) {
  Piece piece = game->board[from_row][from_col];
  game->board[from_row][from_col] = EMPTY;
  game->board[to_row][to_col] = piece;
  
  if (piece == RED && to_row == BOARD_SIZE - 1) {
    game->board[to_row][to_col] = RED_KING;
  } else if (piece == BLACK && to_row == 0) {
    game->board[to_row][to_col] = BLACK_KING;
  }
  
  if (abs(from_row - to_row) == 2 && abs(from_col - to_col) == 2) {
    int jumped_row = (from_row + to_row) / 2;
    int jumped_col = (from_col + to_col) / 2;
    Piece jumped_piece = game->board[jumped_row][jumped_col];
    
    if (jumped_piece == BLACK || jumped_piece == BLACK_KING) {
      game->black_remaining--;
    } else {
      game->red_remaining--;
    }
    
    game->board[jumped_row][jumped_col] = EMPTY;
  }
}

int main() {
  Game game;
  initialize_board(&game);

  int current_player = RED;
  int game_over = 0;

  while (!game_over) {
    display(&game);
    printf("Player %s's turn\n", current_player == RED ? "RED" : "BLACK");

    int from_row, from_col, to_row, to_col;
    printf("Enter move (ex: a2 b3): ");
    scanf("%c%d %c%d", &from_col, &from_row, &to_col, &to_row);
    from_col -= 'a';
    from_row--;
    to_col -= 'a';
    to_row--;

    if (is_legal_move(&game, from_row, from_col, to_row, to_col)) {
      make_move(&game, from_row, from_col, to_row, to_col);
      if (current_player == RED) {
        current_player = BLACK;
        if (game.red_remaining == 0) {
          game_over = 1;
          printf("*** BLACK WINS! ***\n");
        }
      } else {
        current_player = RED;
        if (game.black_remaining == 0) {
          game_over = 1;
          printf("*** RED WINS! ***\n");
        }
      }
    } else {
      printf("Invalid move, please try again\n");
    }

    // Consume remaining newline character
    getchar();
  }

  return 0;
}