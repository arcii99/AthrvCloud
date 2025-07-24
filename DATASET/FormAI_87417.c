//FormAI DATASET v1.0 Category: Checkers Game ; Style: brave
#include <stdio.h>

// Defining constants
#define SIZE 8
#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '.'

// Struct to hold each piece's data
typedef struct {
    char color;
    int row;
    int col;
} Piece;

// Initialize the board with pieces in their starting positions
void init_board(char board[][SIZE], Piece pieces[]) {
    int i,j;
    // Set all spaces to empty
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    // Set up black pieces
    for (i=0; i<3; i++) {
        for (j=0; j<SIZE; j++) {
            if ((i+j) % 2 == 0) {
                board[i][j] = BLACK;
                pieces[3*i+j/2].color = BLACK;
                pieces[3*i+j/2].row = i;
                pieces[3*i+j/2].col = j/2;
            }
        }
    }
    // Set up white pieces
    for (i=SIZE-3; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            if ((i+j) % 2 == 0) {
                board[i][j] = WHITE;
                pieces[3*(SIZE-3-i)+j/2+12].color = WHITE;
                pieces[3*(SIZE-3-i)+j/2+12].row = i;
                pieces[3*(SIZE-3-i)+j/2+12].col = j/2;
            }
        }  
    }
}

// Print the board and the pieces on it
void print_board(char board[][SIZE], Piece pieces[]) {
    int i,j;
    printf("  ");
    for (i=0; i<SIZE; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    for (i=0; i<SIZE; i++) {
        printf("%c ", 'a'+i);
        for (j=0; j<SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (i=0; i<24; i++) {
        printf("%c%d: %c, %d, %d\n", pieces[i].color, i+1, 'a'+pieces[i].row, pieces[i].col+1);
    }
}

// Check if a move is valid
int valid_move(char board[][SIZE], Piece pieces[], int from, int to) {
    // Check if the to position is empty
    if (board[pieces[to].row][pieces[to].col] != EMPTY) {
        return 0;
    }
    // Check if the move is diagonal
    if (pieces[from].row-pieces[to].row != pieces[from].col-pieces[to].col && pieces[from].row-pieces[to].row != pieces[to].col-pieces[from].col) {
        return 0;
    }
    // Check if the piece is moving in the right direction
    if (pieces[from].color == BLACK && pieces[from].row-pieces[to].row < 0) {
        return 0;
    } else if (pieces[from].color == WHITE && pieces[from].row-pieces[to].row > 0) {
        return 0;
    }
    // Check if there are any pieces in between from and to positions
    int row_inc = (pieces[from].row-pieces[to].row)/abs(pieces[from].row-pieces[to].row);
    int col_inc = (pieces[from].col-pieces[to].col)/abs(pieces[from].col-pieces[to].col);
    int row = pieces[from].row+row_inc;
    int col = pieces[from].col+col_inc;
    while (row != pieces[to].row) {
        if (board[row][col] != EMPTY) {
            return 0;
        }
        row += row_inc;
        col += col_inc;
    }
    return 1;
}

// Move a piece from one position to another
void move_piece(char board[][SIZE], Piece pieces[], int from, int to) {
    board[pieces[to].row][pieces[to].col] = pieces[from].color;
    board[pieces[from].row][pieces[from].col] = EMPTY;
    pieces[from].row = pieces[to].row;
    pieces[from].col = pieces[to].col;
    pieces[to].color = pieces[from].color;
}

// Main function
int main() {
    char board[SIZE][SIZE];
    Piece pieces[24];
    init_board(board, pieces);
    print_board(board, pieces);
    int from, to, valid;
    while (1) {
        printf("Enter piece to move: ");
        scanf("%d", &from);
        printf("Enter position to move to: ");
        scanf("%d", &to);
        valid = valid_move(board, pieces, from-1, to-1);
        if (valid) {
            move_piece(board, pieces, from-1, to-1);
            print_board(board, pieces);
        } else {
            printf("Invalid move\n");
        }
    }
    return 0;
}