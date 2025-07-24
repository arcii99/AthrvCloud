//FormAI DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20
#define COLS 40

// Function to print the matrix
void printMatrix(int matrix[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(matrix[i][j] == 1) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to calculate the next generation
void nextGeneration(int matrix[ROWS][COLS]) {
    int i, j, k, l;
    int count; // counter for the number of neighbors
    int tempMatrix[ROWS][COLS];
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            count = 0;
            for(k = -1; k <= 1; k++) {
                for(l = -1; l <= 1; l++) {
                    if(i + k >= 0 && i + k < ROWS && j + l >= 0 && j + l < COLS) {
                        if(matrix[i + k][j + l] == 1) {
                            count++;
                        }
                    }
                }
            }
            count -= matrix[i][j];
            if(matrix[i][j] == 1 && (count < 2 || count > 3)) {
                tempMatrix[i][j] = 0;
            } else if(matrix[i][j] == 0 && count == 3) {
                tempMatrix[i][j] = 1;
            } else {
                tempMatrix[i][j] = matrix[i][j];
            }
        }
    }
    // Copy temporary matrix to original matrix
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            matrix[i][j] = tempMatrix[i][j];
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int matrix[ROWS][COLS];
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
    printMatrix(matrix);
    printf("======================\n");
    // Now let's do some shape shifting!
    int steps = 10;
    int step;
    for(step = 0; step < steps; step++) {
        nextGeneration(matrix);
        if(step % 2 == 0) { // Make a square
            int side = rand() % 10 + 5;
            int centerRow = rand() % (ROWS - (side + 2)) + (side + 1);
            int centerCol = rand() % (COLS - (side + 2)) + (side + 1);
            for(i = centerRow - side/2; i < centerRow + side/2; i++) {
                for(j = centerCol - side/2; j < centerCol + side/2; j++) {
                    matrix[i][j] = 1;
                }
            }
        } else { // Make a triangle
            int base = rand() % 10 + 5;
            int height = rand() % 8 + 3;
            int orientation = rand() % 2;
            int centerRow = rand() % (ROWS - (height + 2)) + (height + 1);
            int centerCol = rand() % (COLS - (base + 2)) + (base + 1);
            if(orientation == 0) { // Pointing up
                for(i = centerRow - height/2; i < centerRow + height/2; i++) {
                    int left = centerCol - (i - centerRow)*base/height;
                    int right = centerCol + (i - centerRow)*base/height;
                    for(j = left; j <= right; j++) {
                        matrix[i][j] = 1;
                    }
                }
            } else { // Pointing down
                for(i = centerRow + height/2; i > centerRow - height/2; i--) {
                    int left = centerCol - (centerRow - i)*base/height;
                    int right = centerCol + (centerRow - i)*base/height;
                    for(j = left; j <= right; j++) {
                        matrix[i][j] = 1;
                    }
                }
            }
        }
        printMatrix(matrix);
        printf("======================\n");
    }
    return 0;
}