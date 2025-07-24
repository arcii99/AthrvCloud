//FormAI DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_MOVES 10

void printBoard(int board[][COLS]);
int validMove(int board[][COLS], int r1, int c1, int r2, int c2);
void swap(int board[][COLS], int r1, int c1, int r2, int c2);

int main() {
    int moves = 0;
    int board[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0}
    };

    srand(time(NULL));

    printf("Starting board:\n");
    printBoard(board);

    while (moves < MAX_MOVES) {
        int r1 = rand() % ROWS;
        int c1 = rand() % COLS;
        int r2 = rand() % ROWS;
        int c2 = rand() % COLS;
        
        if (validMove(board, r1, c1, r2, c2)) {
            swap(board, r1, c1, r2, c2);
            moves++;
            printf("Move #%d:\n", moves);
            printBoard(board);
        }
    }

    printf("Game over!\n");

    return 0;
}

void printBoard(int board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int validMove(int board[][COLS], int r1, int c1, int r2, int c2) {
    if (r1 < 0 || r1 >= ROWS) return 0;
    if (c1 < 0 || c1 >= COLS) return 0;
    if (r2 < 0 || r2 >= ROWS) return 0;
    if (c2 < 0 || c2 >= COLS) return 0;
    if (r1 == r2 && c1 == c2) return 0;

    int temp = board[r1][c1];
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = temp;

    // Check if board is in a valid state
    int expected = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0 && (i != ROWS-1 || j != COLS-1)) {
                return 0;
            }
            if (board[i][j] != expected % (ROWS*COLS)) {
                return 0;
            }
            expected++;
        }
    }

    return 1;
}

void swap(int board[][COLS], int r1, int c1, int r2, int c2) {
    int temp = board[r1][c1];
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = temp;
}