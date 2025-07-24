//FormAI DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 40

// function to print the matrix
void printMatrix(int mat[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", mat[i][j] ? 'X' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

// function to count the number of live neighbours
int numLiveNeighbors(int mat[ROW][COL], int row, int col) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int rowIdx = row + i;
            int colIdx = col + j;

            if (rowIdx < ROW && rowIdx > -1 && colIdx < COL && colIdx > -1) {
                if (i || j) {
                    count += mat[rowIdx][colIdx];
                }
            }
        }
    }

    return count;
}

// function to update the matrix
void updateMatrix(int mat[ROW][COL]) {
    int newMat[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int liveNeighbors = numLiveNeighbors(mat, i, j);

            if (mat[i][j]) {
                newMat[i][j] = (liveNeighbors == 2 || liveNeighbors == 3);
            } else {
                newMat[i][j] = (liveNeighbors == 3);
            }
        }
    }

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            mat[i][j] = newMat[i][j];
        }
    }
}

int main() {
    int mat[ROW][COL] = { 0 };

    srand(time(0));

    int numGenerations = 100;
    int numShapes = 4;

    // set up the initial shape
    int startX = rand() % (ROW - 10);
    int startY = rand() % (COL - 10);

    for (int i = startX; i < startX + 10; i++) {
        for (int j = startY; j < startY + 10; j++) {
            mat[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < numGenerations; i++) {
        printf("Generation: %d\n", i);
        printMatrix(mat);

        // randomly shift the shape
        int deltaRow = rand() % 3 - 1;
        int deltaCol = rand() % 3 - 1;

        startX += deltaRow;
        startY += deltaCol;

        if (startX < 0) startX = 0;
        if (startY < 0) startY = 0;
        if (startX > ROW - 10) startX = ROW - 10;
        if (startY > COL - 10) startY = COL - 10;

        for (int j = startY; j < startY + 10; j++) {
            mat[startX][j] = rand() % 2;
        }

        updateMatrix(mat);
    }

    return 0;
}