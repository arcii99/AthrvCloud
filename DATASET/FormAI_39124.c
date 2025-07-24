//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 20

void print_maze(int maze[ROWS][COLS], int row_size, int col_size) {
    for(int i=0; i<row_size; i++) {
        for(int j=0; j<col_size; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int find_path(int maze[ROWS][COLS], int row_size, int col_size, int row, int col) {
    // Check if current position is valid
    if(row<0 || col<0 || row>=row_size || col>=col_size) return 0;
    if(maze[row][col] == 1) return 0;
    if(row==row_size-1 && col==col_size-1) {
        maze[row][col] = 2;
        return 1;
    }

    maze[row][col] = 1;

    // Recursively search in all directions
    if(find_path(maze, row_size, col_size, row-1, col)) {
        maze[row][col] = 2;
        return 1;
    }
    if(find_path(maze, row_size, col_size, row+1, col)) {
        maze[row][col] = 2;
        return 1;
    }
    if(find_path(maze, row_size, col_size, row, col-1)) {
        maze[row][col] = 2;
        return 1;
    }
    if(find_path(maze, row_size, col_size, row, col+1)) {
        maze[row][col] = 2;
        return 1;
    }

    maze[row][col] = 0;
    return 0;
}

int main() {
    int maze[ROWS][COLS];
    int row_size = ROWS;
    int col_size = COLS;

    // Initialize maze with random obstacles
    srand(time(NULL));
    for(int i=0; i<row_size; i++) {
        for(int j=0; j<col_size; j++) {
            if(rand()%100 < 30) maze[i][j] = 1;
            else maze[i][j] = 0;
        }
    }

    printf("Initial Maze:\n");
    print_maze(maze, row_size, col_size);

    // Find path through maze
    if(find_path(maze, row_size, col_size, 0, 0)) {
        printf("Path found!\n");
        print_maze(maze, row_size, col_size);
    }
    else {
        printf("Path not found!\n");
    }

    return 0;
}