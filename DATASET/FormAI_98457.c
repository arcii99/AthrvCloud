//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

// Initialize the maze
int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 1, 1}
};

// Function to print the maze
void printMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 1)
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to find the route
void findRoute(int x, int y, int a, int b) {
    if (x == a && y == b) {
        printf("-> (%d,%d) ", x, y);
        exit(0);
    }
    if (maze[x][y] == 0) {
        printf("-> (%d,%d) ", x, y);
        maze[x][y] = 2;
        if (x < a && maze[x+1][y] != 2)
            findRoute(x+1, y, a, b);
        if (y < b && maze[x][y+1] != 2)
            findRoute(x, y+1, a, b);
        if (x > 0 && maze[x-1][y] != 2)
            findRoute(x-1, y, a, b);
        if (y > 0 && maze[x][y-1] != 2)
            findRoute(x, y-1, a, b);
    }
}

int main() {
    printf("Maze:\n");
    printMaze();
    printf("Starting point: (1,1)\n");
    printf("Ending point: (8,8)\n");
    printf("Solution for the Maze:\n");
    findRoute(1, 1, 8, 8);
    printf("\n");
    return 0;
}