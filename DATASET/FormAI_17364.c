//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int maze[ROW][COL]; // array to represent the maze
int visited[ROW][COL]; // array to keep track of visited cells
int start_row, start_col; // start position of the maze
int end_row, end_col; // end position of the maze
int direction_row[] = {0, 1, 0, -1}; // array to represent the possible row shifts
int direction_col[] = {1, 0, -1, 0}; // array to represent the possible column shifts

// function to initialize the maze
void initializeMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            maze[i][j] = rand() % 2; // randomly generate 0's and 1's to represent the walls
            visited[i][j] = 0; // set all cells as unvisited initially
        }
    }
    start_row = rand() % ROW; // randomly select the start position
    start_col = rand() % COL;
    end_row = rand() % ROW; // randomly select the end position
    end_col = rand() % COL;
    maze[start_row][start_col] = 0; // mark the start and end positions as not a wall
    maze[end_row][end_col] = 0;
}

// function to print the maze
void printMaze() {
    printf("Maze:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf("  "); // cell is not a wall
            } else {
                printf("█ "); // cell is a wall
            }
        }
        printf("\n");
    }
}

// function to check if a cell is within the maze boundaries
int isWithinBound(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

// function to check if a cell is not a wall and has not been visited
int isNotAWallAndNotVisited(int row, int col) {
    return (maze[row][col] == 0 && visited[row][col] == 0);
}

// recursive function to find a path from the start to the end
int findPath(int row, int col) {
    visited[row][col] = 1; // mark the current cell as visited

    if (row == end_row && col == end_col) { // base case: we have reached the end position
        return 1;
    }

    // check all possible directions
    for (int i = 0; i < 4; i++) {
        int next_row = row + direction_row[i];
        int next_col = col + direction_col[i];
        if (isWithinBound(next_row, next_col) && isNotAWallAndNotVisited(next_row, next_col)) {
            if (findPath(next_row, next_col)) { // recursively try to find the end position
                return 1; // we have found a path, return 1 to signal success
            }
        }
    }

    visited[row][col] = 0; // we have not found a path from this cell, mark it as unvisited

    return 0; // we have not found a path from this cell, return 0 to signal failure
}

int main() {
    srand(time(NULL)); // seed the random number generator

    printf("Welcome to the Maze Route Finder program!\n");

    initializeMaze(); // initialize the maze
    printMaze(); // print the initial maze

    if (findPath(start_row, start_col)) { // try to find a path from the start to the end
        printf("A path from (%d,%d) to (%d,%d) has been found.\n", start_row, start_col, end_row, end_col);
    } else {
        printf("A path from (%d,%d) to (%d,%d) could not be found.\n", start_row, start_col, end_row, end_col);
    }

    return 0;
}