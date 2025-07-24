//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define WALL '*'
#define PATH ' '

char maze[SIZE][SIZE];
int visited[SIZE][SIZE];
int start_row, start_col, end_row, end_col;

void initialize() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (row == 0 || row == SIZE - 1 || col == 0 || col == SIZE - 1) {
                maze[row][col] = WALL;
            } else {
                maze[row][col] = PATH;
            }
            visited[row][col] = 0; // mark all cells as unvisited
        }
    }
    start_row = rand() % (SIZE - 2) + 1; // set random starting point
    start_col = rand() % (SIZE - 2) + 1;
    end_row = rand() % (SIZE - 2) + 1; // set random ending point
    end_col = rand() % (SIZE - 2) + 1;
    maze[start_row][start_col] = 'S';
    maze[end_row][end_col] = 'E';
}

void print_maze() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%c ", maze[row][col]);
        }
        printf("\n");
    }
}

int find_path(int row, int col) {
    if (row == end_row && col == end_col) { // base case: found the exit
        return 1;
    }
    visited[row][col] = 1; // mark current cell as visited
    if (maze[row+1][col] == PATH && !visited[row+1][col]) { // try going down
        if (find_path(row+1, col)) {
            maze[row+1][col] = '+';
            return 1;
        }
    }
    if (maze[row][col+1] == PATH && !visited[row][col+1]) { // try going right
        if (find_path(row, col+1)) {
            maze[row][col+1] = '+';
            return 1;
        }
    }
    if (maze[row-1][col] == PATH && !visited[row-1][col]) { // try going up
        if (find_path(row-1, col)) {
            maze[row-1][col] = '+';
            return 1;
        }
    }
    if (maze[row][col-1] == PATH && !visited[row][col-1]) { // try going left
        if (find_path(row, col-1)) {
            maze[row][col-1] = '+';
            return 1;
        }
    }
    return 0; // no path found
}

int main() {
    srand(time(NULL));
    initialize();
    printf("Maze Route Finder\n");
    printf("-----------------\n");
    printf("START: (%d,%d)\n", start_row, start_col);
    printf("END: (%d,%d)\n\n", end_row, end_col);
    printf("MAZE:\n");
    printf("-----------------\n");
    print_maze();
    printf("-----------------\n\n");

    if (find_path(start_row, start_col)) {
        maze[start_row][start_col] = 'S';
        printf("SOLUTION:\n");
        printf("-----------------\n");
        print_maze();
        printf("-----------------\n\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}