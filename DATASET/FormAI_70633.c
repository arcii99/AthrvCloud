//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25

typedef struct cell {
    int row, col;
    int walls[4]; // top, right, bottom, left
    int visited;
} cell;

void init_maze(cell maze[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j].row = i;
            maze[i][j].col = j;
            maze[i][j].visited = 0;
            maze[i][j].walls[0] = 1; // top
            maze[i][j].walls[1] = 1; // right
            maze[i][j].walls[2] = 1; // bottom
            maze[i][j].walls[3] = 1; // left
        }
    }
}

void print_maze(cell maze[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j].walls[0]) {
                printf("+---");
            } else {
                printf("+   ");
            }
        }
        printf("+\n");
        for (j = 0; j < COLS; j++) {
            if (maze[i][j].walls[3]) {
                printf("|   ");
            } else {
                printf("    ");
            }
        }
        printf("|\n");
    }
    for (j = 0; j < COLS; j++) {
        printf("+---");
    }
    printf("+\n");
}

void generate_maze(cell maze[][COLS], int row, int col) {
    maze[row][col].visited = 1;
    while (1) {
        int unvisited_neighbors = 0;
        int neighbors[4] = {-1, -1, -1, -1}; // top, right, bottom, left
        if (row > 0 && !maze[row-1][col].visited) {
            neighbors[0] = 0;
            unvisited_neighbors++;
        }
        if (col < COLS-1 && !maze[row][col+1].visited) {
            neighbors[1] = 1;
            unvisited_neighbors++;
        }
        if (row < ROWS-1 && !maze[row+1][col].visited) {
            neighbors[2] = 2;
            unvisited_neighbors++;
        }
        if (col > 0 && !maze[row][col-1].visited) {
            neighbors[3] = 3;
            unvisited_neighbors++;
        }
        if (unvisited_neighbors == 0) {
            return;
        }
        int next = neighbors[rand() % 4];
        int next_row = row, next_col = col;
        switch (next) {
            case 0: // top
                next_row--;
                maze[row][col].walls[0] = 0;
                maze[next_row][col].walls[2] = 0;
                break;
            case 1: // right
                next_col++;
                maze[row][col].walls[1] = 0;
                maze[row][next_col].walls[3] = 0;
                break;
            case 2: // bottom
                next_row++;
                maze[row][col].walls[2] = 0;
                maze[next_row][col].walls[0] = 0;
                break;
            case 3: // left
                next_col--;
                maze[row][col].walls[3] = 0;
                maze[row][next_col].walls[1] = 0;
                break;
        }
        generate_maze(maze, next_row, next_col);
    }
}

int main() {
    srand(time(NULL));
    cell maze[ROWS][COLS];
    init_maze(maze);
    generate_maze(maze, 0, 0);
    print_maze(maze);
    return 0;
}