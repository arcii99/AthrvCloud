//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10
#define COLS 10

void print_maze(int maze[ROWS][COLS]); // forward declaration
void generate_maze(int maze[ROWS][COLS]); // forward declaration

int main(void) {
    int maze[ROWS][COLS];
    srand(time(NULL));
    generate_maze(maze);
    print_maze(maze);
    return 0;
}

void generate_maze(int maze[ROWS][COLS]) {
    // mark all cells as unvisited
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = 0;
        }
    }

    // generate maze starting point
    int x = rand() % ROWS;
    int y = rand() % COLS;
    maze[x][y] = 1; // mark starting point as visited

    // generate maze paths randomly using recursive backtracking algorithm
    int dx[4] = {1, 0, -1, 0}; // direction vectors
    int dy[4] = {0, 1, 0, -1};
    int dirs[4] = {0, 1, 2, 3}; // direction order
    for(int i = 0; i < 4; i++) { // shuffle direction order
        int j = rand() % 4;
        int temp = dirs[i];
        dirs[i] = dirs[j];
        dirs[j] = temp;
    }
    for(int i = 0; i < 4; i++) { // explore all directions randomly
        int nx = x + dx[dirs[i]];
        int ny = y + dy[dirs[i]];
        if(nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && maze[nx][ny] == 0) { // check valid cell
            maze[nx][ny] = 1; // mark cell as visited
            maze[x + dx[dirs[i]]/2][y + dy[dirs[i]]/2] = 1; // mark path as visited
            x = nx; // move to next cell
            y = ny;
            generate_maze(maze); // recur on next cell
        }
    }
}

void print_maze(int maze[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 1) {
                printf("  ");
            }
            else {
                printf("\u2588\u2588"); // print block character for walls
            }
        }
        printf("\n");
    }
}