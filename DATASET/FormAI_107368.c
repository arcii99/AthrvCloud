//FormAI DATASET v1.0 Category: Chess AI ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

// function to print the chess board
void print_board(char board[][SIZE]) {
    printf("\n  a b c d e f g h\n");  // column indices
    printf(" +----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d|", i+1);  // row index
        for (int j = 0; j < SIZE; j++) {
            printf("%c|", board[i][j]);  // print the piece at the position (i, j)
        }
        printf("%d", i+1);  // row index
        printf("\n +----------------+\n");
    }
    printf("  a b c d e f g h\n");  // column indices
}

// function to check if the move is valid
int is_valid_move(char board[][SIZE], char piece, int row, int col, int new_row, int new_col) {
    // make sure the new position is within the board limits
    if (new_row < 0 || new_row >= SIZE || new_col < 0 || new_col >= SIZE) {
        return 0;
    }
    // make sure the piece is not trying to move to its current position
    if (row == new_row && col == new_col) {
        return 0;
    }
    // make sure the new position is empty or occupied by an enemy piece
    if (board[new_row][new_col] != '.' && board[new_row][new_col] != ' ' && board[new_row][new_col] == piece) {
        return 0;
    }
    // move logic based on the piece type
    switch(piece) {
        case 'P':  // pawn
            // white pawn moves
            if (board[row][col] == 'P') {
                // move one step forward
                if (new_row == row-1 && new_col == col && board[new_row][new_col] == '.') {
                    return 1;
                }
                // move two steps forward (if it is the first move for the pawn)
                if (new_row == row-2 && new_col == col && row == SIZE-2 && board[new_row][new_col] == '.' && board[new_row+1][new_col] == '.') {
                    return 1;
                }
                // capture a piece diagonally
                if (new_row == row-1 && (new_col == col-1 || new_col == col+1) && (board[new_row][new_col] != '.' && board[new_row][new_col] != ' ')) {
                    return 1;
                }
            }
            // black pawn moves
            if (board[row][col] == 'p') {
                // move one step forward
                if (new_row == row+1 && new_col == col && board[new_row][new_col] == '.') {
                    return 1;
                }
                // move two steps forward (if it is the first move for the pawn)
                if (new_row == row+2 && new_col == col && row == 1 && board[new_row][new_col] == '.' && board[new_row-1][new_col] == '.') {
                    return 1;
                }
                // capture a piece diagonally
                if (new_row == row+1 && (new_col == col-1 || new_col == col+1) && (board[new_row][new_col] != '.' && board[new_row][new_col] != ' ')) {
                    return 1;
                }
            }
            break;
        case 'R':  // rook
            // vertical movement
            if (new_col == col) {
                int min_row = row<new_row ? row : new_row;  // minimum row index
                int max_row = row>new_row ? row : new_row;  // maximum row index
                for (int i = min_row+1; i < max_row; i++) {  // check if there is any piece in between
                    if (board[i][col] != '.' && board[i][col] != ' ') {
                        return 0;
                    }
                }
                return 1;
            }
            // horizontal movement
            if (new_row == row) {
                int min_col = col<new_col ? col : new_col;  // minimum column index
                int max_col = col>new_col ? col : new_col;  // maximum column index
                for (int i = min_col+1; i < max_col; i++) {  // check if there is any piece in between
                    if (board[row][i] != '.' && board[row][i] != ' ') {
                        return 0;
                    }
                }
                return 1;
            }
            break;
        case 'N':  // knight
            if (abs(new_row-row) == 2 && abs(new_col-col) == 1) {
                return 1;
            }
            if (abs(new_row-row) == 1 && abs(new_col-col) == 2) {
                return 1;
            }
            break;
        case 'B':  // bishop
            // diagonal movement
            int d_row = new_row-row;  // row distance
            int d_col = new_col-col;  // column distance
            if (abs(d_row) == abs(d_col)) {  // if both distances are equal, this is a diagonal movement
                int row_dir = d_row>0 ? 1 : -1;  // row direction
                int col_dir = d_col>0 ? 1 : -1;  // column direction
                int i = row+row_dir;
                int j = col+col_dir;
                while (i != new_row && j != new_col) {  // check if there is any piece in between
                    if (board[i][j] != '.' && board[i][j] != ' ') {
                        return 0;
                    }
                    i += row_dir;
                    j += col_dir;
                }
                return 1;
            }
            break;
        case 'Q':  // queen
            // vertical movement
            if (new_col == col) {
                int min_row = row<new_row ? row : new_row;  // minimum row index
                int max_row = row>new_row ? row : new_row;  // maximum row index
                for (int i = min_row+1; i < max_row; i++) {  // check if there is any piece in between
                    if (board[i][col] != '.' && board[i][col] != ' ') {
                        return 0;
                    }
                }
                return 1;
            }
            // horizontal movement
            if (new_row == row) {
                int min_col = col<new_col ? col : new_col;  // minimum column index
                int max_col = col>new_col ? col : new_col;  // maximum column index
                for (int i = min_col+1; i < max_col; i++) {  // check if there is any piece in between
                    if (board[row][i] != '.' && board[row][i] != ' ') {
                        return 0;
                    }
                }
                return 1;
            }
            // diagonal movement
            d_row = new_row-row;  // row distance
            d_col = new_col-col;  // column distance
            if (abs(d_row) == abs(d_col)) {  // if both distances are equal, this is a diagonal movement
                int row_dir = d_row>0 ? 1 : -1;  // row direction
                int col_dir = d_col>0 ? 1 : -1;  // column direction
                int i = row+row_dir;
                int j = col+col_dir;
                while (i != new_row && j != new_col) {  // check if there is any piece in between
                    if (board[i][j] != '.' && board[i][j] != ' ') {
                        return 0;
                    }
                    i += row_dir;
                    j += col_dir;
                }
                return 1;
            }
            break;
        case 'K':  // king
            if (abs(new_row-row) <= 1 && abs(new_col-col) <= 1) {
                return 1;
            }
            break;
    }
    return 0;  // the move is invalid
}

// function to make the move
void make_move(char board[][SIZE], int row, int col, int new_row, int new_col) {
    board[new_row][new_col] = board[row][col];  // move the piece to the new position
    board[row][col] = '.';  // mark the old position as empty
}

// function to get a random valid move
void get_random_move(char board[][SIZE], char piece, int *row, int *col, int *new_row, int *new_col) {
    int valid_move = 0;
    while (!valid_move) {
        // generate random positions
        *row = rand() % SIZE;  // row index of the piece to be moved
        *col = rand() % SIZE;  // column index of the piece to be moved
        *new_row = rand() % SIZE;  // row index of the new position
        *new_col = rand() % SIZE;  // column index of the new position
        // check if the move is valid
        valid_move = is_valid_move(board, piece, *row, *col, *new_row, *new_col);
    }
}

int main() {
    char board[SIZE][SIZE] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };  // initial chess board representation
    printf("Initial chess board:\n");
    print_board(board);  // print the initial chess board
    printf("\n");

    int game_over = 0;
    int turn = 0;  // white: 0, black: 1
    while (!game_over) {
        if (turn == 0) {
            printf("White's turn:\n");  // white's turn
        }
        else {
            printf("Black's turn:\n");  // black's turn
        }
        int row, col, new_row, new_col;  // position variables
        char piece;
        if (turn == 0) {
            piece = 'P';  // white pawn
            get_random_move(board, piece, &row, &col, &new_row, &new_col);  // get a random valid move for white pawn
        }
        else {
            piece = 'p';  // black pawn
            get_random_move(board, piece, &row, &col, &new_row, &new_col);  // get a random valid move for black pawn
        }
        make_move(board, row, col, new_row, new_col);  // execute the move
        print_board(board);  // print the updated chess board
        
        // check if we have a winner or if the game is a draw
        // TODO

        turn = 1 - turn;  // switch turn
    }
    return 0;
}