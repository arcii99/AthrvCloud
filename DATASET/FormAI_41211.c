//FormAI DATASET v1.0 Category: Chess engine ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
char starting_fen[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
char *fen = starting_fen;

void print_board() {
    int row, col;

    printf("\n");
    for (row = 0; row < BOARD_SIZE; ++row) {
        for (col = 0; col < BOARD_SIZE; ++col) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void init_board() {
    int row, col;

    for (row = 0; row < BOARD_SIZE; ++row) {
        for (col = 0; col < BOARD_SIZE; ++col) {
            board[row][col] = 0;
        }
    }
}

void set_fen(const char *new_fen) {
    fen = strdup(new_fen);
}

void parse_fen() {
    char *token;
    char *fen_copy = strdup(fen);
    char *fen_part[6];
    int index = 0;

    token = strtok(fen_copy, " ");

    while (token != NULL) {
        fen_part[index++] = token;
        token = strtok(NULL, " ");
    }

    // TODO: parse each part of the FEN string
}

int main() {
    // TODO: initialize the chess engine
    set_fen(starting_fen);
    parse_fen();
    init_board();

    // TODO: start game loop
    printf("Chess engine initialized. Ready to play!");
    print_board();

    return 0;
}