//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int isWall;
} Cell;

void generateMaze(Cell maze[ROWS][COLS], int startX, int startY);

int main() {
    Cell maze[ROWS][COLS];
    int startX = 0, startY = 0;

    // initialize maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j].isWall = 1; // fill maze with walls
        }
    }

    // generate maze
    generateMaze(maze, startX, startY);

    // print maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j].isWall) {
                printf("#"); // print wall
            } else {
                printf(" "); // print path
            }
        }
        printf("\n");
    }

    return 0;
}

void generateMaze(Cell maze[ROWS][COLS], int startX, int startY) {
    srand(time(NULL)); // seed random number generator

    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // available directions
    int visitedCount = 1; // number of cells visited
    int totalCells = ROWS * COLS; // total number of cells
    int currentX = startX, currentY = startY; // current cell
    int nextX, nextY; // next cell
    int direction; // chosen direction
    int random; // random number

    maze[currentY][currentX].isWall = 0; // mark starting cell as path

    while (visitedCount < totalCells) {
        // check available directions
        int availableDirections[4] = {0, 0, 0, 0};
        int count = 0;
        for (int i = 0; i < 4; i++) {
            nextX = currentX + directions[i][0];
            nextY = currentY + directions[i][1];
            if (nextX >= 0 && nextX < COLS && nextY >= 0 && nextY < ROWS && maze[nextY][nextX].isWall) {
                availableDirections[i] = 1;
                count++;
            }
        }

        if (count > 0) {
            // choose a random available direction
            random = rand() % count;
            count = 0;
            for (int i = 0; i < 4; i++) {
                if (availableDirections[i]) {
                    if (count == random) {
                        direction = i;
                        break;
                    } else {
                        count++;
                    }
                }
            }

            // move to next cell
            currentX += directions[direction][0];
            currentY += directions[direction][1];

            // mark new cell as path
            maze[currentY][currentX].isWall = 0;

            // increment visited count
            visitedCount++;
        } else {
            // backtrack to previous cell
            for (int i = 0; i < 4; i++) {
                nextX = currentX + directions[i][0];
                nextY = currentY + directions[i][1];
                if (nextX >= 0 && nextX < COLS && nextY >= 0 && nextY < ROWS && !maze[nextY][nextX].isWall) {
                    currentX = nextX;
                    currentY = nextY;
                    break;
                }
            }
        }
    }
}