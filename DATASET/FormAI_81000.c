//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>

#define ROWS 10
#define COLS 10

// Function to print the maze
void print_maze(int maze[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a point is valid in the maze
int is_valid_point(int maze[][COLS], int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return 0;
    }
    if (maze[x][y] == 1) {
        return 0;
    }
    return 1;
}

// Function to find the route through the maze
int find_maze_route(int maze[][COLS], int x, int y) {
    if (x == ROWS - 1 && y == COLS - 1) {
        maze[x][y] = 2;
        return 1;
    }
    if (is_valid_point(maze, x, y)) {
        maze[x][y] = 2;
        if (find_maze_route(maze, x + 1, y)) {
            return 1;
        }
        if (find_maze_route(maze, x, y + 1)) {
            return 1;
        }
        if (find_maze_route(maze, x - 1, y)) {
            return 1;
        }
        if (find_maze_route(maze, x, y - 1)) {
            return 1;
        }
        maze[x][y] = 0;
    }
    return 0;
}

int main() {
    int maze[ROWS][COLS] = {
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 1, 1, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 1, 1},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    };
    printf("Original maze:\n");
    print_maze(maze);
    printf("\n");
    if (find_maze_route(maze, 0, 0)) {
        printf("Found route through maze:\n");
        print_maze(maze);
    } else {
        printf("No route found through maze.\n");
    }
    return 0;
}