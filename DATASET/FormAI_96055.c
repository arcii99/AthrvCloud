//FormAI DATASET v1.0 Category: Checkers Game ; Style: unmistakable
#include <stdio.h>

// Define the board size
#define BOARD_SIZE 8

// Define the player pieces
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Define the board
char board[BOARD_SIZE][BOARD_SIZE];

// Initialize the board
void init_board() {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      // Set the player one pieces
      if (row < 3) {
        if ((row + col) % 2 != 0) {
          board[row][col] = PLAYER_ONE;
        }
        else {
          board[row][col] = ' ';
        }
      }
      // Set the player two pieces
      else if (row > 4) {
        if ((row + col) % 2 != 0) {
          board[row][col] = PLAYER_TWO;
        }
        else {
          board[row][col] = ' ';
        }
      }
      // Empty spaces
      else {
        board[row][col] = ' ';
      }
    }
  }
}

// Display the board
void display_board() {
  printf("\n\n");
  printf("  ");
  for (int row = 0; row < BOARD_SIZE; row++) {
    printf("+---");
  }
  printf("+\n");
  for (int row = 0; row < BOARD_SIZE; row++) {
    printf("%d ", (row + 1));
    for (int col = 0; col < BOARD_SIZE; col++) {
      printf("| %c ", board[row][col]);
    }
    printf("|");
    printf("\n");
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
      printf("+---");
    }
    printf("+\n");
  }
  printf("    A   B   C   D   E   F   G   H\n");
}

// Check if a move is valid
int is_valid_move(int start_row, int start_col, int end_row, int end_col, char player_piece) {
  
  // Check if the move is within the bounds of the board
  if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE ||
      end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
    return 0;
  }
  
  // Check if the end position is empty
  if (board[end_row][end_col] != ' ') {
    return 0;
  }
  
  // Check if the move is diagonal
  if (start_row - end_row != start_col - end_col && start_row - end_row != end_col - start_col) {
    return 0;
  }
  
  // Check if the move is only one space or a jump (two spaces)
  if (abs(start_row - end_row) == 1) {
    // Check if the player is moving in the correct direction
    if (player_piece == PLAYER_ONE && end_row > start_row) {
      return 0;
    }
    if (player_piece == PLAYER_TWO && end_row < start_row) {
      return 0;
    }
    
    return 1;
  }
  else if (abs(start_row - end_row) == 2) {
    // Check if the player is moving in the correct direction
    if (player_piece == PLAYER_ONE && end_row > start_row) {
      return 0;
    }
    if (player_piece == PLAYER_TWO && end_row < start_row) {
      return 0;
    }
    
    // Check if the move is a jump
    int mid_row = (start_row + end_row) / 2;
    int mid_col = (start_col + end_col) / 2;
    if (board[mid_row][mid_col] == ' ') {
      return 0;
    }
    if (board[mid_row][mid_col] == player_piece) {
      return 0;
    }
    
    return 1;
  }
  
  return 0;
}

// Make a move on the board
void make_move(int start_row, int start_col, int end_row, int end_col, char player_piece) {
  board[start_row][start_col] = ' ';
  
  // Check if the move is a jump
  if (abs(start_row - end_row) == 2) {
    int mid_row = (start_row + end_row) / 2;
    int mid_col = (start_col + end_col) / 2;
    board[mid_row][mid_col] = ' ';
  }
  
  board[end_row][end_col] = player_piece;
}

// Check if a player can make a move
int can_move(char player_piece) {
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == player_piece) {
        // Check if the player can move forward
        if (player_piece == PLAYER_ONE && row > 0) {
          if (col > 0 && is_valid_move(row, col, row - 1, col - 1, player_piece)) {
            return 1;
          }
          if (col < BOARD_SIZE - 1 && is_valid_move(row, col, row - 1, col + 1, player_piece)) {
            return 1;
          }
        }
        if (player_piece == PLAYER_TWO && row < BOARD_SIZE - 1) {
          if (col > 0 && is_valid_move(row, col, row + 1, col - 1, player_piece)) {
            return 1;
          }
          if (col < BOARD_SIZE - 1 && is_valid_move(row, col, row + 1, col + 1, player_piece)) {
            return 1;
          }
        }
        // Check if the player can jump
        if (col > 1 && row > 1 && is_valid_move(row, col, row - 2, col - 2, player_piece)) {
          return 1;
        }
        if (col < BOARD_SIZE - 2 && row > 1 && is_valid_move(row, col, row - 2, col + 2, player_piece)) {
          return 1;
        }
        if (col > 1 && row < BOARD_SIZE - 2 && is_valid_move(row, col, row + 2, col - 2, player_piece)) {
          return 1;
        }
        if (col < BOARD_SIZE - 2 && row < BOARD_SIZE - 2 && is_valid_move(row, col, row + 2, col + 2, player_piece)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

// Check if the game is over
int is_game_over() {
  if (!can_move(PLAYER_ONE) || !can_move(PLAYER_TWO)) {
    return 1;
  }
  return 0;
}

// Find the winner
char find_winner() {
  int player_one_count = 0;
  int player_two_count = 0;
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == PLAYER_ONE) {
        player_one_count++;
      }
      if (board[row][col] == PLAYER_TWO) {
        player_two_count++;
      }
    }
  }
  if (player_one_count > player_two_count) {
    return PLAYER_ONE;
  }
  if (player_two_count > player_one_count) {
    return PLAYER_TWO;
  }
  return ' ';
}

// Main function
int main() {
  // Initialize the board
  init_board();
  
  // Define the current player
  char current_player = PLAYER_ONE;
  
  // Play the game
  while (!is_game_over()) {
    // Display the board
    display_board();
    
    // Get the player's move
    char start_col;
    int start_row;
    char end_col;
    int end_row;
    printf("%c's turn\n", current_player);
    printf("Enter the starting position (ex. A2): ");
    scanf(" %c%d", &start_col, &start_row);
    printf("Enter the ending position (ex. B3): ");
    scanf(" %c%d", &end_col, &end_row);
    start_col = toupper(start_col);
    end_col = toupper(end_col);
    start_row--;
    end_row--;
    
    // Check if the move is valid
    if (!is_valid_move(start_row, start_col - 'A', end_row, end_col - 'A', current_player)) {
      printf("Invalid move.\n");
      continue;
    }
    
    // Make the move
    make_move(start_row, start_col - 'A', end_row, end_col - 'A', current_player);
    
    // Switch players
    if (current_player == PLAYER_ONE) {
      current_player = PLAYER_TWO;
    }
    else {
      current_player = PLAYER_ONE;
    }
  }
  
  // Display the winner
  char winner = find_winner();
  if (winner == ' ') {
    printf("The game is a tie!");
  }
  else {
    printf("%c is the winner!", winner);
  }
  
  return 0;
}