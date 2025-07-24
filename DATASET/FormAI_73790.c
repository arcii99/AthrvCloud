//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

void generateMaze(int maze[ROWS][COLS], int row, int col);
void printMaze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];

    // Initialize maze with all 1's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // Set seed for rand()
    srand(time(NULL));

    // Generate maze starting from (0, 0)
    generateMaze(maze, 0, 0);

    // Print the final maze
    printMaze(maze);

    return 0;
}

void generateMaze(int maze[ROWS][COLS], int row, int col) {
    // Mark current cell as visited
    maze[row][col] = 0;

    // Generate random directions
    int directions[4] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        int randomIndex = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[randomIndex];
        directions[randomIndex] = temp;
    }

    // Recursively generate maze in each direction
    for (int i = 0; i < 4; i++) {
        int rowOffset = 0;
        int colOffset = 0;

        if (directions[i] == 1 && row > 0) { // Up
            rowOffset = -1;
        } else if (directions[i] == 2 && col < COLS - 1) { // Right
            colOffset = 1;
        } else if (directions[i] == 3 && row < ROWS - 1) { // Down
            rowOffset = 1;
        } else if (directions[i] == 4 && col > 0) { // Left
            colOffset = -1;
        }

        int newRow = row + rowOffset;
        int newCol = col + colOffset;

        if (maze[newRow][newCol]) { // If unvisited cell
            // Remove wall between current cell and new cell
            if (rowOffset == -1) { // Up
                maze[row][col] &= ~1;
                maze[newRow][newCol] &= ~4;
            } else if (colOffset == 1) { // Right
                maze[row][col] &= ~2;
                maze[newRow][newCol] &= ~8;
            } else if (rowOffset == 1) { // Down
                maze[row][col] &= ~4;
                maze[newRow][newCol] &= ~1;
            } else if (colOffset == -1) { // Left
                maze[row][col] &= ~8;
                maze[newRow][newCol] &= ~2;
            }

            // Recursively generate maze from new cell
            generateMaze(maze, newRow, newCol);
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    // Print top wall
    for (int i = 0; i < COLS; i++) {
        printf("_");
    }
    printf("\n");

    // Print maze cells
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] & 1) { // Left wall
                printf("_");
            } else {
                printf(" ");
            }

            if (maze[i][j] & 2) { // Top wall
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}