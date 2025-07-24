//FormAI DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// A structure to represent a single square on the board
typedef struct {
    bool is_empty;
    bool is_black;
} Square;

// A structure to represent the entire board
typedef Square Board[BOARD_SIZE][BOARD_SIZE];

// Initialize the board to its initial state
void init_board(Board board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                board[row][col].is_empty = true;
                board[row][col].is_black = false;
            }
            else if (row < 3) {
                board[row][col].is_empty = false;
                board[row][col].is_black = true;
            }
            else if (row > 4) {
                board[row][col].is_empty = false;
                board[row][col].is_black = false;
            }
            else {
                board[row][col].is_empty = true;
                board[row][col].is_black = false;
            }
        }
    }
}

// Print the board to the console
void print_board(Board board) {
    printf(" 01234567\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col].is_empty) {
                printf(".");
            }
            else if (board[row][col].is_black) {
                printf("B");
            }
            else {
                printf("W");
            }
        }
        printf("\n");
    }
}

int main() {
    Board board;
    init_board(board);
    print_board(board);
    return 0;
}