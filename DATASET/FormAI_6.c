//FormAI DATASET v1.0 Category: Chess engine ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BOARD_SIZE 8

/* structure representing a chess piece */
typedef struct {
    char piece_type; // K (King), Q (Queen), R (Rook), B (Bishop), N (Knight), P (Pawn)
    char color; // W (White), B (Black)
} ChessPiece;

/* chess board array */
ChessPiece board[BOARD_SIZE][BOARD_SIZE];

/* function to initialize the chess board */
void initialize_board() {
    int i, j;

    /* initializing the pieces on the board */
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            if(i == 0 || i == 7) {
                if(j == 0 || j == 7) {
                    board[i][j].piece_type = 'R';
                    board[i][j].color = (i == 0) ? 'W' : 'B';
                }
                else if(j == 1 || j == 6) {
                    board[i][j].piece_type = 'N';
                    board[i][j].color = (i == 0) ? 'W' : 'B';
                }
                else if(j == 2 || j == 5) {
                    board[i][j].piece_type = 'B';
                    board[i][j].color = (i == 0) ? 'W' : 'B';
                }
                else if(j == 3) {
                    board[i][j].piece_type = 'Q';
                    board[i][j].color = (i == 0) ? 'W' : 'B';
                }
                else if(j == 4) {
                    board[i][j].piece_type = 'K';
                    board[i][j].color = (i == 0) ? 'W' : 'B';
                }
            }
            else if(i == 1 || i == 6) {
                board[i][j].piece_type = 'P';
                board[i][j].color = (i == 1) ? 'W' : 'B';
            }
            else {
                board[i][j].piece_type = ' ';
                board[i][j].color = ' ';
            }
        }
    }
}

/* function to print the chess board */
void print_board() {
    int i, j;

    printf("\n");
    /* printing the column indices */
    printf("   ");
    for(i=0; i<BOARD_SIZE; i++) {
        printf("%d  ", i+1);
    }
    printf("\n");

    /* printing the rows */
    for(i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i+1);
        printf("|");
        for(j=0; j<BOARD_SIZE; j++) {
            printf("%c%c|", board[i][j].piece_type, board[i][j].color);
        }
        printf("\n");
    }
}

int main() {
    initialize_board();
    print_board();

    return 0;
}