//FormAI DATASET v1.0 Category: Chess engine ; Style: Ken Thompson
#include <stdio.h>

#define WHITE 0
#define BLACK 1
#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
int curr_player = WHITE;

void init_board() {
    for (int i=0; i<BOARD_SIZE; i++) {
        for (int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = -1;
        }
    }
    
    for (int i=0; i<BOARD_SIZE; i++) {
        board[1][i] = WHITE * 6;
        board[6][i] = BLACK * 6;
    }

    board[0][0] = board[0][7] = WHITE * 3;
    board[7][0] = board[7][7] = BLACK * 3;

    board[0][1] = board[0][6] = WHITE * 2;
    board[7][1] = board[7][6] = BLACK * 2;

    board[0][2] = board[0][5] = WHITE * 4;
    board[7][2] = board[7][5] = BLACK * 4;

    board[0][3] = WHITE * 5;
    board[7][3] = BLACK * 5;

    board[0][4] = WHITE * 1;
    board[7][4] = BLACK * 1;
}

void print_board() {
    printf("\n  a b c d e f g h\n");
    for (int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j=0; j<BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                printf(". ");
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("%d", BOARD_SIZE - i);
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int main() {
    init_board();
    print_board();
    return 0;
}