//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 7

//Function to print maze
void print_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Function to check if the current position is valid and unvisited
int is_valid(char maze[ROWS][COLS], int row, int col, int visited[ROWS][COLS]) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }

    if (maze[row][col] == '#' || visited[row][col] == 1) {
        return 0;
    }

    return 1;
}

//Recursive function to find a path through the maze
int find_path(char maze[ROWS][COLS], int row, int col, int visited[ROWS][COLS]) {
    visited[row][col] = 1;

    if (maze[row][col] == '$') {
        return 1;
    }

    int next_row, next_col;

    //Move up
    next_row = row - 1;
    next_col = col;
    if (is_valid(maze, next_row, next_col, visited)) {
        if (find_path(maze, next_row, next_col, visited)) {
            visited[row][col] = 0;
            return 1;
        }
    }

    //Move right
    next_row = row;
    next_col = col + 1;
    if (is_valid(maze, next_row, next_col, visited)) {
        if (find_path(maze, next_row, next_col, visited)) {
            visited[row][col] = 0;
            return 1;
        }
    }

    //Move down
    next_row = row + 1;
    next_col = col;
    if (is_valid(maze, next_row, next_col, visited)) {
        if (find_path(maze, next_row, next_col, visited)) {
            visited[row][col] = 0;
            return 1;
        }
    }

    //Move left
    next_row = row;
    next_col = col - 1;
    if (is_valid(maze, next_row, next_col, visited)) {
        if (find_path(maze, next_row, next_col, visited)) {
            visited[row][col] = 0;
            return 1;
        }
    }

    visited[row][col] = 0;
    return 0;
}

int main() {
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '#', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '$', '#'}
    };

    int visited[ROWS][COLS] = {{0}};

    printf("Initial maze:\n");
    print_maze(maze);

    if (find_path(maze, 1, 1, visited) == 1) {
        printf("Path found!\n");
        print_maze(maze);
    } else {
        printf("Path not found!\n");
    }

    return 0;
}