//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function to print the maze
void print_maze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if coordinates are valid
int valid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Function to find a path in the maze
int find_path(char maze[ROWS][COLS], int row, int col, int dest_x, int dest_y) {
    if (!valid(row, col)) {
        return 0;
    }
    if (maze[row][col] == '#') {
        return 0;
    }
    if (row == dest_x && col == dest_y) {
        return 1;
    }
    if (maze[row][col] == '.' || maze[row][col] == 'S') {
        maze[row][col] = '#';
        if (find_path(maze, row - 1, col, dest_x, dest_y)) {
            maze[row][col] = 'x';
            return 1;
        }
        if (find_path(maze, row, col + 1, dest_x, dest_y)) {
            maze[row][col] = 'x';
            return 1;
        }
        if (find_path(maze, row + 1, col, dest_x, dest_y)) {
            maze[row][col] = 'x';
            return 1;
        }
        if (find_path(maze, row, col - 1, dest_x, dest_y)) {
            maze[row][col] = 'x';
            return 1;
        }
        maze[row][col] = '.';
    }
    return 0;
}

int main() {
    char maze[ROWS][COLS] = {
        {'#','#','.','.','.','.','.','.','.','#'},
        {'#','.','.','#','#','#','.','#','.','#'},
        {'#','.','.','.','.','.','.','#','.','#'},
        {'#','#','#','#','#','.','#','#','.','#'},
        {'#','.','.','.','#','.','.','.','.','#'},
        {'#','.','#','#','#','.','#','#','.','#'},
        {'#','.','.','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','.','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','#','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    };

    int start_x = 0;
    int start_y = 2;
    int dest_x = 9;
    int dest_y = 7;

    printf("Original maze:\n");
    print_maze(maze);

    printf("\n");

    if (!find_path(maze, start_x, start_y, dest_x, dest_y)) {
        printf("No path found!\n");
    } else {
        printf("Path found:\n");
        print_maze(maze);
    }

    return 0;
}