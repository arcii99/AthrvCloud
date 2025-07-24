//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15 //number of rows in the maze
#define COLS 20 //number of columns in the maze
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

void print_maze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
    srand(time(NULL));
    int start_row = rand() % ROWS;
    int start_col = rand() % COLS;
    int end_row = rand() % ROWS;
    int end_col = rand() % COLS;
    maze[start_row][start_col] = START;
    maze[end_row][end_col] = END;
    for (i = 1; i < ROWS - 1; i++) {
        for (j = 1; j < COLS - 1; j++) {
            if (!(maze[i][j] == START || maze[i][j] == END)) { //do not build walls around the start and end points
                if (rand() % 10 < 8) { //80% chance to be a wall
                    maze[i][j] = WALL;
                }
                else { //20% chance to be a path
                    maze[i][j] = PATH;
                }
            }
        }
    }
}

void solve_maze(char maze[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return;
    }
    if (maze[row][col] == WALL) {
        return;
    }
    if (maze[row][col] == END) {
        maze[row][col] = 'X'; //replace with X to mark the solution path
        return;
    }
    maze[row][col] = 'X'; //replace with X to mark the solution path
    solve_maze(maze, row - 1, col); //north
    solve_maze(maze, row, col + 1); //east
    solve_maze(maze, row + 1, col); //south
    solve_maze(maze, row, col - 1); //west
}

int main() {
    char maze[ROWS][COLS];
    generate_maze(maze);
    printf("Generated maze:\n");
    print_maze(maze);
    solve_maze(maze, 0, 0); //start from top left corner
    printf("\nSolved maze:\n");
    print_maze(maze);
    return 0;
}