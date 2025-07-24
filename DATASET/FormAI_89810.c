//FormAI DATASET v1.0 Category: Checkers Game ; Style: systematic
#include <stdio.h>

int board[8][8]; // The 8x8 checker board
int player = 1; // Player 1 starts first
int counter = 0; // Counter for checking draw game
int winner = 0; // Flag to check if there is a winner

void print_board() {
  printf("\n   0 1 2 3 4 5 6 7\n");
  for (int i = 0; i < 8; i++) {
    printf("%d  ", i);
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == 0) {
        printf("- ");
      } else if (board[i][j] == 1) {
        printf("B "); // Player 1's piece "B"
      } else if (board[i][j] == 2) {
        printf("R "); // Player 2's piece "R"
      }
    }
    printf("\n");
  }
}

int valid_move(int x1, int y1, int x2, int y2) {
  // Check if the move is within the board
  if (x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
    return 0;
  }
  
  // Check if the target position is empty
  if (board[x2][y2] != 0) {
    return 0;
  }
  
  // Check if the player is moving their own piece
  if (player == 1 && board[x1][y1] != 1) {
    return 0;
  } else if (player == 2 && board[x1][y1] != 2) {
    return 0;
  }
  
  // Check if the move is a jump
  if (x1-x2 == 2 || x1-x2 == -2) {
    // Check if there is an opponent's piece to jump over
    int x3 = (x1+x2)/2;
    int y3 = (y1+y2)/2;
    if (board[x3][y3] != (3 - player)) {
      return 0;
    }
  }
  
  return 1;
}

void make_move(int x1, int y1, int x2, int y2) {
  board[x2][y2] = board[x1][y1];
  board[x1][y1] = 0;
  
  // Check if a jump was made
  if (x1-x2 == 2 || x1-x2 == -2) {
    int x3 = (x1+x2)/2;
    int y3 = (y1+y2)/2;
    board[x3][y3] = 0;
  }
  
  // Check if a piece reached the end of the board and crowned
  if (board[x2][y2] == 1 && x2 == 0) {
    board[x2][y2] = 3;
  } else if (board[x2][y2] == 2 && x2 == 7) {
    board[x2][y2] = 4;
  }
  
  // Switch player turn
  player = 3 - player;
}

void check_winner() {
  int count1 = 0;
  int count2 = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == 1 || board[i][j] == 3) {
        count1++;
      } else if (board[i][j] == 2 || board[i][j] == 4) {
        count2++;
      }
    }
  }
  
  if (count1 == 0 || count2 == 0) {
    winner = player;
  }
}

int main() {
  // Initialize board
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i < 3 && (i+j) % 2 == 0) {
        board[i][j] = 2; // Player 2's piece "R"
      } else if (i > 4 && (i+j) % 2 == 0) {
        board[i][j] = 1; // Player 1's piece "B"
      } else {
        board[i][j] = 0; // Empty position
      }
    }
  }
  
  print_board();
  
  // Start game loop
  while (winner == 0) {
    int x1, y1, x2, y2;
    printf("\nPlayer %d's turn.\n", player);
    printf("Enter current position of the piece (x y): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter new position to move the piece (x y): ");
    scanf("%d %d", &x2, &y2);
    
    if (valid_move(x1, y1, x2, y2)) {
      make_move(x1, y1, x2, y2);
      print_board();
      counter++;
    } else {
      printf("Invalid move. Try again.\n");
    }
    
    check_winner();
  }
  
  // End game
  printf("\nPlayer %d wins!\n", winner);
  printf("Total moves: %d\n", counter);
  
  return 0;
}