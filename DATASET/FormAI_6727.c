//FormAI DATASET v1.0 Category: Checkers Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Constants for the board and pieces
#define BOARD_SIZE 8
#define PIECE_EMPTY '.'
#define PIECE_BLACK 'B'
#define PIECE_RED 'R'
#define PIECE_KING_B 'K'
#define PIECE_KING_R 'Q'

// Function declarations
void initializeBoard(char board[][BOARD_SIZE]);
void displayBoard(char board[][BOARD_SIZE]);
void movePiece(char board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col);
void makeKing(char board[][BOARD_SIZE], int row, int col);
int isValidMove(char board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col, char player);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn = 1; // Player 1's turn is represented by odd numbers, Player 2's turn is represented by even numbers
    int start_row, start_col, end_row, end_col;

    initializeBoard(board);
    displayBoard(board);

    // Game loop
    while (1) {
        printf("Player %d's turn:\n", turn % 2 == 1 ? 1 : 2);
        printf("Enter starting row and column: ");
        scanf("%d%d", &start_row, &start_col);
        printf("Enter ending row and column: ");
        scanf("%d%d", &end_row, &end_col);

        // Check if move is valid
        if (isValidMove(board, start_row, start_col, end_row, end_col, turn % 2 == 1 ? PIECE_BLACK : PIECE_RED)) {
            // Move piece and check if it should become a king
            movePiece(board, start_row, start_col, end_row, end_col);
            if (turn % 2 == 1 && end_row == BOARD_SIZE - 1) {
                makeKing(board, end_row, end_col);
            }
            else if (turn % 2 == 0 && end_row == 0) {
                makeKing(board, end_row, end_col);
            }

            displayBoard(board);

            // Check for win condition
            int num_black = 0, num_red = 0;
            for (int row = 0; row < BOARD_SIZE; row++) {
                for (int col = 0; col < BOARD_SIZE; col++) {
                    if (board[row][col] == PIECE_BLACK || board[row][col] == PIECE_KING_B) {
                        num_black++;
                    }
                    else if (board[row][col] == PIECE_RED || board[row][col] == PIECE_KING_R) {
                        num_red++;
                    }
                }
            }
            if (num_black == 0) {
                printf("Player 2 wins!\n");
                break;
            }
            else if (num_red == 0) {
                printf("Player 1 wins!\n");
                break;
            }

            // Switch turns
            turn++;
        }
        else {
            printf("Invalid move, try again.\n");
        }
    }

    return 0;
}

// Function to initialize the board
void initializeBoard(char board[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 1 && row <= 2) { // Black pieces
                board[row][col] = PIECE_BLACK;
            }
            else if ((row + col) % 2 == 1 && row >= BOARD_SIZE - 3) { // Red pieces
                board[row][col] = PIECE_RED;
            }
            else { // Empty space
                board[row][col] = PIECE_EMPTY;
            }
        }
    }
}

// Function to display the board
void displayBoard(char board[][BOARD_SIZE]) {
    printf("\n   0 1 2 3 4 5 6 7\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d  ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move a piece
void movePiece(char board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = PIECE_EMPTY;
}

// Function to make a piece into a king
void makeKing(char board[][BOARD_SIZE], int row, int col) {
    if (board[row][col] == PIECE_BLACK) {
        board[row][col] = PIECE_KING_B;
    }
    else if (board[row][col] == PIECE_RED) {
        board[row][col] = PIECE_KING_R;
    }
}

// Function to check if a move is valid
int isValidMove(char board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col, char player) {
    // Check if start and end positions are on the board
    if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE ||
        end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        return 0;
    }

    // Check if end position is empty
    if (board[end_row][end_col] != PIECE_EMPTY) {
        return 0;
    }

    // Check if player is moving their own piece
    if (board[start_row][start_col] != player && board[start_row][start_col] != (player == PIECE_BLACK ? PIECE_KING_B : PIECE_KING_R)) {
        return 0;
    }

    // Check if regular piece is moving diagonally forward
    if (board[start_row][start_col] == player) {
        if (player == PIECE_BLACK && end_row != start_row + 1) {
            return 0;
        }
        else if (player == PIECE_RED && end_row != start_row - 1) {
            return 0;
        }
        if (end_col != start_col - 1 && end_col != start_col + 1) {
            return 0;
        }
        if (board[end_row][end_col] != PIECE_EMPTY) {
            return 0;
        }
    }

    // Check if king is moving diagonally
    if (board[start_row][start_col] == (player == PIECE_BLACK ? PIECE_KING_B : PIECE_KING_R)) {
        if (abs(end_row - start_row) != abs(end_col - start_col)) {
            return 0;
        }
        int row_inc = end_row > start_row ? 1 : -1;
        int col_inc = end_col > start_col ? 1 : -1;
        int row = start_row + row_inc;
        int col = start_col + col_inc;
        while (row != end_row && col != end_col) {
            if (board[row][col] != PIECE_EMPTY) {
                return 0;
            }
            row += row_inc;
            col += col_inc;
        }
    }

    return 1;
}