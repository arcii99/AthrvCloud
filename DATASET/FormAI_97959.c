//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 11 // odd number of rows
#define COLS 21 // odd number of cols

// direction macros
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// cell structure
struct Cell {
    int visited;
    int walls[4];
};

// function declarations
void initMaze(struct Cell maze[][COLS]);
void printMaze(struct Cell maze[][COLS]);
void generateMaze(struct Cell maze[][COLS], int row, int col);
int getValidNeighbor(struct Cell maze[][COLS], int row, int col);
void removeWall(struct Cell maze[][COLS], int row1, int col1, int row2, int col2);
int isOpen(struct Cell maze[][COLS], int row, int col, int direction);

int main() {
    srand(time(NULL)); // seed random number generator

    struct Cell maze[ROWS][COLS];
    initMaze(maze); // initialize maze with all walls up
    generateMaze(maze, 1, 1); // generate maze starting from cell (1,1)

    printMaze(maze); // print final maze

    return 0;
}

// initialize maze with all walls up
void initMaze(struct Cell maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j].visited = 0; // mark cell as unvisited
            maze[i][j].walls[UP] = 1;
            maze[i][j].walls[DOWN] = 1;
            maze[i][j].walls[LEFT] = 1;
            maze[i][j].walls[RIGHT] = 1;
        }
    }
}

// print maze
void printMaze(struct Cell maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // top wall
            printf("+");
            if (maze[i][j].walls[UP]) printf("--"); // wall up
            else printf("  "); // no wall up
        }
        printf("+\n");
        for (int j = 0; j < COLS; j++) {
            // left wall
            if (maze[i][j].walls[LEFT]) printf("|"); // wall left
            else printf(" "); // no wall left
            printf("  ");
            // right wall
            if (maze[i][j].walls[RIGHT]) printf("|"); // wall right
            else printf(" "); // no wall right
        }
        printf("\n");
    }
    for (int j = 0; j < COLS; j++) {
        // bottom wall
        printf("+--");
    }
    printf("+\n");
}

// generate maze with recursive backtracking algorithm
void generateMaze(struct Cell maze[][COLS], int row, int col) {
    maze[row][col].visited = 1; // mark current cell as visited

    while (1) {
        int neighbor = getValidNeighbor(maze, row, col); // get random valid neighbor

        if (neighbor == -1) return; // if no valid neighbor, return

        int neighbor_row = row, neighbor_col = col;

        switch (neighbor) {
            case UP:
                neighbor_row--;
                break;
            case DOWN:
                neighbor_row++;
                break;
            case LEFT:
                neighbor_col--;
                break;
            case RIGHT:
                neighbor_col++;
                break;
        }

        if (!maze[neighbor_row][neighbor_col].visited) { // if neighbor is unvisited
            removeWall(maze, row, col, neighbor_row, neighbor_col); // remove wall between current cell and neighbor
            generateMaze(maze, neighbor_row, neighbor_col); // recurse on neighbor cell
        }
    }
}

// get a random valid neighbor for cell at (row,col)
int getValidNeighbor(struct Cell maze[][COLS], int row, int col) {
    int neighbors[4] = {-1, -1, -1, -1}; // initialize all neighbors as invalid

    if (row > 1 && isOpen(maze, row, col, UP)) neighbors[UP] = UP;
    if (row < ROWS - 2 && isOpen(maze, row, col, DOWN)) neighbors[DOWN] = DOWN;
    if (col > 1 && isOpen(maze, row, col, LEFT)) neighbors[LEFT] = LEFT;
    if (col < COLS - 2 && isOpen(maze, row, col, RIGHT)) neighbors[RIGHT] = RIGHT;

    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (neighbors[i] != -1) count++;
    }

    if (count == 0) return -1; // if no valid neighbors, return -1

    int randNeighbor = rand() % count; // get a random neighbor

    for (int i = 0; i < 4; i++) {
        if (neighbors[i] != -1) {
            if (randNeighbor == 0) return neighbors[i];
            randNeighbor--;
        }
    }
    return -1;
}

// remove wall between cells (row1,col1) and (row2,col2)
void removeWall(struct Cell maze[][COLS], int row1, int col1, int row2, int col2) {
    if (row1 == row2) { // same row
        if (col1 < col2) { // cell on left
            maze[row1][col1].walls[RIGHT] = 0;
            maze[row2][col2].walls[LEFT] = 0;
        } else { // cell on right
            maze[row1][col1].walls[LEFT] = 0;
            maze[row2][col2].walls[RIGHT] = 0;
        }
    } else { // same column
        if (row1 < row2) { // cell above
            maze[row1][col1].walls[DOWN] = 0;
            maze[row2][col2].walls[UP] = 0;
        } else { // cell below
            maze[row1][col1].walls[UP] = 0;
            maze[row2][col2].walls[DOWN] = 0;
        }
    }
}

// check if there is no wall between cells at (row,col) and its neighbor in given direction
int isOpen(struct Cell maze[][COLS], int row, int col, int direction) {
    switch (direction) {
        case UP:
            return maze[row - 1][col].walls[DOWN] == 0;
        case DOWN:
            return maze[row + 1][col].walls[UP] == 0;
        case LEFT:
            return maze[row][col - 1].walls[RIGHT] == 0;
        case RIGHT:
            return maze[row][col + 1].walls[LEFT] == 0;
    }
    return 0;
}