//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define constants for maze size
#define ROWS 7
#define COLS 9

// define constants for maze symbols
#define WALL '#'
#define EMPTY ' '
#define PATH '.'

// define struct for maze
typedef struct {
    char grid[ROWS][COLS];
    int startRow;
    int startCol;
    int endRow;
    int endCol;
} Maze;

// function prototypes
void readMaze(FILE* filePointer, Maze* maze);
void printMaze(Maze maze);
bool findPath(Maze* maze, int row, int col);

// main function
int main() {
    FILE* filePointer;
    Maze maze;
    int row, col;

    // open file containing maze
    filePointer = fopen("maze.txt", "r");
    if (filePointer == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    // read maze from file
    readMaze(filePointer, &maze);

    // close file
    fclose(filePointer);

    // print maze
    printf("Maze:\n");
    printMaze(maze);

    // find path through maze
    if (findPath(&maze, maze.startRow, maze.startCol)) {
        printf("Solution:\n");
        printMaze(maze);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

// function to read maze from file
void readMaze(FILE* filePointer, Maze* maze) {
    char ch;
    int row, col;

    // set all cells in maze to empty
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            maze->grid[row][col] = EMPTY;
        }
    }

    // read maze from file
    row = 0;
    col = 0;
    while ((ch = fgetc(filePointer)) != EOF) {
        if (ch == '\n') {
            row++;
            col = 0;
        } else {
            maze->grid[row][col] = ch;
            if (ch == 'S') {
                maze->startRow = row;
                maze->startCol = col;
            } else if (ch == 'E') {
                maze->endRow = row;
                maze->endCol = col;
            }
            col++;
        }
    }
}

// function to print maze
void printMaze(Maze maze) {
    int row, col;

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%c", maze.grid[row][col]);
        }
        printf("\n");
    }

    printf("\n");
}

// function to find path through maze
bool findPath(Maze* maze, int row, int col) {
    // mark current cell as on path
    maze->grid[row][col] = PATH;

    // check if current cell is end cell
    if (row == maze->endRow && col == maze->endCol) {
        return true;
    }

    // check if can move up
    if (row > 0 && maze->grid[row - 1][col] != WALL && maze->grid[row - 1][col] != PATH) {
        if (findPath(maze, row - 1, col)) {
            return true;
        }
    }

    // check if can move down
    if (row < ROWS - 1 && maze->grid[row + 1][col] != WALL && maze->grid[row + 1][col] != PATH) {
        if (findPath(maze, row + 1, col)) {
            return true;
        }
    }

    // check if can move left
    if (col > 0 && maze->grid[row][col - 1] != WALL && maze->grid[row][col - 1] != PATH) {
        if (findPath(maze, row, col - 1)) {
            return true;
        }
    }

    // check if can move right
    if (col < COLS - 1 && maze->grid[row][col + 1] != WALL && maze->grid[row][col + 1] != PATH) {
        if (findPath(maze, row, col + 1)) {
            return true;
        }
    }

    // mark current cell as not on path
    maze->grid[row][col] = EMPTY;

    return false;
}