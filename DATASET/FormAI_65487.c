//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

// function to check if a cell is valid
int is_valid(int row, int col, int maze[][COL]) {
    // check if row and col are within the maze
    if (row < 0 || col < 0 || row >= ROW || col >= COL) {
        return 0;
    }
    // check if cell is open
    else if (maze[row][col] == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// function to print the maze
void print_maze(int maze[][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// recursive function to find a path through the maze
int find_path(int row, int col, int maze[][COL], int path[][COL]) {
    // check if current cell is valid and not already part of the path
    if (is_valid(row, col, maze) && path[row][col] == 0) {
        // mark current cell as part of the path
        path[row][col] = 1;
        // check if current cell is the end of the maze
        if (row == ROW - 1 && col == COL - 1) {
            return 1;
        }
        // explore neighboring cells
        else if (find_path(row + 1, col, maze, path) ||
                 find_path(row - 1, col, maze, path) ||
                 find_path(row, col + 1, maze, path) ||
                 find_path(row, col - 1, maze, path)) {
            return 1;
        }
        // backtrack if no neighboring cells lead to the end
        else {
            path[row][col] = 0;
            return 0;
        }
    }
    else {
        return 0;
    }
}

int main() {
    // initialize the maze
    int maze[ROW][COL] = {
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0}
    };
    // initialize the path
    int path[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    // print the initial maze
    printf("Initial Maze:\n");
    print_maze(maze);
    // find a path through the maze
    if (find_path(0, 0, maze, path)) {
        printf("\nPath Found:\n");
        print_maze(path);
    }
    else {
        printf("\nNo Path Found\n");
    }
    return 0;
}