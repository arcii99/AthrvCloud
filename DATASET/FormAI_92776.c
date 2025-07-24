//FormAI DATASET v1.0 Category: Checkers Game ; Style: relaxed
#include <stdio.h>
#include <stdbool.h>

// Function to print the current state of the board
void print_board(int board[][8]) {
    printf("-----------------\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("|");
            switch (board[i][j]) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("r");
                    break;
                case 2:
                    printf("b");
                    break;
                case 3:
                    printf("R");
                    break;
                case 4:
                    printf("B");
                    break;
            }
        }
        printf("|\n");
        printf("-----------------\n");
    }
}

// Function to move a piece
void move_piece(int board[][8], int start_row, int start_col, int end_row, int end_col) {
    int current_piece = board[start_row][start_col]; // current piece at start position
    board[start_row][start_col] = 0; // make start position empty
    board[end_row][end_col] = current_piece; // move piece to end position
}

// Function to check if a move is valid
bool is_valid_move(int board[][8], int start_row, int start_col, int end_row, int end_col, int is_king) {
    int current_piece = board[start_row][start_col];

    // Ensure end position is within bounds
    if (end_row < 0 || end_row > 7 || end_col < 0 || end_col > 7) {
        return false;
    }

    // Ensure end position is empty
    if (board[end_row][end_col] != 0) {
        return false;
    }

    // Ensure piece is moving diagonally
    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;
    if (row_diff == 0 || col_diff == 0 || row_diff != col_diff) {
        return false;
    }

    // Ensure piece is moving in the right direction
    if (!is_king) {
        if (current_piece == 1 && row_diff > 0) { // red piece can only move upwards
            return false;
        } else if (current_piece == 2 && row_diff < 0) { // black piece can only move downwards
            return false;
        }
    }

    // Ensure piece is jumping over another piece if required
    if (row_diff == -2 || row_diff == 2) {
        int opponent_row = (start_row + end_row) / 2; // row of opponent piece
        int opponent_col = (start_col + end_col) / 2; // column of opponent piece
        int opponent_piece = board[opponent_row][opponent_col]; // opponent piece
        if (opponent_piece == 0 || (current_piece % 2 == opponent_piece % 2)) { // ensure opponent is present and is of different color
            return false;
        }
    }

    return true; // move is valid
}

// Function to check if a piece can jump over another piece
bool can_jump(int board[][8], int current_row, int current_col) {
    int current_piece = board[current_row][current_col];
    if (current_piece % 2 == 1) { // red piece can only jump upwards
        if (((current_row-2) >= 0) && ((current_col-2) >= 0) && (board[current_row-1][current_col-1] % 2 == 2) && (board[current_row-2][current_col-2] == 0)) { // can jump top left
            return true;
        } else if (((current_row-2) >= 0) && ((current_col+2) <= 7) && (board[current_row-1][current_col+1] % 2 == 2) && (board[current_row-2][current_col+2] == 0)) { // can jump top right
            return true;
        }
    } else { // black piece can only jump downwards
        if (((current_row+2) <= 7) && ((current_col-2) >= 0) && (board[current_row+1][current_col-1] % 2 == 1) && (board[current_row+2][current_col-2] == 0)) { // can jump bottom left
            return true;
        } else if (((current_row+2) <= 7) && ((current_col+2) <= 7) && (board[current_row+1][current_col+1] % 2 == 1) && (board[current_row+2][current_col+2] == 0)) { // can jump bottom right
            return true;
        }
    }
    return false; // cannot jump
}

// Function to make a move
void make_move(int board[][8], int start_row, int start_col, int end_row, int end_col) {
    int current_piece = board[start_row][start_col];

    // Make the move
    move_piece(board, start_row, start_col, end_row, end_col);

    // If the piece reaches the end, make it a King
    if ((current_piece == 1 && end_row == 0) || (current_piece == 2 && end_row == 7)) {
        board[end_row][end_col] += 2;
    }

    // If the piece can jump again, prompt for next move
    if (can_jump(board, end_row, end_col)) {
        printf("You can jump again! Enter new move:\n");
        int new_end_row, new_end_col;
        scanf("%d %d", &new_end_row, &new_end_col);
        if (is_valid_move(board, end_row, end_col, new_end_row, new_end_col, current_piece > 2)) {
            make_move(board, end_row, end_col, new_end_row, new_end_col);
        } else {
            printf("Invalid move!\n");
        }
    }
}

int main() {
    int board[8][8] = {0}; // initialize the board to a 8 x 8 grid filled with 0's
    // 0 - empty
    // 1 - red piece
    // 2 - black piece
    // 3 - red king
    // 4 - black king
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            // Place red pieces
            if ((row % 2 == 0 && col % 2 == 1 && row <= 2) || (row % 2 == 1 && col % 2 == 0 && row <= 2)) {
                board[row][col] = 1;
            }
            // Place black pieces
            if ((row % 2 == 1 && col % 2 == 0 && row >= 5) || (row % 2 == 0 && col % 2 == 1 && row >= 5)) {
                board[row][col] = 2;
            }
        }
    }

    print_board(board); // print the initial board
    printf("Enter a move (start_row start_col end_row end_col):\n");
    int start_row, start_col, end_row, end_col;
    scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);
    while (true) {
        if (is_valid_move(board, start_row, start_col, end_row, end_col, board[start_row][start_col] > 2)) {
            make_move(board, start_row, start_col, end_row, end_col); // valid move, make the move
            print_board(board); // print the new board
        } else {
            printf("Invalid move!\n");
        }
        printf("Enter a move (start_row start_col end_row end_col):\n");
        scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);
    }
    return 0;
}