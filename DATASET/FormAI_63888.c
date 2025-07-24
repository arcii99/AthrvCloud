//FormAI DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 20

void printBoard(int arr[][COLS]) {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (arr[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int arr[][COLS], int row, int col) {
    int count = 0;
    for (int i=row-1; i<=row+1; i++) {
        for (int j=col-1; j<=col+1; j++) {
            int r = (i + ROWS) % ROWS;
            int c = (j + COLS) % COLS;
            if (arr[r][c] == 1) {
                count++;
            }
        }
    }
    return count;
}

void playGame(int arr[][COLS]) {
    int newArr[ROWS][COLS] = {0};
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            int neighbors = countNeighbors(arr, i, j);
            if (arr[i][j] == 0 && neighbors == 3) {
                newArr[i][j] = 1;
            } else if (arr[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                newArr[i][j] = 0;
            } else {
                newArr[i][j] = arr[i][j];
            }
        }
    }
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            arr[i][j] = newArr[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS] = {0};
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    while (1) {
        system ("clear");
        printBoard(board);
        playGame(board);
        usleep(500000);
    }
    return 0;
}