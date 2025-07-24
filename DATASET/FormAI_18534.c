//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS];

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generateMaze(int row, int col) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int randDir[4] = {0, 1, 2, 3};
    int temp;

    for (int i = 0; i < 4; i++) {
        int random = rand() % 4;
        temp = randDir[random];
        randDir[random] = randDir[i];
        randDir[i] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int nextRow = row + directions[randDir[i]][0] * 2;
        int nextCol = col + directions[randDir[i]][1] * 2;

        if (nextRow < 0 || nextCol < 0 || nextRow >= ROWS || nextCol >= COLS) {
            continue;
        }

        if (maze[nextRow][nextCol] == 0) {
            maze[nextRow - directions[randDir[i]][0]][nextCol - directions[randDir[i]][1]] = 1;
            maze[nextRow][nextCol] = 1;

            generateMaze(nextRow, nextCol);
        }
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1) {
                maze[i][j] = 0;
            } else {
                maze[i][j] = 1;
            }
        }
    }

    generateMaze(1, 1);
    printMaze();
    
    return 0;
}