//FormAI DATASET v1.0 Category: Checkers Game ; Style: puzzling
#include <stdio.h>

#define BOARD_SIZE 8

// Define the board as a two-dimensional array of integers
int board[BOARD_SIZE][BOARD_SIZE] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0}
};

// Define the pieces as integers
#define EMPTY 0
#define WHITE 1
#define BLACK 2
#define KING 3

// Define the functions for moving and capturing pieces
int move_piece(int player, int x1, int y1, int x2, int y2) {
    // Check if the move is valid
    if (!is_valid_move(player, x1, y1, x2, y2)) {
        return 0;
    }
    
    // Move the piece
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = EMPTY;
    
    // Check if the piece should be promoted to a king
    if ((player == WHITE && x2 == 0) || (player == BLACK && x2 == 7)) {
        board[x2][y2] = KING;
    }
    
    return 1;
}

int capture_piece(int player, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int mid_x = x1 + dx / 2;
    int mid_y = y1 + dy / 2;
    
    // Check if the capture is valid
    if (!is_valid_capture(player, x1, y1, x2, y2)) {
        return 0;
    }
    
    // Capture the piece
    board[x2][y2] = board[x1][y1];
    board[mid_x][mid_y] = EMPTY;
    board[x1][y1] = EMPTY;
    
    // Check if the piece should be promoted to a king
    if ((player == WHITE && x2 == 0) || (player == BLACK && x2 == 7)) {
        board[x2][y2] = KING;
    }
    
    return 1;
}

// Define the functions for checking if moves and captures are valid
int is_valid_move(int player, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    // Check if the destination is empty
    if (board[x2][y2] != EMPTY) {
        return 0;
    }
    
    // Check if the move is diagonal
    if (dx == 0 || dy == 0 || dx != dy) {
        return 0;
    }
    
    // Check if the player is moving in the correct direction
    if (player == WHITE && dx > 0) {
        return 0;
    }
    if (player == BLACK && dx < 0) {
        return 0;
    }
    
    // Check if the move is only one square
    if (abs(dx) != 1) {
        return 0;
    }
    
    return 1;
}

int is_valid_capture(int player, int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int mid_x = x1 + dx / 2;
    int mid_y = y1 + dy / 2;
    
    // Check if the destination is empty
    if (board[x2][y2] != EMPTY) {
        return 0;
    }
    
    // Check if the move is diagonal
    if (dx == 0 || dy == 0 || dx != dy) {
        return 0;
    }
    
    // Check if the player is moving in the correct direction
    if (player == WHITE && dx > 0) {
        return 0;
    }
    if (player == BLACK && dx < 0) {
        return 0;
    }
    
    // Check if the capture is two squares away
    if (abs(dx) != 2) {
        return 0;
    }
    
    // Check if there is a piece to capture
    if (board[mid_x][mid_y] == EMPTY) {
        return 0;
    }
    
    // Check if the piece to capture belongs to the other player
    if (board[mid_x][mid_y] == player || board[mid_x][mid_y] == player + 2) {
        return 0;
    }
    
    return 1;
}

// Define the function to print the board
void print_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (board[row][col]) {
                case EMPTY:
                    printf(" ");
                    break;
                case WHITE:
                    printf("o");
                    break;
                case BLACK:
                    printf("x");
                    break;
                case KING:
                    printf("K");
                    break;
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    // Print the initial board
    print_board();
    
    // Move a piece from e3 to d4
    move_piece(BLACK, 5, 4, 4, 3);
    
    // Print the board after the move
    print_board();
    
    // Capture a piece from d4 to f2
    capture_piece(BLACK, 4, 3, 2, 5);
    
    // Print the board after the capture
    print_board();
    
    return 0;
}