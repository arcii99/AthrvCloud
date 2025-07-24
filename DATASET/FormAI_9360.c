//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(int maze[ROWS][COLS]) {
    int i, j;
    // Initialize maze with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }
    // Set starting and ending points
    maze[0][0] = 0;
    maze[ROWS-1][COLS-1] = 0;
    
    srand(time(NULL)); // Seed random number generator
    int row = 1, col = 1;
    maze[row][col] = 0; // Set starting position to open space
    
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right
    int numDirections = 4;
    while (numDirections > 0) {
        int r = rand() % numDirections;
        int dirRow = directions[r][0];
        int dirCol = directions[r][1];
        int neighborRow = row + 2 * dirRow;
        int neighborCol = col + 2 * dirCol;
        if (neighborRow > 0 && neighborRow < ROWS-1 && neighborCol > 0 && neighborCol < COLS-1 && maze[neighborRow][neighborCol] == 1) {
            // Clear path to neighbor
            maze[row+dirRow][col+dirCol] = 0;
            maze[neighborRow][neighborCol] = 0;
            // Move to neighbor
            row = neighborRow;
            col = neighborCol;
            // Reset directions array and increment open space count
            numDirections = 4;
            continue;
        }
        // Remove direction from directions array
        directions[r][0] = directions[numDirections-1][0];
        directions[r][1] = directions[numDirections-1][1];
        numDirections--;
    }
}

void printMaze(int maze[ROWS][COLS]) {
    int i, j;
    printf(" ");
    for (j = 0; j < COLS; j++) {
        printf("_ ");
    }
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("__");
            }
            if (j == COLS-1) {
                printf("|");
            } else if (maze[i][j] == 0 && maze[i][j+1] == 0) {
                printf(" ");
            } else {
                printf("_");
            }
        }
        printf("\n");
    }
}

int main() {
    int maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}