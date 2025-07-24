//FormAI DATASET v1.0 Category: Game of Life ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 80

int matrix[ROWS][COLS];

void initializeMatrix() {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(rand() % 2 == 0) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

void printMatrix() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(matrix[i][j] == 0) {
                printf(".");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int row, int col) {
    int count = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) {
                continue;
            }
            int r = row + i;
            int c = col + j;
            if(r < 0 || r >= ROWS || c < 0 || c >= COLS) {
                continue;
            }
            if(matrix[r][c] == 1) {
                count++;
            }
        }
    }
    return count;
}

void updateMatrix() {
    int nextMatrix[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(i, j);
            if(matrix[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) {
                    nextMatrix[i][j] = 0;
                } else {
                    nextMatrix[i][j] = 1;
                }
            } else {
                if(neighbors == 3) {
                    nextMatrix[i][j] = 1;
                } else {
                    nextMatrix[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            matrix[i][j] = nextMatrix[i][j];
        }
    }
}

int main() {
    initializeMatrix();
    while(1) {
        printMatrix();
        updateMatrix();
        // pause for a bit
        for(int i = 0; i < 10000000; i++) {
            // do nothing
        }
        // erase the console
        system("clear");
    }
    return 0;
}