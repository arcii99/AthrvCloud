//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void generateMaze(int maze[SIZE][SIZE]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == 0 || j == 0 || i == SIZE - 1 || j == SIZE - 1) {
                maze[i][j] = 1;
            } else if (i % 2 == 0 && j % 2 == 0) {
                maze[i][j] = 0;
            } else {
                maze[i][j] = rand() % 2;
            }
        }
    }
}

void printMaze(int maze[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (maze[i][j] == 1) {
                printf("██");
            } else if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("??");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[SIZE][SIZE];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}