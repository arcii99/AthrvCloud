//FormAI DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

bool matrix[WIDTH][HEIGHT];
bool nextMatrix[WIDTH][HEIGHT];
int neighbors[WIDTH][HEIGHT];

void populateMatrix() {
    srand(time(NULL));

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            matrix[i][j] = (rand() % 2) == 1 ? true : false;
        }
    }
}

int countNeighbors(int i, int j) {
    int count = 0;

    if (i > 0) {
        count += matrix[i-1][j];
        if (j > 0) {
            count += matrix[i-1][j-1];
        }
        if (j < HEIGHT-1) {
            count += matrix[i-1][j+1];
        }
    }

    if (i < WIDTH-1) {
        count += matrix[i+1][j];
        if (j > 0) {
            count += matrix[i+1][j-1];
        }
        if (j < HEIGHT-1) {
            count += matrix[i+1][j+1];
        }
    }

    if (j > 0) {
        count += matrix[i][j-1];
    }

    if (j < HEIGHT-1) {
        count += matrix[i][j+1];
    }

    return count;
}

void update() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            neighbors[i][j] = countNeighbors(i, j);
        }
    }

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (matrix[i][j]) {
                if (neighbors[i][j] < 2 || neighbors[i][j] > 3) {
                    nextMatrix[i][j] = false;
                } else {
                    nextMatrix[i][j] = true;
                }
            } else {
                if (neighbors[i][j] == 3) {
                    nextMatrix[i][j] = true;
                } else {
                    nextMatrix[i][j] = false;
                }
            }
        }
    }

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            matrix[i][j] = nextMatrix[i][j];
        }
    }
}

void printMatrix() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf(matrix[i][j] ? "#" : " ");
        }
        printf("\n");
    }
}

int main() {
    populateMatrix();

    while (true) {
        system("cls");
        printMatrix();
        update();
    }

    return 0;
}