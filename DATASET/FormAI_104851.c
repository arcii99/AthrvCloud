//FormAI DATASET v1.0 Category: Checkers Game ; Style: future-proof
#include <stdio.h>

// Board dimensions
#define WIDTH 8
#define HEIGHT 8

// Define board squares
#define EMPTY 0
#define RED 1
#define BLACK 2

// Piece types
#define NORMAL 0
#define KING 1

int board[HEIGHT][WIDTH] = { 0 };

void init_board() {
    // Initialize the starting position of the game
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            if(row % 2 == col % 2) {
                if(row < 3) board[row][col] = BLACK;
                else if(row > 4) board[row][col] = RED;
            }
        }
    }
}

void print_board() {
    // Print out the current game board
    printf("  0 1 2 3 4 5 6 7\n");
    for(int row = 0; row < HEIGHT; row++) {
        printf("%d ", row);
        for(int col = 0; col < WIDTH; col++) {
            if(board[row][col] == EMPTY) printf(". ");
            else if(board[row][col] == RED) printf("r ");
            else printf("b ");
        }
        printf("\n");
    }
    printf("\n");
}

int valid_move(int row, int col, int dest_row, int dest_col, int player) {
    // Check if the given move is valid for the current player
    if(dest_row < 0 || dest_row >= HEIGHT || dest_col < 0 || dest_col >= WIDTH) return 0;
    if(board[dest_row][dest_col] != EMPTY) return 0;
    if(player == RED) {
        if(board[row][col] == NORMAL) {
            if(dest_row != row + 1 || abs(dest_col - col) != 1) return 0;
        }
        else { // King piece
            if(abs(dest_row - row) != 1 || abs(dest_col - col) != 1) return 0;
        }
        return 1;
    }
    else { // Black player
        if(board[row][col] == NORMAL) {
            if(dest_row != row - 1 || abs(dest_col - col) != 1) return 0;
        }
        else { // King piece
            if(abs(dest_row - row) != 1 || abs(dest_col - col) != 1) return 0;
        }
        return 1;
    }
}

int jump_move(int row, int col, int dest_row, int dest_col, int player) {
    // Check if the given move is a jump move for the current player
    int mid_row = (row + dest_row) / 2;
    int mid_col = (col + dest_col) / 2;
    if(dest_row < 0 || dest_row >= HEIGHT || dest_col < 0 || dest_col >= WIDTH) return 0;
    if(board[dest_row][dest_col] != EMPTY) return 0;
    if(player == RED) {
        if(board[row][col] == NORMAL) {
            if(dest_row != row + 2 || abs(dest_col - col) != 2) return 0;
            if(board[mid_row][mid_col] != BLACK) return 0;
        }
        else { // King piece
            if(abs(dest_row - row) != 2 || abs(dest_col - col) != 2) return 0;
            if(board[mid_row][mid_col] != BLACK) return 0;
        }
        return 1;
    }
    else { // Black player
        if(board[row][col] == NORMAL) {
            if(dest_row != row - 2 || abs(dest_col - col) != 2) return 0;
            if(board[mid_row][mid_col] != RED) return 0;
        }
        else { // King piece
            if(abs(dest_row - row) != 2 || abs(dest_col - col) != 2) return 0;
            if(board[mid_row][mid_col] != RED) return 0;
        }
        return 1;
    }
}

void make_move(int row, int col, int dest_row, int dest_col, int player) {
    // Move the piece on the board
    board[dest_row][dest_col] = board[row][col];
    board[row][col] = EMPTY;
    if(player == BLACK && dest_row == 0) board[dest_row][dest_col] = KING;
    if(player == RED && dest_row == HEIGHT-1) board[dest_row][dest_col] = KING;
}

int game_over(int player) {
    // Check if the game is over
    int count_red = 0, count_black = 0;
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            if(board[row][col] == RED || board[row][col] == KING) count_red++;
            else if(board[row][col] == BLACK || board[row][col] == KING) count_black++;
        }
    }
    if(count_red == 0) return BLACK;
    else if(count_black == 0) return RED;
    else return 0;
}

int main() {
    int player = RED, game = 0;
    init_board();
    while(game == 0) {
        printf("Player %d's turn.\n", player);
        print_board();
        int row, col, dest_row, dest_col;
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &row, &col);
        printf("Enter the row and column of the destination square: ");
        scanf("%d %d", &dest_row, &dest_col);
        if(valid_move(row, col, dest_row, dest_col, player) || jump_move(row, col, dest_row, dest_col, player)) {
            make_move(row, col, dest_row, dest_col, player);
            if(jump_move(row, col, dest_row, dest_col, player)) {
                printf("Jump move!\n");
                while(jump_move(dest_row, dest_col, dest_row+2, dest_col+2, player) ||
                      jump_move(dest_row, dest_col, dest_row+2, dest_col-2, player) ||
                      jump_move(dest_row, dest_col, dest_row-2, dest_col+2, player) ||
                      jump_move(dest_row, dest_col, dest_row-2, dest_col-2, player)) {
                          printf("Enter another jump move for this piece: ");
                          int new_dest_row, new_dest_col;
                          scanf("%d %d", &new_dest_row, &new_dest_col);
                          make_move(dest_row, dest_col, new_dest_row, new_dest_col, player);
                          // Update the moved piece location
                          dest_row = new_dest_row;
                          dest_col = new_dest_col;
                }
            }
            if(player == RED) player = BLACK;
            else player = RED;
        }
        else printf("Invalid move. Try again.\n");
        game = game_over(player);
    }
    printf("Game over! Player %d wins!\n", game);
    return 0;
}