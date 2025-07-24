//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 7

int maze[ROWS][COLS] = {
    {1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 1}
};

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int findPath(int row, int col) {
    if (row == ROWS - 1 && col == COLS - 1) {
        return 1; // reached the end
    }
    if (maze[row][col] == 0) {
        return 0; // hit a wall
    }
    if (maze[row][col] == 2) {
        return 0; // already visited this spot
    }
    maze[row][col] = 2; // mark current spot as visited
    if (col < COLS - 1 && findPath(row, col + 1)) { // try right
        return 1;
    }
    if (row < ROWS - 1 && findPath(row + 1, col)) { // try down
        return 1;
    }
    if (col > 0 && findPath(row, col - 1)) { // try left
        return 1;
    }
    if (row > 0 && findPath(row - 1, col)) { // try up
        return 1;
    }
    return 0; // no path found
}

int main() {
    printf("Maze:\n");
    printMaze();
    if (findPath(0, 0)) {
        printf("Path found!\nMaze with path:\n");
        printMaze();
    } else {
        printf("No path found!\n");
    }
    return 0;
}