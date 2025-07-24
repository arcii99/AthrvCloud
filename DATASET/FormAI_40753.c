//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11

int maze[HEIGHT][WIDTH];

void initMaze() {
    // Initialize maze with walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }
}

void printMaze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf((maze[i][j] == 1) ? "X " : "  ");
        }
        printf("\n");
    }
}

void generateMaze(int row, int col) {
    int directions[4][2] = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};
    int randDir;
    int newRow, newCol;

    // Randomize directions
    for (int i = 0; i < 4; i++) {
        randDir = rand() % 4;
        int tempRow = directions[i][0];
        int tempCol = directions[i][1];
        directions[i][0] = directions[randDir][0];
        directions[i][1] = directions[randDir][1];
        directions[randDir][0] = tempRow;
        directions[randDir][1] = tempCol;
    }

    maze[row][col] = 2; // Mark current cell as visited

    // Visit neighboring cells
    for (int i = 0; i < 4; i++) {
        newRow = row + directions[i][0];
        newCol = col + directions[i][1];

        if (newRow >= 0 && newRow < HEIGHT && newCol >= 0 && newCol < WIDTH) { // Check if new cell within boundaries
            if (maze[newRow][newCol] == 0) { // Check if new cell not visited
                maze[(row + newRow) / 2][(col + newCol) / 2] = 2; // Mark wall between current and new cell as visited
                generateMaze(newRow, newCol); // Recursively visit new cell
            }
        }
    }
}

int main() {
    srand(time(NULL));
    initMaze();
    generateMaze(1, 1); // Start generating maze from cell (1, 1)
    printMaze();
    return 0;
}