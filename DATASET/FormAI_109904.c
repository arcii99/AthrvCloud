//FormAI DATASET v1.0 Category: Chess engine ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[8][8] = {{-4, -2, -3, -5, -6, -3, -2, -4},
                   {-1, -1, -1, -1, -1, -1, -1, -1},
                   { 0,  0,  0,  0,  0,  0,  0,  0},
                   { 0,  0,  0,  0,  0,  0,  0,  0},
                   { 0,  0,  0,  0,  0,  0,  0,  0},
                   { 0,  0,  0,  0,  0,  0,  0,  0},
                   { 1,  1,  1,  1,  1,  1,  1,  1},
                   { 4,  2,  3,  5,  6,  3,  2,  4}};

void print_board() {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            printf("%c ", " PNBRQKpnbrqk"[board[rank][file] + 6]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int turn = 0;
    while (1) {
        printf("Turn %d:\n", turn);
        print_board();
        int from_file, from_rank, to_file, to_rank;
        do {
            from_file = rand() % 8;
            from_rank = rand() % 8;
        } while (board[from_rank][from_file] == 0 || (turn % 2 == 0 && board[from_rank][from_file] > 0) || (turn % 2 == 1 && board[from_rank][from_file] < 0));
        do {
            to_file = rand() % 8;
            to_rank = rand() % 8;
        } while (board[from_rank][from_file] == board[to_rank][to_file] || board[from_rank][from_file] * board[to_rank][to_file] > 0);
        board[to_rank][to_file] = board[from_rank][from_file];
        board[from_rank][from_file] = 0;
        turn++;
    }
    return 0;
}