//FormAI DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 30
#define COLS 80

void print_board(char board[ROWS][COLS]) {
    system("clear"); // clear the screen
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 'X') {
                printf("\033[1;31m"); // change color to red for cells that are alive
                printf("%c", board[i][j]);
                printf("\033[0m");
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
}

void update_board(char board[ROWS][COLS]) {
    char new_board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int count = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x == i && y == j) continue;
                    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) continue;
                    if (board[x][y] == 'X') count++;
                }
            }
            if (count == 3 || (count == 2 && board[i][j] == 'X')) {
                new_board[i][j] = 'X';
            } else {
                new_board[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    char board[ROWS][COLS];
    // initialize board to all spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
    // draw glider
    board[3][1] = 'X';
    board[4][2] = 'X';
    board[2][3] = 'X';
    board[3][3] = 'X';
    board[4][3] = 'X';

    while (1) { // infinite loop
        print_board(board);
        update_board(board);
        usleep(100000); // delay for 0.1 seconds
    }
    return 0;
}