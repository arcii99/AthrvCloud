//FormAI DATASET v1.0 Category: Chess engine ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    // Set the initial positions of the pieces
    // Rook
    board[0][0] = board[0][7] = 'R';
    // Knight
    board[0][1] = board[0][6] = 'N';
    // Bishop
    board[0][2] = board[0][5] = 'B';
    // Queen
    board[0][3] = 'Q';
    // King
    board[0][4] = 'K';
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'P'; // Pawns
    }
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-'; // Empty squares
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[6][i] = 'p'; // Pawns
    }
    // Rook
    board[7][0] = board[7][7] = 'r';
    // Knight
    board[7][1] = board[7][6] = 'n';
    // Bishop
    board[7][2] = board[7][5] = 'b';
    // Queen
    board[7][3] = 'q';
    // King
    board[7][4] = 'k';
}

void print_board() {
    printf("\n   A B C D E F G H\n");
    printf("  +-----------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            char piece = board[i][j];
            if (piece == '-') {
                printf(" ");
            } else {
                printf("%c", piece);
            }
            printf("|");
        }
        printf(" %d\n", i + 1);
        printf("  +-----------------+\n");
    }
    printf("   A B C D E F G H\n");
}

int main() {
    initialize_board();
    print_board();
    return 0;
}