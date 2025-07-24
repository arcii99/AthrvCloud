//FormAI DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

// Create a 2D board with random values
void create_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Print the current state of the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Take a step in the game
void step(int board[BOARD_SIZE][BOARD_SIZE]) {
    int new_board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int count = 0;
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    if (a == 0 && b == 0) {
                        continue;
                    }
                    int row = i + a;
                    int col = j + b;
                    if (row < 0) {
                        row = BOARD_SIZE - 1;
                    } else if (row > BOARD_SIZE - 1) {
                        row = 0;
                    }
                    if (col < 0) {
                        col = BOARD_SIZE - 1;
                    } else if (col > BOARD_SIZE - 1) {
                        col = 0;
                    }
                    if (board[row][col] == 1) {
                        count++;
                    }
                }
            }
            if (board[i][j] == 1) {
                if (count < 2 || count > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if (count == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    create_board(board);
    for(int i=0; i<20; i++) {
        print_board(board);
        printf("\n");
        step(board);
    }
    return 0;
}