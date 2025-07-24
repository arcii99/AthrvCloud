//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

typedef struct {
    int x;
    int y;
} Cell;

int main() {
    srand(time(NULL));

    // Initialize maze
    int maze[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // Set starting cell
    Cell currentCell = {rand() % ROWS, rand() % COLS};
    maze[currentCell.x][currentCell.y] = 0;

    // Generate maze
    int visitedCount = 1;
    while (visitedCount < ROWS * COLS) {
        // Find neighbors
        Cell neighbors[4];
        int neighborCount = 0;
        if (currentCell.x > 0 && maze[currentCell.x-1][currentCell.y] == 1) {
            neighbors[neighborCount++] = (Cell){currentCell.x-1, currentCell.y};
        }
        if (currentCell.y > 0 && maze[currentCell.x][currentCell.y-1] == 1) {
            neighbors[neighborCount++] = (Cell){currentCell.x, currentCell.y-1};
        }
        if (currentCell.x < ROWS-1 && maze[currentCell.x+1][currentCell.y] == 1) {
            neighbors[neighborCount++] = (Cell){currentCell.x+1, currentCell.y};
        }
        if (currentCell.y < COLS-1 && maze[currentCell.x][currentCell.y+1] == 1) {
            neighbors[neighborCount++] = (Cell){currentCell.x, currentCell.y+1};
        }

        // Choose random neighbor
        if (neighborCount > 0) {
            int neighborIndex = rand() % neighborCount;
            Cell neighbor = neighbors[neighborIndex];

            // Knock down wall
            if (neighbor.x < currentCell.x) {
                maze[currentCell.x-1][currentCell.y] = 0;
            }
            else if (neighbor.x > currentCell.x) {
                maze[currentCell.x+1][currentCell.y] = 0;
            }
            else if (neighbor.y < currentCell.y) {
                maze[currentCell.x][currentCell.y-1] = 0;
            }
            else if (neighbor.y > currentCell.y) {
                maze[currentCell.x][currentCell.y+1] = 0;
            }

            // Move to neighbor
            currentCell = neighbor;
            maze[currentCell.x][currentCell.y] = 0;
            visitedCount++;
        }
        else {
            // Backtrack
            int backtrackFound = 0;
            while (!backtrackFound) {
                // Randomly choose previous cell
                int prevX = rand() % ROWS;
                int prevY = rand() % COLS;

                if (maze[prevX][prevY] == 0) {
                    // Remove wall
                    if (prevX < currentCell.x) {
                        maze[currentCell.x-1][currentCell.y] = 0;
                    }
                    else if (prevX > currentCell.x) {
                        maze[currentCell.x+1][currentCell.y] = 0;
                    }
                    else if (prevY < currentCell.y) {
                        maze[currentCell.x][currentCell.y-1] = 0;
                    }
                    else if (prevY > currentCell.y) {
                        maze[currentCell.x][currentCell.y+1] = 0;
                    }

                    // Move to previous cell
                    currentCell = (Cell){prevX, prevY};
                    visitedCount++;
                    backtrackFound = 1;
                }
            }
        }
    }

    // Print maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("# ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }

    return 0;
}