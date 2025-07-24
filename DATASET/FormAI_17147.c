//FormAI DATASET v1.0 Category: Chess AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[8][8];
int player_turn;
int score[2];

void clear_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = 0;
        }
    }
}

void place_pieces() {
    for (int i = 0; i < 8; i++) {
        board[1][i] = -1;
        board[6][i] = 1;
    }
    board[0][0] = board[0][7] = -2;
    board[7][0] = board[7][7] = 2;
    board[0][1] = board[0][6] = -3;
    board[7][1] = board[7][6] = 3;
    board[0][2] = board[0][5] = -4;
    board[7][2] = board[7][5] = 4;
    board[0][3] = -5;
    board[7][3] = 5;
    board[0][4] = -6;
    board[7][4] = 6;
}

void print_board() {
    printf("    a b c d e f g h\n");
    printf("  +-----------------+\n");
    for (int i = 7; i >= 0; i--) {
        printf("%d |", i+1);
        for (int j = 0; j < 8; j++) {
            switch (board[i][j]) {
                case -1: printf("p|"); break;
                case -2: printf("r|"); break;
                case -3: printf("n|"); break;
                case -4: printf("b|"); break;
                case -5: printf("q|"); break;
                case -6: printf("k|"); break;
                case 0: printf(" |"); break;
                case 1: printf("|p"); break;
                case 2: printf("|r"); break;
                case 3: printf("|n"); break;
                case 4: printf("|b"); break;
                case 5: printf("|q"); break;
                case 6: printf("|k"); break;
            }
        }
        printf("| %d\n", i+1);
        printf("  +-----------------+\n");
    }
    printf("    a b c d e f g h\n");
}

int main() {
    clear_board();
    place_pieces();
    print_board();
    return 0;
}