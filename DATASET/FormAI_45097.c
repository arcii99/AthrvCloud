//FormAI DATASET v1.0 Category: Checkers Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define EMPTY 0
#define BLACK 1
#define RED 2

typedef struct {
    int x;
    int y;
} Move;

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} GameState;

Move get_move(char* str) {
    Move move;
    sscanf(str, "%d,%d", &move.x, &move.y);
    printf("Player moved to (%d,%d)\n", move.x, move.y);
    return move;
}

void display_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(" |");
            } else if (board[i][j] == BLACK) {
                printf("B|");
            } else if (board[i][j] == RED) {
                printf("R|");
            }
        }
        printf("\n");
    }
}

int check_win(int board[BOARD_SIZE][BOARD_SIZE]) {
    int black_left = 0;
    int red_left = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == BLACK) {
                black_left++;
            } else if (board[i][j] == RED) {
                red_left++;
            }
        }
    }
    if (red_left == 0) {
        return BLACK;
    } else if (black_left == 0) {
        return RED;
    } else {
        return 0;
    }
}

int main(int argc, char* argv[]) {
    GameState state;
    memset(state.board, 0, sizeof(state.board));
    state.turn = BLACK;
    int winner = 0;
    int player = BLACK;
    char input[256];
    Move move;
    while (winner == 0) {
        display_board(state.board);
        printf("Player %d's turn. Enter move (x,y): ", player);
        fgets(input, 256, stdin);
        input[strcspn(input, "\n")] = 0; // remove trailing newline
        move = get_move(input);
        if (state.board[move.x][move.y] == player) {
            printf("Invalid move: can't move to your own piece.\n");
            continue;
        }
        if (player == BLACK && move.x > state.turn) {
            printf("Invalid move: can't move backwards.\n");
            continue;
        }
        if (player == RED && move.x < state.turn) {
            printf("Invalid move: can't move backwards.\n");
            continue;
        }
        if (move.x < 0 || move.x >= BOARD_SIZE || move.y < 0 || move.y >= BOARD_SIZE) {
            printf("Invalid move: out of bounds.\n");
            continue;
        }
        int dx = abs(move.x - state.turn);
        int dy = abs(move.y - state.turn);
        if (dx != 1 || dy != 1) {
            printf("Invalid move: must move diagonally 1 space.\n");
            continue;
        }
        if (state.board[move.x][move.y] != EMPTY) {
            printf("Invalid move: position already occupied.\n");
            continue;
        }
        state.board[move.x][move.y] = player;
        state.turn = move.x;
        winner = check_win(state.board);
        if (player == BLACK) {
            player = RED;
        } else {
            player = BLACK;
        }
    }
    display_board(state.board);
    if (winner == BLACK) {
        printf("Black wins!\n");
    } else {
        printf("Red wins!\n");
    }
    return 0;
}