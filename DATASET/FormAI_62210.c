//FormAI DATASET v1.0 Category: Checkers Game ; Style: Romeo and Juliet
#include <stdio.h>

// Checkerboard dimensions
#define BOARD_SIZE 8

// Piece representation
#define EMPTY 0
#define WHITE 1
#define BLACK 2

// move direction for black piece
#define UP_LEFT -9
#define UP_RIGHT -7
#define DOWN_LEFT 7
#define DOWN_RIGHT 9

// move direction for white piece
#define WHITE_UP_LEFT 9
#define WHITE_UP_RIGHT 7
#define WHITE_DOWN_LEFT -7
#define WHITE_DOWN_RIGHT -9

// Function to display the Checkerboard
void display_board(int arr[BOARD_SIZE][BOARD_SIZE]) {
  printf("  ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
  }
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

// Set the board with initial pieces
void initialize_board(int arr[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if ((i + j) % 2 == 1 && i < 3) {
        arr[i][j] = BLACK;
      } else if ((i + j) % 2 == 1 && i > 4) {
        arr[i][j] = WHITE;
      } else {
        arr[i][j] = EMPTY;
      }
    }
  }
}

// Check if the move is valid and return the resulting board
int check_move(int arr[BOARD_SIZE][BOARD_SIZE], int init_pos, int dest_pos) {

  int init_x = init_pos / BOARD_SIZE;
  int init_y = init_pos % BOARD_SIZE;
  int dest_x = dest_pos / BOARD_SIZE;
  int dest_y = dest_pos % BOARD_SIZE;

  // Determine the current piece and move directions
  int current_player = arr[init_x][init_y];
  int direction;
  if (current_player == BLACK) {
    direction = (dest_pos > init_pos) ? DOWN_RIGHT : DOWN_LEFT;
  } else {
    direction = (dest_pos > init_pos) ? WHITE_DOWN_RIGHT : WHITE_DOWN_LEFT;
  }

  if (dest_x < 0 || dest_x >= BOARD_SIZE || dest_y < 0 || dest_y >= BOARD_SIZE) {
    printf("Invalid Move: out of bounds\n");
    return -1;
  }

  if (arr[dest_x][dest_y] != EMPTY) {
    printf("Invalid Move: destination occupied\n");
    return -1;
  }

  // Check if it's a capture move
  int delta_x = dest_x - init_x;
  int delta_y = dest_y - init_y;
  if (delta_x == 2 || delta_x == -2) {
    int capture_x = init_x + delta_x / 2;
    int capture_y = init_y + delta_y / 2;
    if (arr[capture_x][capture_y] != 3 - current_player) {
      printf("Invalid Move: must capture opponent piece\n");
      return -1;
    } else {
      arr[capture_x][capture_y] = EMPTY;
    }
  }

  // Make the move
  arr[dest_x][dest_y] = current_player;
  arr[init_x][init_y] = EMPTY;

  // Check for promotion to King
  if (dest_x == 0 || dest_x == BOARD_SIZE - 1) {
    arr[dest_x][dest_y] = current_player + 1;
  }

  return 0;
}

// Make a move on the current board
int make_move(int arr[BOARD_SIZE][BOARD_SIZE], int current_player) {
  printf("Turn of Player %d\n", current_player);
  int init_pos, dest_pos;
  printf("Enter initial position: ");
  scanf("%d", &init_pos);
  printf("Enter destination position: ");
  scanf("%d", &dest_pos);

  int result = check_move(arr, init_pos, dest_pos);
  while (result == -1) {
    printf("Invalid move, please try again.\n");
    printf("Enter initial position: ");
    scanf("%d", &init_pos);
    printf("Enter destination position: ");
    scanf("%d", &dest_pos);
    result = check_move(arr, init_pos, dest_pos);
  }

  return (current_player == BLACK) ? WHITE : BLACK;
}

// Check if a player has won
int check_win(int arr[BOARD_SIZE][BOARD_SIZE], int player) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (arr[i][j] == player || arr[i][j] == player + 2) {
        int direction;
        if (player == BLACK) {
          direction = (arr[i][j] == BLACK) ? DOWN_LEFT : DOWN_RIGHT;
        } else {
          direction = (arr[i][j] == WHITE) ? WHITE_UP_LEFT : WHITE_UP_RIGHT;
        }

        // check if a jump is possible in the current direction
        int jump_x = i + direction / 2;
        int jump_y = j + direction / 2;
        if (jump_x >= 0 && jump_x < BOARD_SIZE && jump_y >= 0 && jump_y < BOARD_SIZE) {
          if (arr[jump_x][jump_y] == 3 - player || arr[jump_x][jump_y] == 3 - player + 2) {
            int dest_x = i + direction;
            int dest_y = j + direction;
            if (dest_x >= 0 && dest_x < BOARD_SIZE && dest_y >= 0 && dest_y < BOARD_SIZE) {
              if (arr[dest_x][dest_y] == EMPTY) {
                return 0;
              }
            }
          }
        }

        // check if a normal move is possible in the current direction
        int dest_x = i + direction;
        int dest_y = j + direction;
        if (dest_x >= 0 && dest_x < BOARD_SIZE && dest_y >= 0 && dest_y < BOARD_SIZE) {
          if (arr[dest_x][dest_y] == EMPTY) {
            return 0;
          }
        }
      }
    }
  }

  return player;
}

int main() {
  // Initialize the Checkerboard
  int board[BOARD_SIZE][BOARD_SIZE];
  initialize_board(board);

  // Game loop
  int current_player = BLACK;
  int winner = 0;
  while (winner == 0) {
    display_board(board);
    current_player = make_move(board, current_player);
    winner = check_win(board, current_player);
  }

  printf("Congratulations Player %d, you win!\n", winner);
}