//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20

char maze[MAX_ROWS][MAX_COLS];

void generateMaze(int startX, int startY) {
    int i, j, rnd;
    // Mark starting point as path
    maze[startX][startY] = ' ';
    // Generate random directions
    int directions[] = {-1, 0, 1, 0, -1};
    for (i = 0; i < 4; i++) {
        rnd = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[rnd];
        directions[rnd] = temp;
    }
    // Check each direction
    for (i = 0; i < 4; i++) {
        int dx = directions[i], dy = directions[i + 1];
        // Check if new position is valid
        if (startX + dx < 1 || startX + dx > MAX_ROWS - 2 || 
            startY + dy < 1 || startY + dy > MAX_COLS - 2 || 
            maze[startX + 2 * dx][startY + 2 * dy] != '#') 
        {
            continue;
        }
        // Mark as path
        maze[startX + dx][startY + dy] = ' ';
        maze[startX + 2 * dx][startY + 2 * dy] = ' ';
        generateMaze(startX + 2 * dx, startY + 2 * dy);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int i, j;
    // Initialize maze with walls
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (i == 0 || i == MAX_ROWS - 1 || j == 0 || j == MAX_COLS - 1) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = '.';
            }
        }
    }
    generateMaze(1, 1); // Start generating at top left corner
    // Print maze
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}