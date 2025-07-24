//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25
#define WALL '+'
#define PATH ' '
#define START 'S'
#define END 'E'

void generateMaze(char maze[][COLS]);
void printMaze(char maze[][COLS]);
void fill(char maze[][COLS], int row, int col);
int checkValid(int row, int col);
int checkNeighbor(char maze[][COLS], int row, int col);

int main() {
    char maze[ROWS][COLS];
    srand(time(NULL));
    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(char maze[][COLS]) {
    int i, j;
    //fill the maze with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
    //create starting and ending points
    int start_row = rand() % ROWS;
    int start_col = 0;
    int end_row = rand() % ROWS;
    int end_col = COLS - 1;

    maze[start_row][start_col] = START;
    maze[end_row][end_col] = END;
    //fill the maze with paths
    fill(maze, start_row, start_col);
}

void fill(char maze[][COLS], int row, int col) {
    int i, direction;
    int directions[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};

    for (i = 0; i < 4; i++) {
        //generate random directions
        direction = rand() % 4;
        if (checkValid(row + directions[direction][0], col + directions[direction][1]) && 
            checkNeighbor(maze, row + directions[direction][0], col + directions[direction][1])) {
            //if the cell is valid and has not been visited, fill it with path
            maze[row + directions[direction][0]][col + directions[direction][1]] = PATH;
            fill(maze, row + directions[direction][0], col + directions[direction][1]);
        }
    }
}

int checkValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

int checkNeighbor(char maze[][COLS], int row, int col) {
    if (checkValid(row, col)) {
        int count = 0;
        //count the number of neighbors that have already been visited
        if (maze[row][col] == PATH) {
            return 0;
        }
        if (checkValid(row + 1, col) && maze[row + 1][col] == PATH) { count++; }
        if (checkValid(row - 1, col) && maze[row - 1][col] == PATH) { count++; }
        if (checkValid(row, col + 1) && maze[row][col + 1] == PATH) { count++; }
        if (checkValid(row, col - 1) && maze[row][col - 1] == PATH) { count++; }
        return count == 1;
    }
    return 0;
}

void printMaze(char maze[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}