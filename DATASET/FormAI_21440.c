//FormAI DATASET v1.0 Category: Chess engine ; Style: protected
#include <stdio.h>
#include <stdlib.h>

/* Struct for chess piece */
typedef struct piece {
    char symbol; // piece symbol
    char color; // piece color
} piece_t;

/* Chessboard */
piece_t board[8][8];

/* Initialize the chessboard with starting positions */
void init_board() {
    // Pawns
    for (int i = 0; i < 8; i++) {
        board[1][i].symbol = 'P';
        board[1][i].color = 'w';
        board[6][i].symbol = 'P';
        board[6][i].color = 'b';
    }
    
    // Rooks
    board[0][0].symbol = 'R';
    board[0][0].color = 'w';
    board[0][7].symbol = 'R';
    board[0][7].color = 'w';
    board[7][0].symbol = 'R';
    board[7][0].color = 'b';
    board[7][7].symbol = 'R';
    board[7][7].color = 'b';

    // Knights
    board[0][1].symbol = 'N';
    board[0][1].color = 'w';
    board[0][6].symbol = 'N';
    board[0][6].color = 'w';
    board[7][1].symbol = 'N';
    board[7][1].color = 'b';
    board[7][6].symbol = 'N';
    board[7][6].color = 'b';

    // Bishops
    board[0][2].symbol = 'B';
    board[0][2].color = 'w';
    board[0][5].symbol = 'B';
    board[0][5].color = 'w';
    board[7][2].symbol = 'B';
    board[7][2].color = 'b';
    board[7][5].symbol = 'B';
    board[7][5].color = 'b';

    // Queens
    board[0][3].symbol = 'Q';
    board[0][3].color = 'w';
    board[7][3].symbol = 'Q';
    board[7][3].color = 'b';

    // Kings
    board[0][4].symbol = 'K';
    board[0][4].color = 'w';
    board[7][4].symbol = 'K';
    board[7][4].color = 'b';
}

/* Function to print the chessboard */
void print_board() {
    printf("\n   a b c d e f g h\n");
    printf("  +----------------+\n");
    for (int i = 0; i < 8; i++) {
        printf("%d | ", i+1);
        for (int j = 0; j < 8; j++) {
            if (board[i][j].symbol == '\0') {
                printf(". ");
            } else {
                printf("%c ", board[i][j].symbol);
            }
        }
        printf("| %d\n", i+1);
    }
    printf("  +----------------+\n");
    printf("   a b c d e f g h\n");
}

int main() {
    init_board();
    print_board();
    return 0;
}