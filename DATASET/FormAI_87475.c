//FormAI DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int countNeighbors(int arr[][COLS], int x, int y) {
    int count = 0;
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0)
                continue;
            if (x + i < 0 || x + i >= ROWS || y + j < 0 || y + j >= COLS)
                continue;
            if (arr[x + i][y + j] == 1)
                count++;
        }
    }
    return count;
}

void initializeBoard(int arr[][COLS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 2;
        }
    }
}

void printBoard(int arr[][COLS]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (arr[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void playGameOfLife(int arr[][COLS]) {
    int tempArr[ROWS][COLS];
    int i, j, count;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            count = countNeighbors(arr, i, j);
            if (arr[i][j] == 1) {
                if (count < 2 || count > 3)
                    tempArr[i][j] = 0;
                else
                    tempArr[i][j] = 1;
            }
            else {
                if (count == 3)
                    tempArr[i][j] = 1;
                else
                    tempArr[i][j] = 0;
            }
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = tempArr[i][j];
        }
    }
}

int main() {
    int gameBoard[ROWS][COLS];
    initializeBoard(gameBoard);
    for (int i = 0; i < 100; i++) {
        system("cls");  // Clear the console screen on each iteration
        printf("Iteration %d\n", i);
        printBoard(gameBoard);
        playGameOfLife(gameBoard);
    }
    return 0;
}