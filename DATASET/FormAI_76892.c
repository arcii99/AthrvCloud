//FormAI DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#define ROWS 10
#define COLS 10

int getCurrentState(int arr[][COLS], int row, int col) {
    return arr[row][col];
}

int getNeighbourState(int arr[][COLS], int row, int col) {
    int count = 0;

    // check upper row neighbours
    if (row > 0) {
        if (arr[row-1][col] == 1)
            count++;
        if (col > 0 && arr[row-1][col-1] == 1)
            count++;
        if (col < COLS-2 && arr[row-1][col+1] == 1)
            count++;
    }

    // check left and right neighbours
    if (col > 0 && arr[row][col-1] == 1)
        count++;
    if (col < COLS-2 && arr[row][col+1] == 1)
        count++;

    // check bottom row neighbours
    if (row < ROWS-2) {
        if (arr[row+1][col] == 1)
            count++;
        if (col > 0 && arr[row+1][col-1] == 1)
            count++;
        if (col < COLS-2 && arr[row+1][col+1] == 1)
            count++;
    }

    return count;
}

void printArray(int arr[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[ROWS][COLS] = {0};
    int nextStateArr[ROWS][COLS] = {0};
    int generationCount = 0;

    // initialize the array with random values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 2;
        }
    }

    printf("\nGeneration 0\n");
    printArray(arr);

    // simulate generations
    while (generationCount < 10) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int currentState = getCurrentState(arr, i, j);
                int neighbourState = getNeighbourState(arr, i, j);

                if (currentState == 0 && neighbourState == 3) {
                    nextStateArr[i][j] = 1;
                }
                else if (currentState == 1 && (neighbourState == 2 || neighbourState == 3)) {
                    nextStateArr[i][j] = 1;
                }
                else {
                    nextStateArr[i][j] = 0;
                }
            }
        }

        // update the array with the next state
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                arr[i][j] = nextStateArr[i][j];
            }
        }

        printf("\nGeneration %d\n", ++generationCount);
        printArray(arr);
    }

    return 0;
}