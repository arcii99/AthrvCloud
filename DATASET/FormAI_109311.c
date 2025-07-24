//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int start_x = 1, start_y = 1;
int end_x = 8, end_y = 8;
int path_found = 0;

void print_maze(void) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void find_path(int x, int y) {
    if (x == end_x && y == end_y) {
        path_found = 1;
        return;
    }

    maze[x][y] = 2;

    if (maze[x][y+1] == 0) {
        find_path(x, y+1);
    }

    if (maze[x+1][y] == 0) {
        find_path(x+1, y);
    }

    if (maze[x][y-1] == 0) {
        find_path(x, y-1);
    }

    if (maze[x-1][y] == 0) {
        find_path(x-1, y);
    }

    if (path_found) {
        maze[start_x][start_y] = 2;
        return;
    }

    maze[x][y] = 0;
}

int main(void) {
    print_maze();

    find_path(start_x, start_y);
    if (path_found) {
        printf("\n");
        print_maze();
    } else {
        printf("\nPath not found.\n");
    }

    return 0;
}