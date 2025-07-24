//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// function to print the maze
void print_maze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// function to check if given position is valid or not
int is_valid(int maze[][COLS], int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == 0) {
        return 0;
    }
    return 1;
}

// recursive function to find the path
int find_path(int maze[][COLS], int x, int y, int path[][2], int path_index) {
    if (x == ROWS - 1 && y == COLS - 1) {
        path[path_index][0] = x;
        path[path_index][1] = y;
        return 1;
    }

    if (is_valid(maze, x, y)) {
        path[path_index][0] = x;
        path[path_index][1] = y;
        if (find_path(maze, x + 1, y, path, path_index + 1)) {
            return 1;
        }
        if (find_path(maze, x, y + 1, path, path_index + 1)) {
            return 1;
        }
        if (find_path(maze, x - 1, y, path, path_index + 1)) {
            return 1;
        }
        if (find_path(maze, x, y - 1, path, path_index + 1)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int maze[ROWS][COLS] = {
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    
    int path[ROWS*COLS][2];
    int path_found = find_path(maze, 0, 0, path, 0);

    if (path_found) {
        printf("Path Found: ");
        for (int i = 0; i <= ROWS*COLS; i++) {
            printf("(%d,%d) ", path[i][0], path[i][1]);
        }
        printf("\n\n");
        print_maze(maze);
    } else {
        printf("No Path Found in the Maze!\n");
    }

    return 0;
}