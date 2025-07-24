//FormAI DATASET v1.0 Category: Checkers Game ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

// Shape-shifting function declarations
void print_board(char board[][8]);
int check_move(char board[][8], int start_row, int start_col, int end_row, int end_col, char player);
void make_move(char board[][8], int start_row, int start_col, int end_row, int end_col, char player, int is_king);

// Main function
int main() {
    char board[8][8] = {
        { '_', 'r', '_', 'r', '_', 'r', '_', 'r' },
        { 'r', '_', 'r', '_', 'r', '_', 'r', '_' },
        { '_', 'r', '_', 'r', '_', 'r', '_', 'r' },
        { '_', '_', '_', '_', '_', '_', '_', '_' },
        { '_', '_', '_', '_', '_', '_', '_', '_' },
        { 'b', '_', 'b', '_', 'b', '_', 'b', '_' },
        { '_', 'b', '_', 'b', '_', 'b', '_', 'b' },
        { 'b', '_', 'b', '_', 'b', '_', 'b', '_' }
    };
    char player = 'r';
    int game_over = 0;

    // Game loop
    while (!game_over) {
        printf("The current state of the board is:\n");
        print_board(board);

        // Ask for player input
        int start_row, start_col, end_row, end_col;
        printf("%c's turn. Enter the row and column numbers for the piece you want to move (separated by a space): ", player);
        scanf("%d %d", &start_row, &start_col);
        printf("Enter the row and column numbers for the destination (separated by a space): ");
        scanf("%d %d", &end_row, &end_col);

        // Check if move is valid
        int valid_move = check_move(board, start_row, start_col, end_row, end_col, player);
        if (valid_move) {
            // Make the move
            int is_king = 0;
            if (player == 'r' && end_row == 0) {
                is_king = 1;
            } else if (player == 'b' && end_row == 7) {
                is_king = 1;
            }
            make_move(board, start_row, start_col, end_row, end_col, player, is_king);

            // Check if game is over
            // If there are no more pieces of the opposing player, or if the opposing player has no valid moves, the game is over
            char opposing_player = (player == 'r') ? 'b' : 'r';
            int opposing_pieces = 0;
            int opposing_moves = 0;
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    if (board[row][col] == opposing_player || board[row][col] == toupper(opposing_player)) {
                        opposing_pieces++;
                        if (check_move(board, row, col, row+1, col+1, opposing_player) ||
                            check_move(board, row, col, row+1, col-1, opposing_player) ||
                            check_move(board, row, col, row-1, col+1, opposing_player) ||
                            check_move(board, row, col, row-1, col-1, opposing_player)) {
                            opposing_moves++;
                        }
                    }
                }
            }
            if (opposing_pieces == 0 || opposing_moves == 0) {
                game_over = 1;
                printf("Game over! %c wins!\n", player);
            }

            // Switch players
            player = (player == 'r') ? 'b' : 'r';
        } else {
            printf("That move is invalid. Try again.\n");
        }
    }

    return 0;
}

// Shape-shifting function definitions
void print_board(char board[][8]) {
    printf("    0 1 2 3 4 5 6 7\n");
    for (int row = 0; row < 8; row++) {
        printf("  %d ", row);
        for (int col = 0; col < 8; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

int check_move(char board[][8], int start_row, int start_col, int end_row, int end_col, char player) {
    // Check if input is within bounds of board
    if (start_row < 0 || start_row > 7 || start_col < 0 || start_col > 7 || end_row < 0 || end_row > 7 || end_col < 0 || end_col > 7) {
        return 0;
    }

    // Check if end position is empty
    if (board[end_row][end_col] != '_') {
        return 0;
    }

    // Check if player is moving their own piece
    char piece = board[start_row][start_col];
    if (player == 'r' && piece != 'r' && piece != 'R') {
        return 0;
    }
    if (player == 'b' && piece != 'b' && piece != 'B') {
        return 0;
    }

    // Check if piece is moving in the right direction
    if (piece == 'r' && end_row >= start_row) {
        return 0;
    }
    if (piece == 'b' && end_row <= start_row) {
        return 0;
    }

    // Check if piece is moving diagonally and within one space
    int row_diff = abs(start_row - end_row);
    int col_diff = abs(start_col - end_col);
    if (row_diff != 1 || col_diff != 1) {
        return 0;
    }

    // Check if piece is trying to take an opposing piece
    char opposing_player = (player == 'r') ? 'b' : 'r';
    if ((piece == 'r' || piece == 'R') && end_row < start_row && 
       (board[end_row+1][end_col+1] == opposing_player || board[end_row+1][end_col-1] == opposing_player)) {
        return 1;
    }
    if ((piece == 'b' || piece == 'B') && end_row > start_row && 
       (board[end_row-1][end_col+1] == opposing_player || board[end_row-1][end_col-1] == opposing_player)) {
        return 1;
    }

    // Check if piece is trying to become a king
    if (piece == 'r' && end_row == 0) {
        return 1;
    }
    if (piece == 'b' && end_row == 7) {
        return 1;
    }

    return 0;
}

void make_move(char board[][8], int start_row, int start_col, int end_row, int end_col, char player, int is_king) {
    // Make the move
    char piece = board[start_row][start_col];
    board[start_row][start_col] = '_';
    board[end_row][end_col] = piece;

    // Make the piece a king if necessary
    if (is_king) {
        board[end_row][end_col] = toupper(piece);
    }

    // Take opposing piece if necessary
    char opposing_player = (player == 'r') ? 'b' : 'r';
    if ((piece == 'r' || piece == 'R') && end_row < start_row && 
       board[end_row+1][end_col+1] == opposing_player) {
        board[end_row+1][end_col+1] = '_';
    } else if ((piece == 'r' || piece == 'R') && end_row < start_row && 
              board[end_row+1][end_col-1] == opposing_player) {
        board[end_row+1][end_col-1] = '_';
    } else if ((piece == 'b' || piece == 'B') && end_row > start_row && 
              board[end_row-1][end_col+1] == opposing_player) {
        board[end_row-1][end_col+1] = '_';
    } else if ((piece == 'b' || piece == 'B') && end_row > start_row && 
              board[end_row-1][end_col-1] == opposing_player) {
        board[end_row-1][end_col-1] = '_';
    }
}