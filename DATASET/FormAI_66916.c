//FormAI DATASET v1.0 Category: Chess AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a chess piece
typedef struct Piece {
    char name[2];
    int row;
    int col;
} Piece;

// Function to initialize the chess board
void init_board(char board[8][8]) {
    // Place black pieces
    board[0][0] = 'r';
    board[0][1] = 'n';
    board[0][2] = 'b';
    board[0][3] = 'q';
    board[0][4] = 'k';
    board[0][5] = 'b';
    board[0][6] = 'n';
    board[0][7] = 'r';
    for (int i = 0; i < 8; i++) {
        board[1][i] = 'p';
    }
    // Place white pieces
    board[7][0] = 'R';
    board[7][1] = 'N';
    board[7][2] = 'B';
    board[7][3] = 'Q';
    board[7][4] = 'K';
    board[7][5] = 'B';
    board[7][6] = 'N';
    board[7][7] = 'R';
    for (int i = 0; i < 8; i++) {
        board[6][i] = 'P';
    }
    // Fill empty spaces
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the chess board
void print_board(char board[8][8]) {
    printf("   a b c d e f g h\n");
    printf("  +-----------------+\n");
    for (int i = 7; i >= 0; i--) {
        printf("%d |", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("%c|", board[i][j]);
        }
        printf(" %d\n", i + 1);
        printf("  +-----------------+\n");
    }
    printf("   a b c d e f g h\n");
}

// Function to get user input for a move
void get_move(Piece *piece, int *new_row, int *new_col) {
    char move[5];
    printf("Enter your move (e.g. e2e4): ");
    scanf("%s", move);
    piece->col = move[0] - 'a';
    piece->row = move[1] - '1';
    *new_col = move[2] - 'a';
    *new_row = move[3] - '1';
}

// Function to check if a move is valid
int is_valid_move(char board[8][8], Piece piece, int new_row, int new_col) {
    // Check if movement is not out of bounds
    if (new_row > 7 || new_row < 0 || new_col > 7 || new_col < 0) {
        return 0;
    }
    // Check if there is no piece at the new location or if the piece at the new location is not of the same color
    if (board[new_row][new_col] == ' ' || (isupper(piece.name[0]) != isupper(board[new_row][new_col]))) {
        return 1;
    } else {
        return 0;
    }
}

// Main function to run the chess game
int main() {
    char board[8][8];
    init_board(board);
    print_board(board);

    int game_over = 0;
    while (!game_over) {
        // Get user input for piece to move and new location
        Piece piece;
        int new_row, new_col;
        get_move(&piece, &new_row, &new_col);
        
        // Check if move is valid
        if (is_valid_move(board, piece, new_row, new_col)) {
            // Update board with move
            board[new_row][new_col] = piece.name[0];
            board[piece.row][piece.col] = ' ';

            // Print updated board
            print_board(board);
        } else {
            printf("Invalid move. Please try again.\n");
        }

        // Check for game over conditions
        // Game over if king is captured
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'k' || board[i][j] == 'K') {
                    game_over = 1;
                    printf("Game over. %c wins!\n", board[i][j]);
                    break;
                }
            }
            if (game_over) {
                break;
            }
        }
    }

    return 0;
}