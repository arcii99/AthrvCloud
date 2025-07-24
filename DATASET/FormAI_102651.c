//FormAI DATASET v1.0 Category: Chess engine ; Style: medieval
/* Medieval Chess Engine */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold each piece on the board
typedef struct board_piece {
    char type; // K=King, Q=Queen, R=Rook, B=Bishop, N=Knight, P=Pawn
    char color; // W=White, B=Black
} board_piece;

// global variables
const int BOARD_SIZE = 8;
board_piece board[8][8];

// initialize the chess board with pieces in starting position
void initialize_board() {
    // pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i].type = 'P';
        board[1][i].color = 'B';
        board[6][i].type = 'P';
        board[6][i].color = 'W';
    }

    // rooks
    board[0][0].type = 'R';
    board[0][0].color = 'B';
    board[0][7].type = 'R';
    board[0][7].color = 'B';
    board[7][0].type = 'R';
    board[7][0].color = 'W';
    board[7][7].type = 'R';
    board[7][7].color = 'W';

    // knights
    board[0][1].type = 'N';
    board[0][1].color = 'B';
    board[0][6].type = 'N';
    board[0][6].color = 'B';
    board[7][1].type = 'N';
    board[7][1].color = 'W';
    board[7][6].type = 'N';
    board[7][6].color = 'W';

    // bishops
    board[0][2].type = 'B';
    board[0][2].color = 'B';
    board[0][5].type = 'B';
    board[0][5].color = 'B';
    board[7][2].type = 'B';
    board[7][2].color = 'W';
    board[7][5].type = 'B';
    board[7][5].color = 'W';

    // queens
    board[0][3].type = 'Q';
    board[0][3].color = 'B';
    board[7][3].type = 'Q';
    board[7][3].color = 'W';

    // kings
    board[0][4].type = 'K';
    board[0][4].color = 'B';
    board[7][4].type = 'K';
    board[7][4].color = 'W';
}

// print the current state of the chess board
void print_board() {
    printf("   A B C D E F G H\n");
    printf("  +---------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d | ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == '\0') {
                printf(". ");
            } else {
                printf("%c ", board[i][j].type);
            }
        }
        printf("| %d\n", BOARD_SIZE - i);
    }
    printf("  +---------------+\n");
    printf("   A B C D E F G H\n");
}

int main() {
    initialize_board();
    print_board();
    return 0;
}