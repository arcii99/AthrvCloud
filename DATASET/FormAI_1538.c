//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool sol_found = false;

void print_maze(int curr_x, int curr_y) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == curr_x && j == curr_y) {
                printf("2 ");
            } else {
                printf("%d ", maze[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void find_path(int curr_x, int curr_y) {
    if (curr_x == ROW - 1 && curr_y == COL - 1) {
        sol_found = true;
        print_maze(curr_x, curr_y);
        return;
    }

    if (curr_x < ROW - 1 && maze[curr_x + 1][curr_y] == 0) {
        maze[curr_x + 1][curr_y] = 2;
        print_maze(curr_x + 1, curr_y);
        find_path(curr_x + 1, curr_y);
        if (!sol_found) {
            maze[curr_x + 1][curr_y] = 0;
        }
    }

    if (curr_y < COL - 1 && maze[curr_x][curr_y + 1] == 0) {
        maze[curr_x][curr_y + 1] = 2;
        print_maze(curr_x, curr_y + 1);
        find_path(curr_x, curr_y + 1);
        if (!sol_found) {
            maze[curr_x][curr_y + 1] = 0;
        }
    }
}

int main() {
    maze[0][0] = 2;
    print_maze(0, 0);
    find_path(0, 0);

    if (!sol_found) {
        printf("No solution found\n");
    }

    return 0;
}