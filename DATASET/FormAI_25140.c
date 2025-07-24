//FormAI DATASET v1.0 Category: Checkers Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Define the board type as a 2D array of integers
typedef int board_t[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board with default values
void init_board(board_t board) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i + j) % 2 == 0) {  // Set black squares to -1
                board[i][j] = -1;
            } else {  // Set white squares to 0
                board[i][j] = 0;
            }
        }
    }
}

// Function to print the board state
void print_board(board_t board) {
    printf("  1 2 3 4 5 6 7 8\n");  // Print column numbers
    printf(" +---------------+\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%c|", 'a' + i);  // Print row letter
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == -1) {
                printf("*|");  // Black square
            } else if(board[i][j] == 0) {
                printf(" |");  // White square
            } else {
                printf("%c|", board[i][j]);  // Piece
            }
        }
        printf("\n");
        printf(" +---------------+\n");
    }
}

// Function to move a piece on the board
void move_piece(board_t board, int from_row, int from_col, int to_row, int to_col) {
    if(board[to_row][to_col] != 0) {
        printf("Invalid move!\n");
        return;
    }
    int piece = board[from_row][from_col];
    board[from_row][from_col] = 0;
    board[to_row][to_col] = piece;
}

int main() {
    board_t board;
    init_board(board);
    print_board(board);

    // Code implementation here

    return 0;
}