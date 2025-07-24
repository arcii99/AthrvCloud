//FormAI DATASET v1.0 Category: Chess AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

struct Move {
    int from_x;
    int from_y;
    int to_x;
    int to_y;
};

void print_board(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    int x, y;

    printf("  a b c d e f g h\n");

    for (y = 0; y < BOARD_HEIGHT; y++) {
        printf("%d ", y + 1);

        for (x = 0; x < BOARD_WIDTH; x++) {
            printf("%c ", board[y][x]);
        }

        printf("%d\n", y + 1);
    }

    printf("  a b c d e f g h\n");
}

void initialize_board(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    int x, y;

    for (y = 0; y < BOARD_HEIGHT; y++) {
        for (x = 0; x < BOARD_WIDTH; x++) {
            if (y == 0 && (x == 0 || x == 7)) {
                board[y][x] = 'R';
            } else if (y == 0 && (x == 1 || x == 6)) {
                board[y][x] = 'N';
            } else if (y == 0 && (x == 2 || x == 5)) {
                board[y][x] = 'B';
            } else if (y == 0 && x == 3) {
                board[y][x] = 'Q';
            } else if (y == 0 && x == 4) {
                board[y][x] = 'K';
            } else if (y == 1) {
                board[y][x] = 'P';
            } else if (y == 6) {
                board[y][x] = 'p';
            } else if (y == 7 && (x == 0 || x == 7)) {
                board[y][x] = 'r';
            } else if (y == 7 && (x == 1 || x == 6)) {
                board[y][x] = 'n';
            } else if (y == 7 && (x == 2 || x == 5)) {
                board[y][x] = 'b';
            } else if (y == 7 && x == 3) {
                board[y][x] = 'q';
            } else if (y == 7 && x == 4) {
                board[y][x] = 'k';
            } else {
                board[y][x] = '.';
            }
        }
    }
}

int is_valid_move(char board[BOARD_HEIGHT][BOARD_WIDTH], struct Move move) {
    char piece = board[move.from_y][move.from_x];

    if (move.from_x < 0 || move.from_x >= BOARD_WIDTH ||
        move.from_y < 0 || move.from_y >= BOARD_HEIGHT ||
        move.to_x < 0 || move.to_x >= BOARD_WIDTH ||
        move.to_y < 0 || move.to_y >= BOARD_HEIGHT) {
        return 0;
    }

    if (move.from_x == move.to_x && move.from_y == move.to_y) {
        return 0;
    }

    if (piece == 'P') {
        if (move.to_y == move.from_y - 1 && 
            move.to_x == move.from_x && 
            board[move.to_y][move.to_x] == '.') {
            return 1;
        } else if (move.to_y == move.from_y - 2 && move.from_y == 6 &&
                   move.to_x == move.from_x && 
                   board[move.to_y][move.to_x] == '.' &&
                   board[move.to_y + 1][move.to_x] == '.') {
            return 1;
        } else if (move.to_y == move.from_y - 1 && 
                   (move.to_x == move.from_x - 1 || 
                    move.to_x == move.from_x + 1) && 
                   board[move.to_y][move.to_x] != '.') {
            return 1;
        }
    }

    // TODO: implement other piece rules

    return 0;
} 

void make_move(char board[BOARD_HEIGHT][BOARD_WIDTH], struct Move move) {
    board[move.from_y][move.from_x] = '.';
    board[move.to_y][move.to_x] = 'P';
}

int main() {
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    struct Move move;
    int i;

    initialize_board(board);
    print_board(board);

    for (i = 0; i < 100; i++) {
        move.from_x = rand() % BOARD_WIDTH;
        move.from_y = rand() % BOARD_HEIGHT;
        move.to_x = rand() % BOARD_WIDTH;
        move.to_y = rand() % BOARD_HEIGHT;

        if (is_valid_move(board, move)) {
            make_move(board, move);
            print_board(board);
        }
    }

    return 0;
}