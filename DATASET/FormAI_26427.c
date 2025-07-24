//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 25
#define COL 25

int mazeWalls[ROW][COL];

void printMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (mazeWalls[i][j] == 1) {
                printf("█");
            } else if (i == 0 && j == 1) {
                printf("S"); // Start
            } else if (i == ROW - 1 && j == COL - 2) {
                printf("E"); // End
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generateMaze() {
    srand(time(0));

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            mazeWalls[i][j] = 1;
        }
    }

    for (int i = 2; i < ROW - 2; i += 2) {
        for (int j = 2; j < COL - 2; j += 2) {
            mazeWalls[i][j] = 0;

            if (i == 2) {
                mazeWalls[i - 1][j] = 0;
            }

            if (j == 2) {
                mazeWalls[i][j - 1] = 0;
            }

            if (i == ROW - 3) {
                mazeWalls[i + 1][j] = 0;
            }

            if (j == COL - 3) {
                mazeWalls[i][j + 1] = 0;
            }

            int rnd = rand() % 4;

            switch (rnd) {
                case 0:
                    mazeWalls[i - 1][j] = 0;
                    break;
                case 1:
                    mazeWalls[i][j + 1] = 0;
                    break;
                case 2:
                    mazeWalls[i + 1][j] = 0;
                    break;
                case 3:
                    mazeWalls[i][j - 1] = 0;
                    break;
            }
        }
    }
}

int main() {
    generateMaze();
    printMaze();
    return 0;
}