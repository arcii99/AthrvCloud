//FormAI DATASET v1.0 Category: Checkers Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void print_board(int *board);
int valid_move(int *board, int player, int start, int end);
void make_move(int *board, int player, int start, int end);

int main() {
    int board[BOARD_SIZE*BOARD_SIZE] = {
        0, 1, 0, 1, 0, 1, 0, 1,
        1, 0, 1, 0, 1, 0, 1, 0,
        0, 1, 0, 1, 0, 1, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        2, 0, 2, 0, 2, 0, 2, 0,
        0, 2, 0, 2, 0, 2, 0, 2,
        2, 0, 2, 0, 2, 0, 2, 0
    };
    int player = 1;
    int move[2];
    int start, end;
    int valid_input;

    printf("Checkers Game\n\n");
    while (1) {
        print_board(board);
        printf("Player %d's turn\n", player);
        do {
            valid_input = 1;
            printf("Enter move: ");
            scanf("%d %d", &move[0], &move[1]);
            start = move[0]-1 + (move[1]-1)*BOARD_SIZE;
            end = move[1]-1 + (move[1]-1)*BOARD_SIZE;
            if (!valid_move(board, player, start, end)) {
                printf("Invalid move, try again\n");
                valid_input = 0;
            }
        } while (!valid_input);
        make_move(board, player, start, end);
        player = player == 1 ? 2 : 1;
    }
    return 0;
}

void print_board(int *board) {
    int i, j;

    printf("  1 2 3 4 5 6 7 8\n");
    printf("  ---------------\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i+1);
        for (j = 0; j < BOARD_SIZE; j++) {
            switch (board[i*BOARD_SIZE+j]) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("X");
                    break;
                case 2:
                    printf("O");
                    break;
            }
            printf("|");
        }
        printf("%d\n", i+1);
        printf(" |---------------|\n");
    }
    printf("  1 2 3 4 5 6 7 8\n\n");
}

int valid_move(int *board, int player, int start, int end) {
    int dx, dy;

    if (start < 0 || start >= BOARD_SIZE*BOARD_SIZE ||
        end < 0 || end >= BOARD_SIZE*BOARD_SIZE)
        return 0;
    dx = end%BOARD_SIZE - start%BOARD_SIZE;
    dy = end/BOARD_SIZE - start/BOARD_SIZE;
    if (board[start] != player || board[end] != 0)
        return 0;
    if (player == 1) {
        if (dy == -1)
            return dx == -1 || dx == 1;
        if (dy == -2)
            return dx == -2 || dx == 2 &&
                board[start+(dx/2)+(dy/2)*BOARD_SIZE] == 2;
    } else {
        if (dy == 1)
            return dx == -1 || dx == 1;
        if (dy == 2)
            return dx == -2 || dx == 2 &&
                board[start+(dx/2)+(dy/2)*BOARD_SIZE] == 1;
    }
    return 0;
}

void make_move(int *board, int player, int start, int end) {
    board[end] = player;
    board[start] = 0;
    if (player == 1 && end/BOARD_SIZE == 0)
        board[end] = 3;
    if (player == 2 && end/BOARD_SIZE == BOARD_SIZE-1)
        board[end] = 4;
    if (abs(end-start) == 2) {
        board[start+(end-start)/2] = 0;
    }
}