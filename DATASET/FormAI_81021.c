//FormAI DATASET v1.0 Category: Checkers Game ; Style: peaceful
#include <stdio.h>

// Constants
#define BOARD_SIZE 8
#define EMPTY 0
#define RED 1
#define BLACK 2
#define RED_PIECE 'R'
#define BLACK_PIECE 'B'

// Function prototypes
void print_board(int board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y, int color);
void move_piece(int board[BOARD_SIZE][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y);
int get_opposite_color(int color);
int is_game_over(int board[BOARD_SIZE][BOARD_SIZE]);

int main() {
  // Initialize the board
  int board[BOARD_SIZE][BOARD_SIZE] = {
    {EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY, RED},
    {RED, EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY},
    {EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY, RED},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY},
    {EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK},
    {BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY}
  };

  // Main game loop
  int game_over = 0;
  int current_player = RED;
  while (!game_over) {
    // Print the board
    print_board(board);

    // Get the user's move
    int from_x, from_y, to_x, to_y;
    printf("Player %d's turn:\n", current_player);
    printf("Enter the x-coordinate of the piece you want to move: ");
    scanf("%d", &from_x);
    printf("Enter the y-coordinate of the piece you want to move: ");
    scanf("%d", &from_y);
    printf("Enter the x-coordinate of the square you want to move to: ");
    scanf("%d", &to_x);
    printf("Enter the y-coordinate of the square you want to move to: ");
    scanf("%d", &to_y);

    // Check if move is valid
    int valid_move = is_valid_move(board, from_x, from_y, to_x, to_y, current_player);
    if (!valid_move) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Move the piece
    move_piece(board, from_x, from_y, to_x, to_y);

    // Check if game is over
    game_over = is_game_over(board);
    if (game_over) {
      printf("Player %d wins!\n", get_opposite_color(current_player));
    }

    // Switch to the other player
    current_player = get_opposite_color(current_player);
  }

  return 0;
}

// Functions

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
  // Print the column labels
  printf("  ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n");

  // Print the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == EMPTY) {
        printf(". ");
      } else if (board[i][j] == RED) {
        printf("%c ", RED_PIECE);
      } else if (board[i][j] == BLACK) {
        printf("%c ", BLACK_PIECE);
      }
    }
    printf("\n");
  }
}

int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y, int color) {
  // Check that the square being moved from is not empty
  if (board[from_x][from_y] == EMPTY) {
    return 0;
  }

  // Check that the square being moved to is empty
  if (board[to_x][to_y] != EMPTY) {
    return 0;
  }

  // Check that the movement is diagonal
  int dx = to_x - from_x;
  int dy = to_y - from_y;
  if (dx != dy && dx != -dy) {
    return 0;
  }

  // Check that the movement is not more than two squares
  if (dx * dx + dy * dy > 8) {
    return 0;
  }

  // Check that a regular piece is not moving backwards
  if (color == RED && dy < 0) {
    return 0;
  } else if (color == BLACK && dy > 0) {
    return 0;
  }

  // Check that there is an opponent's piece in between the start and end squares
  int x_direction = (dx > 0 ? 1 : -1);
  int y_direction = (dy > 0 ? 1 : -1);
  int x = from_x + x_direction;
  int y = from_y + y_direction;
  while (x != to_x && y != to_y) {
    if (board[x][y] != EMPTY && board[x][y] != color) {
      return 1;
    }
    x += x_direction;
    y += y_direction;
  }

  return 0;
}

void move_piece(int board[BOARD_SIZE][BOARD_SIZE], int from_x, int from_y, int to_x, int to_y) {
  board[to_x][to_y] = board[from_x][from_y];
  board[from_x][from_y] = EMPTY;
}

int get_opposite_color(int color) {
  if (color == RED) {
    return BLACK;
  } else {
    return RED;
  }
}

int is_game_over(int board[BOARD_SIZE][BOARD_SIZE]) {
  int red_count = 0;
  int black_count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == RED) {
        red_count++;
      } else if (board[i][j] == BLACK) {
        black_count++;
      }
    }
  }

  if (red_count == 0 || black_count == 0) {
    return 1;
  } else {
    return 0;
  }
}