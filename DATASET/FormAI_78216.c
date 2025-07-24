//FormAI DATASET v1.0 Category: Chess engine ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { WHITE, BLACK } color;
typedef enum { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } piece;

typedef struct {
    piece piece;
    color color;
} Square;

Square board[BOARD_SIZE][BOARD_SIZE] = { 0 };

void initialize_board() {
    // Set up the pawns
    for(int i=0; i<BOARD_SIZE; i++) {
        board[1][i].piece = PAWN;
        board[1][i].color = BLACK;
        board[6][i].piece = PAWN;
        board[6][i].color = WHITE;
    }
    // Set up the knights
    board[0][1].piece = board[0][6].piece = KNIGHT;
    board[7][1].piece = board[7][6].piece = KNIGHT;
    board[0][1].color = board[7][1].color = BLACK;
    board[0][6].color = board[7][6].color = WHITE;
    // Set up the bishops
    board[0][2].piece = board[0][5].piece = BISHOP;
    board[7][2].piece = board[7][5].piece = BISHOP;
    board[0][2].color = board[7][2].color = BLACK;
    board[0][5].color = board[7][5].color = WHITE;
    // Set up the rooks
    board[0][0].piece = board[0][7].piece = ROOK;
    board[7][0].piece = board[7][7].piece = ROOK;
    board[0][0].color = board[7][0].color = BLACK;
    board[0][7].color = board[7][7].color = WHITE;
    // Set up the queens
    board[0][3].piece = QUEEN;
    board[7][3].piece = QUEEN;
    board[0][3].color = BLACK;
    board[7][3].color = WHITE;
    // Set up the kings
    board[0][4].piece = KING;
    board[7][4].piece = KING;
    board[0][4].color = BLACK;
    board[7][4].color = WHITE;
}

void print_board() {
    printf("  ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" %c ", 'a'+i);
    }
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            char c = ' ';
            switch(board[i][j].piece) {
                case EMPTY:
                    c = ' ';
                    break;
                case PAWN:
                    c = 'P';
                    break;
                case KNIGHT:
                    c = 'N';
                    break;
                case BISHOP:
                    c = 'B';
                    break;
                case ROOK:
                    c = 'R';
                    break;
                case QUEEN:
                    c = 'Q';
                    break;
                case KING:
                    c = 'K';
                    break;
            }
            if(board[i][j].color == WHITE) {
                c = tolower(c);
            }
            printf("|%c", c);
        }
        printf("|%d\n", i+1);
    }
    printf("  ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf(" %c ", 'a'+i);
    }
    printf("\n");
}

int main() {
    initialize_board();
    print_board();
    return 0;
}