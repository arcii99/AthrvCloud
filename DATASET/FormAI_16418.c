//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#define ROWS 5
#define COLS 5

void printMaze(char maze[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        printf("%s\n", maze[i]);
    }
}

void findRoute(char maze[][COLS], int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        // out of bounds
        return;
    }

    if (maze[x][y] == 'G') {
        // found the goal!
        maze[x][y] = 'X'; // mark the goal cell as part of the path
        printMaze(maze, ROWS);
        return;
    }

    if (maze[x][y] == '#' || maze[x][y] == 'X') {
        // wall or already visited cell
        return;
    }

    // mark current cell as part of the path
    maze[x][y] = 'X';

    // try all possible directions
    findRoute(maze, x-1, y); // up
    findRoute(maze, x+1, y); // down
    findRoute(maze, x, y-1); // left
    findRoute(maze, x, y+1); // right

    // backtrack
    maze[x][y] = '.';
}

int main() {
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#'},
        {'.', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '#'},
        {'#', '#', '#', 'G', '#'}
    };

    printf("Original maze:\n");
    printMaze(maze, ROWS);

    printf("\nFinding route...\n");
    findRoute(maze, 1, 0);

    return 0;
}