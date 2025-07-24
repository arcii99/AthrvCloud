//FormAI DATASET v1.0 Category: Checkers Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// define the player types
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// define the pieces types
#define BLANK ' '
#define WHITE_PIECE 'w'
#define BLACK_PIECE 'b'
#define WHITE_KING 'W'
#define BLACK_KING 'B'

// define the colors
#define WHITE_COLOR "\x1b[37m"
#define BLACK_COLOR "\x1b[30m"
#define RESET_COLOR "\x1b[0m"

char board[BOARD_SIZE][BOARD_SIZE];
char player1 = PLAYER_1;
char player2 = PLAYER_2;

// A function to print the game board
void print_board() {
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("\t  ");
    for (int j = 0; j < BOARD_SIZE; j++) {
      if ((i + j) % 2 == 0) {  // even cell
        printf("%s  ", WHITE_COLOR);
      } else {                  // odd cell
        printf("%s  ", BLACK_COLOR);
      }
      printf("%c " RESET_COLOR, board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// A function to initialize the game board with the starting pieces
void initialize_board() {
  // initialize the blank cells
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = BLANK;
    }
  }
  // initialize the player 1 pieces
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if ((i + j) % 2 == 0) {  // even cell
        board[i][j] = BLACK_PIECE;
      }
    }
  }
  // initialize the player 2 pieces
  for (int i = BOARD_SIZE - 1; i > BOARD_SIZE - 4; i--) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if ((i + j) % 2 == 0) {  // even cell
        board[i][j] = WHITE_PIECE;
      }
    }
  }
}

// A function to check if the move is a valid move (for a single piece)
int is_valid_move(int curr_row, int curr_col, int next_row, int next_col, char piece) {
  // check boundaries
  if (next_row < 0 || next_row >= BOARD_SIZE || next_col < 0 || next_col >= BOARD_SIZE) {
    return 0;
  }
  // check if the destination cell is a blank cell
  if (board[next_row][next_col] != BLANK) {
    return 0;
  }
  // check if the piece is a King
  if (piece == WHITE_KING || piece == BLACK_KING) {
    int diff_row = abs(next_row - curr_row);
    int diff_col = abs(next_col - curr_col);
    // check if it's a diagonal move
    if (diff_row != diff_col) {
      return 0;
    }
    // check if it's a valid move
    int i = curr_row;
    int j = curr_col;
    int count = 0;
    while (i != next_row && j != next_col) {
      if (board[i][j] != BLANK) {
        count++;
      }
      i += (next_row - curr_row) / diff_row;
      j += (next_col - curr_col) / diff_col;
    }
    if (count != 0) {
      return 0;
    }
    return 1;
  }
  // check if the piece is a non-King
  int diff_row = next_row - curr_row;
  int diff_col = abs(next_col - curr_col);
  // make sure that the move is in one of the players directions
  if ((diff_row < 0 && piece == WHITE_PIECE) || (diff_row > 0 && piece == BLACK_PIECE)) {
    return 0;
  }
  // check if it's a diagonal move
  if (diff_row != diff_col) {
    return 0;
  }
  // check if the move is valid
  if (abs(diff_row) != 1 || diff_col != 1) {
    return 0;
  }
  return 1;
}

// A function to check if the move is a valid move (for a jump move)
int is_valid_jump(int curr_row, int curr_col, int next_row, int next_col, char piece, int count) {
  // check boundaries
  if (next_row < 0 || next_row >= BOARD_SIZE || next_col < 0 || next_col >= BOARD_SIZE) {
    return 0;
  }
  // check if the destination cell is a blank cell
  if (board[next_row][next_col] != BLANK) {
    return 0;
  }
  int jumped_piece_row = (curr_row + next_row) / 2;
  int jumped_piece_col = (curr_col + next_col) / 2;
  // check if there's a piece to jump over
  if ((piece == BLACK_PIECE || piece == BLACK_KING) && board[jumped_piece_row][jumped_piece_col] != WHITE_PIECE && board[jumped_piece_row][jumped_piece_col] != WHITE_KING) {
    return 0;
  }
  if ((piece == WHITE_PIECE || piece == WHITE_KING) && board[jumped_piece_row][jumped_piece_col] != BLACK_PIECE && board[jumped_piece_row][jumped_piece_col] != BLACK_KING) {
    return 0;
  }
  // check if it's a valid jump
  int diff_row = next_row - curr_row;
  int diff_col = abs(next_col - curr_col);
  if (abs(diff_row) != 2 || diff_col != 2) {
    return 0;
  }
  // update the count
  count++;
  // if the piece can jump again, check the valid jumps
  if (is_valid_jump(next_row, next_col, next_row - 2, next_col - 2, piece, count) || is_valid_jump(next_row, next_col, next_row - 2, next_col + 2, piece, count) || is_valid_jump(next_row, next_col, next_row + 2, next_col - 2, piece, count) || is_valid_jump(next_row, next_col, next_row + 2, next_col + 2, piece, count)) {
    return 1;
  }
  return count;
}

// A function to check if the move is a valid move (supports jumps as well)
int is_valid(int curr_row, int curr_col, int next_row, int next_col, char piece, int count) {
  // check if the move is valid
  if (is_valid_move(curr_row, curr_col, next_row, next_col, piece)) {
    return 1;
  }
  // check if the move is a jump
  count = is_valid_jump(curr_row, curr_col, next_row, next_col, piece, count);
  if (count) {
    return count;
  }
  return 0;
}

// A function to move a piece
void move_piece(int curr_row, int curr_col, int next_row, int next_col, char piece) {
  // move the piece to the new cell
  board[next_row][next_col] = piece;
  board[curr_row][curr_col] = BLANK;
  // check if the piece has become a King
  if (piece == BLACK_PIECE && next_row == 0) {
    board[next_row][next_col] = BLACK_KING;
  }
  if (piece == WHITE_PIECE && next_row == BOARD_SIZE - 1) {
    board[next_row][next_col] = WHITE_KING;
  }
}

// A function to jump over a piece
void jump_piece(int curr_row, int curr_col, int next_row, int next_col, char piece) {
  int jumped_piece_row = (curr_row + next_row) / 2;
  int jumped_piece_col = (curr_col + next_col) / 2;
  // remove the jumped over piece
  board[jumped_piece_row][jumped_piece_col] = BLANK;
  // move the piece to the new cell
  move_piece(curr_row, curr_col, next_row, next_col, piece);
}

// A function to get the player input
int get_input(int *curr_row, int *curr_col, int *next_row, int *next_col) {
  printf("Enter the current row: ");
  if (scanf("%d", curr_row) != 1) {
    return 0;
  }
  printf("Enter the current column: ");
  if (scanf("%d", curr_col) != 1) {
    return 0;
  }
  printf("Enter the next row: ");
  if (scanf("%d", next_row) != 1) {
    return 0;
  }
  printf("Enter the next column: ");
  if (scanf("%d", next_col) != 1) {
    return 0;
  }
  return 1;
}

// A function to check if a single piece can make a valid move
int has_valid_move(int row, int col, char piece) {
  // search in the diagonal cells
  if (piece == BLACK_PIECE || piece == BLACK_KING) {
    if (is_valid_move(row, col, row - 1, col - 1, piece)) {
      return 1;
    }
    if (is_valid_move(row, col, row - 1, col + 1, piece)) {
      return 1;
    }
  }
  if (piece == WHITE_PIECE || piece == WHITE_KING) {
    if (is_valid_move(row, col, row + 1, col - 1, piece)) {
      return 1;
    }
    if (is_valid_move(row, col, row + 1, col + 1, piece)) {
      return 1;
    }
  }
  // search in the jump cells
  int count = 0;
  if (piece == BLACK_PIECE || piece == BLACK_KING) {
    count = is_valid_jump(row, col, row - 2, col - 2, piece, count);
    if (count) {
      return count;
    }
    count = is_valid_jump(row, col, row - 2, col + 2, piece, count);
    if (count) {
      return count;
    }
  }
  if (piece == WHITE_PIECE || piece == WHITE_KING) {
    count = is_valid_jump(row, col, row + 2, col - 2, piece, count);
    if (count) {
      return count;
    }
    count = is_valid_jump(row, col, row + 2, col + 2, piece, count);
    if (count) {
      return count;
    }
  }
  return 0;
}

// A function to check if the player has any valid moves
int has_valid_moves(char player) {
  // search in all the player's pieces
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == player || board[i][j] == (player == PLAYER_1 ? 'W' : 'B')) {
        if (has_valid_move(i, j, board[i][j])) {
          return 1;
        }
      }
    }
  }
  return 0;
}

// A function to switch between the players
char switch_player(char player) {
  return player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
}

// A function to play the game
void play_game() {
  char curr_player = player1;
  int curr_row, curr_col, next_row, next_col;
  int turn_count = 0;
  while (1) {
    print_board();
    printf("Player %c's turn.\n", curr_player);
    // check if the player has any valid moves
    if (!has_valid_moves(curr_player)) {
      printf("Player %c has no valid moves left.\n", curr_player);
      curr_player = switch_player(curr_player);
      continue;
    }
    if (!get_input(&curr_row, &curr_col, &next_row, &next_col)) {
      printf("Invalid input. Please try again.\n");
      continue;
    }
    // check if it's a valid move
    int count = is_valid(curr_row, curr_col, next_row, next_col, board[curr_row][curr_col], 0);
    if (!count) {
      printf("Invalid move. Please try again.\n");
      continue;
    }
    // execute the move(s)
    move_piece(curr_row, curr_col, next_row, next_col, board[curr_row][curr_col]);
    if (count > 1) {
      while (count > 1) {
        turn_count++;
        printf("Player %c is jumping again.\n", curr_player);
        printf("Current row: %d\n", next_row);
        printf("Current column: %d\n", next_col);
        printf("Enter the next row: ");
        if (scanf("%d", &next_row) != 1) {
          printf("Invalid input. Please try again.\n");
          continue;
        }
        printf("Enter the next column: ");
        if (scanf("%d", &next_col) != 1) {
          printf("Invalid input. Please try again.\n");
          continue;
        }
        // check if it's a valid jump
        int result = is_valid_jump(next_row, next_col, next_row - 2, next_col - 2, board[next_row][next_col], 0);
        if (!result) {
          result = is_valid_jump(next_row, next_col, next_row - 2, next_col + 2, board[next_row][next_col], 0);
        }
        if (!result) {
          result = is_valid_jump(next_row, next_col, next_row + 2, next_col - 2, board[next_row][next_col], 0);
        }
        if (!result) {
          result = is_valid_jump(next_row, next_col, next_row + 2, next_col + 2, board[next_row][next_col], 0);
        }
        if (!result) {
          printf("Invalid jump. Please try again.\n");
          continue;
        }
        // execute the jump
        jump_piece(next_row, next_col, next_row - 2, next_col - 2, board[next_row][next_col]);
        count = result;
      }
    }
    // check if the player has won
    if (!has_valid_moves(switch_player(curr_player))) {
      print_board();
      printf("Congratulations, Player %c wins!\n", curr_player);
      return;
    }
    // switch to the other player
    curr_player = turn_count % 2 == 0 ? player1 : player2;
  }
}

// main function
int main() {
  initialize_board();
  play_game();
  return 0;
}