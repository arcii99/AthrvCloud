//FormAI DATASET v1.0 Category: Chess engine ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Board size
#define BOARD_SIZE 8

// Maximum length for input buffer
#define MAX_INPUT_LENGTH 20

// Piece color
typedef enum {
    WHITE,
    BLACK
} color;

// Chess piece
typedef struct {
    char name;    // could be L (for knight), K (for king), Q (for queen), R (for rook), B (for bishop), or P (for pawn)
    color c;      // piece color
    bool moved;   // whether the piece has moved before
} piece;

// Chess square
typedef struct {
    piece p;           // chess piece on this square
    bool highlighted;  // whether the square should be highlighted
} square;

// Chess board
typedef struct {
    square board[BOARD_SIZE][BOARD_SIZE];
} chessboard;

// Function to initialize the chess board
void init_board(chessboard *cb) {
    // Initialize pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        cb->board[1][i].p.name = 'P';  // White pawn
        cb->board[1][i].p.c = WHITE;
        cb->board[1][i].p.moved = false;
        cb->board[6][i].p.name = 'P';  // Black pawn
        cb->board[6][i].p.c = BLACK;
        cb->board[6][i].p.moved = false;
    }
    // Initialize knights
    cb->board[0][1].p.name = 'L';  // White knight
    cb->board[0][1].p.c = WHITE;
    cb->board[0][1].p.moved = false;
    cb->board[0][6].p.name = 'L';  // White knight
    cb->board[0][6].p.c = WHITE;
    cb->board[0][6].p.moved = false;
    cb->board[7][1].p.name = 'L';  // Black knight
    cb->board[7][1].p.c = BLACK;
    cb->board[7][1].p.moved = false;
    cb->board[7][6].p.name = 'L';  // Black knight
    cb->board[7][6].p.c = BLACK;
    cb->board[7][6].p.moved = false;
    // Initialize bishops
    cb->board[0][2].p.name = 'B';  // White bishop
    cb->board[0][2].p.c = WHITE;
    cb->board[0][2].p.moved = false;
    cb->board[0][5].p.name = 'B';  // White bishop
    cb->board[0][5].p.c = WHITE;
    cb->board[0][5].p.moved = false;
    cb->board[7][2].p.name = 'B';  // Black bishop
    cb->board[7][2].p.c = BLACK;
    cb->board[7][2].p.moved = false;
    cb->board[7][5].p.name = 'B';  // Black bishop
    cb->board[7][5].p.c = BLACK;
    cb->board[7][5].p.moved = false;
    // Initialize rooks
    cb->board[0][0].p.name = 'R';  // White rook
    cb->board[0][0].p.c = WHITE;
    cb->board[0][0].p.moved = false;
    cb->board[0][7].p.name = 'R';  // White rook
    cb->board[0][7].p.c = WHITE;
    cb->board[0][7].p.moved = false;
    cb->board[7][0].p.name = 'R';  // Black rook
    cb->board[7][0].p.c = BLACK;
    cb->board[7][0].p.moved = false;
    cb->board[7][7].p.name = 'R';  // Black rook
    cb->board[7][7].p.c = BLACK;
    cb->board[7][7].p.moved = false;
    // Initialize queens
    cb->board[0][3].p.name = 'Q';  // White queen
    cb->board[0][3].p.c = WHITE;
    cb->board[0][3].p.moved = false;
    cb->board[7][3].p.name = 'Q';  // Black queen
    cb->board[7][3].p.c = BLACK;
    cb->board[7][3].p.moved = false;
    // Initialize kings
    cb->board[0][4].p.name = 'K';  // White king
    cb->board[0][4].p.c = WHITE;
    cb->board[0][4].p.moved = false;
    cb->board[7][4].p.name = 'K';  // Black king
    cb->board[7][4].p.c = BLACK;
    cb->board[7][4].p.moved = false;
}

// Function to print the chess board
void print_board(chessboard *cb) {
    printf("   ");
    for (char c = 'a'; c < 'a' + BOARD_SIZE; c++) {
        printf("%c  ", c);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (cb->board[i][j].highlighted) {
                printf("\033[1;32m");  // Green foreground
            }
            if (cb->board[i][j].p.name != '\0') {
                printf("%c ", cb->board[i][j].p.name);
            } else {
                printf(". ");
            }
            if (cb->board[i][j].highlighted) {
                printf("\033[0m");  // Reset colors
                cb->board[i][j].highlighted = false;
            }
        }
        printf("%d\n", BOARD_SIZE - i);
    }
    printf("   ");
    for (char c = 'a'; c < 'a' + BOARD_SIZE; c++) {
        printf("%c  ", c);
    }
    printf("\n");
}

// Function to convert a string column letter (like "a") to a numeric index (like 0)
int column_to_index(char col) {
    return col - 'a';
}

// Function to convert a string row number (like "2") to a numeric index (like 1)
int row_to_index(char row) {
    return BOARD_SIZE - (row - '0');
}

// Function to move a piece on the chess board
bool move_piece(chessboard *cb, int start_row, int start_col, int end_row, int end_col) {
    if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE
        || end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) {
        // Invalid row/column indices
        return false;
    }
    piece p = cb->board[start_row][start_col].p;
    if (p.name == '\0' || cb->board[end_row][end_col].p.c == p.c) {
        // No piece to move or the end square already has a piece of the same color
        return false;
    }
    switch (p.name) {
        case 'P':
            // Handle pawn moves
            if (p.c == WHITE) {
                if (end_row == start_row - 1 && end_col == start_col && cb->board[end_row][end_col].p.name == '\0') {
                    // Regular pawn move one square forward
                    cb->board[start_row][start_col].p.name = '\0';
                    cb->board[end_row][end_col].p = p;
                    cb->board[end_row][end_col].p.moved = true;
                    return true;
                } else if (end_row == start_row - 2 && end_col == start_col && start_row == BOARD_SIZE - 2
                           && cb->board[end_row][end_col].p.name == '\0' && cb->board[end_row + 1][end_col].p.name == '\0') {
                    // Pawn move two squares forward from starting position
                    cb->board[start_row][start_col].p.name = '\0';
                    cb->board[end_row][end_col].p = p;
                    cb->board[end_row][end_col].p.moved = true;
                    return true;
                } else if (end_row == start_row - 1 && abs(end_col - start_col) == 1
                           && cb->board[end_row][end_col].p.name != '\0' && cb->board[end_row][end_col].p.c == BLACK) {
                    // Pawn capture diagonal to the left or right
                    cb->board[start_row][start_col].p.name = '\0';
                    cb->board[end_row][end_col].p = p;
                    cb->board[end_row][end_col].p.moved = true;
                    return true;
                }
            } else {
                // Black pawn
                if (end_row == start_row + 1 && end_col == start_col && cb->board[end_row][end_col].p.name == '\0') {
                    // Regular pawn move one square forward
                    cb->board[start_row][start_col].p.name = '\0';
                    cb->board[end_row][end_col].p = p;
                    cb->board[end_row][end_col].p.moved = true;
                    return true;
                } else if (end_row == start_row + 2 && end_col == start_col && start_row == 1
                           && cb->board[end_row][end_col].p.name == '\0' && cb->board[end_row - 1][end_col].p.name == '\0') {
                    // Pawn move two squares forward from starting position
                    cb->board[start_row][start_col].p.name = '\0';
                    cb->board[end_row][end_col].p = p;
                    cb->board[end_row][end_col].p.moved = true;
                    return true;
                } else if (end_row == start_row + 1 && abs(end_col - start_col) == 1
                           && cb->board[end_row][end_col].p.name != '\0' && cb->board[end_row][end_col].p.c == WHITE) {
                    // Pawn capture diagonal to the left or right
                    cb->board[start_row][start_col].p.name = '\0';
                    cb->board[end_row][end_col].p = p;
                    cb->board[end_row][end_col].p.moved = true;
                    return true;
                }
            }
            break;
        case 'L':
            // Handle knight moves
            if ((abs(end_row - start_row) == 2 && abs(end_col - start_col) == 1)
                || (abs(end_row - start_row) == 1 && abs(end_col - start_col) == 2)) {
                // Valid L-shaped move
                cb->board[start_row][start_col].p.name = '\0';
                cb->board[end_row][end_col].p = p;
                cb->board[end_row][end_col].p.moved = true;
                return true;
            }
            break;
        case 'K':
            // Handle king moves
            if (abs(end_row - start_row) <= 1 && abs(end_col - start_col) <= 1) {
                // Valid king move
                cb->board[start_row][start_col].p.name = '\0';
                cb->board[end_row][end_col].p = p;
                cb->board[end_row][end_col].p.moved = true;
                return true;
            }
            break;
        case 'Q':
            // Handle queen moves
            if (start_row == end_row || start_col == end_col || abs(end_row - start_row) == abs(end_col - start_col)) {
                // Valid vertical/horizontal/diagonal move
                int row_dir = (end_row - start_row == 0) ? 0 : (end_row - start_row > 0) ? 1 : -1;
                int col_dir = (end_col - start_col == 0) ? 0 : (end_col - start_col > 0) ? 1 : -1;
                int r = start_row + row_dir;
                int c = start_col + col_dir;
                while (r != end_row || c != end_col) {
                    if (cb->board[r][c].p.name != '\0') {
                        // Invalid move because there is another piece on the path
                        return false;
                    }
                    r += row_dir;
                    c += col_dir;
                }
                // Valid move
                cb->board[start_row][start_col].p.name = '\0';
                cb->board[end_row][end_col].p = p;
                cb->board[end_row][end_col].p.moved = true;
                return true;
            }
            break;
        case 'R':
            // Handle rook moves
            if (start_row == end_row || start_col == end_col) {
                // Valid vertical/horizontal move
                int row_dir = (end_row - start_row == 0) ? 0 : (end_row - start_row > 0) ? 1 : -1;
                int col_dir = (end_col - start_col == 0) ? 0 : (end_col - start_col > 0) ? 1 : -1;
                int r = start_row + row_dir;
                int c = start_col + col_dir;
                while (r != end_row || c != end_col) {
                    if (cb->board[r][c].p.name != '\0') {
                        // Invalid move because there is another piece on the path
                        return false;
                    }
                    r += row_dir;
                    c += col_dir;
                }
                // Valid move
                cb->board[start_row][start_col].p.name = '\0';
                cb->board[end_row][end_col].p = p;
                cb->board[end_row][end_col].p.moved = true;
                return true;
            }
            break;
        case 'B':
            // Handle bishop moves
            if (abs(end_row - start_row) == abs(end_col - start_col)) {
                // Valid diagonal move
                int row_dir = (end_row - start_row > 0) ? 1 : -1;
                int col_dir = (end_col - start_col > 0) ? 1 : -1;
                int r = start_row + row_dir;
                int c = start_col + col_dir;
                while (r != end_row || c != end_col) {
                    if (cb->board[r][c].p.name != '\0') {
                        // Invalid move because there is another piece on the path
                        return false;
                    }
                    r += row_dir;
                    c += col_dir;
                }
                // Valid move
                cb->board[start_row][start_col].p.name = '\0';
                cb->board[end_row][end_col].p = p;
                cb->board[end_row][end_col].p.moved = true;
                return true;
            }
            break;
        default:
            break;
    }
    // Invalid move
    return false;
}

int main() {
    chessboard cb;
    init_board(&cb);
    printf("Welcome to the cheerful C Chess engine example program!\n");
    printf("To move a piece, enter the column letter and row number of the starting square, followed by the column letter and row number of the ending square.\n");
    printf("For example: a2 a4\n");
    printf("Good luck and have fun!\n\n");
    while (true) {
        print_board(&cb);
        printf("Enter move: ");
        char input[MAX_INPUT_LENGTH];
        fgets(input, MAX_INPUT_LENGTH, stdin);
        int start_col = column_to_index(input[0]);
        int start_row = row_to_index(input[1]);
        int end_col = column_to_index(input[3]);
        int end_row = row_to_index(input[4]);
        if (move_piece(&cb, start_row, start_col, end_row, end_col)) {
            printf("Move successful!\n");
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}