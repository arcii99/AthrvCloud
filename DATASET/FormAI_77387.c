//FormAI DATASET v1.0 Category: Chess engine ; Style: minimalist
#include <stdio.h>

#define ROWS 8
#define COLS 8

char board[ROWS][COLS];

void initialize_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    printf("   A B C D E F G H\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d| ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("   A B C D E F G H\n");
}

void setup_board() {
    // Set up pawns
    for (int i = 0; i < COLS; i++) {
        board[1][i] = 'P';
        board[6][i] = 'p';
    }

    // Set up rooks, knights, bishops
    board[0][0] = board[0][7] = 'R';
    board[7][0] = board[7][7] = 'r';

    board[0][1] = board[0][6] = 'N';
    board[7][1] = board[7][6] = 'n';

    board[0][2] = board[0][5] = 'B';
    board[7][2] = board[7][5] = 'b';

    // Set up queens and kings
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[7][3] = 'q';
    board[7][4] = 'k';
}

int main() {
    initialize_board();
    setup_board();
    print_board();

    return 0;
}