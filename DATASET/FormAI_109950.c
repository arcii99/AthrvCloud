//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define constants for the maze size
#define ROWS 9
#define COLS 10

// define constants for the different maze cells
#define WALL '#'
#define EMPTY ' '
#define START 'S'
#define END 'E'
#define PATH '*'

// define struct for the maze cell, with row, column, parent row, parent column, and cost to reach cell
struct Cell {
    int row;
    int col;
    int parentRow;
    int parentCol;
    int distance;
};

// define global variables for the start and end cell positions
int startRow, startCol, endRow, endCol;

// define the maze grid as a global variable
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'S', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
    {'#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', 'E', '#'}
};

// function to print the current state of the maze
void printMaze() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if a given cell is a valid path
bool isValid(int row, int col) {
    if (maze[row][col] == ' ' || maze[row][col] == 'E') {
        return true;
    } else {
        return false;
    }
}

// function to check if the given cell is the end cell
bool isEnd(int row, int col) {
    if (maze[row][col] == 'E') {
        return true;
    } else {
        return false;
    }
}

// function to add a cell to the open list
void addToOpen(struct Cell cells[], int *openLength, int row, int col, int parentRow, int parentCol, int distance) {
    cells[*openLength].row = row;
    cells[*openLength].col = col;
    cells[*openLength].parentRow = parentRow;
    cells[*openLength].parentCol = parentCol;
    cells[*openLength].distance = distance;
    (*openLength)++;
}

// function to get the cell with the lowest cost from the open list
struct Cell getLowestCost(struct Cell cells[], int openLength) {
    int minDistance = cells[0].distance;
    int minIndex = 0;
    for (int i = 1; i < openLength; i++) {
        if (cells[i].distance < minDistance) {
            minDistance = cells[i].distance;
            minIndex = i;
        }
    }
    return cells[minIndex];
}

// function to find the shortest path from the start cell to the end cell
void findPath() {
    // create the list of cells to be explored
    struct Cell openList[ROWS*COLS];
    int openLength = 0;
    
    // create the list of explored cells
    bool closedList[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            closedList[i][j] = false;
        }
    }
    
    // add the start cell to the open list
    addToOpen(openList, &openLength, startRow, startCol, -1, -1, 0);
    
    // loop until the end cell is found or the open list is empty
    while (openLength > 0) {
        // get the cell with the lowest cost from the open list
        struct Cell currentCell = getLowestCost(openList, openLength);
        openLength--;
        
        // mark the current cell as explored
        closedList[currentCell.row][currentCell.col] = true;
        
        // if the end cell has been found, backtrack to find the path
        if (isEnd(currentCell.row, currentCell.col)) {
            printf("Path found!\n");
            int pathLength = currentCell.distance;
            int pathRow = currentCell.row;
            int pathCol = currentCell.col;
            while (maze[pathRow][pathCol] != 'S') {
                maze[pathRow][pathCol] = PATH;
                int tempRow = pathRow;
                pathRow = openList[pathRow*COLS + pathCol].parentRow;
                pathCol = openList[tempRow*COLS + pathCol].parentCol;
            }
            maze[startRow][startCol] = START;
            printMaze();
            printf("Path length: %d\n", pathLength);
            return;
        }
        
        // add neighboring cells to the open list if they are valid paths
        if (currentCell.row > 0 && !closedList[currentCell.row-1][currentCell.col] && isValid(currentCell.row-1, currentCell.col)) {
            addToOpen(openList, &openLength, currentCell.row-1, currentCell.col, currentCell.row, currentCell.col, currentCell.distance+1);
        }
        if (currentCell.row < ROWS-1 && !closedList[currentCell.row+1][currentCell.col] && isValid(currentCell.row+1, currentCell.col)) {
            addToOpen(openList, &openLength, currentCell.row+1, currentCell.col, currentCell.row, currentCell.col, currentCell.distance+1);
        }
        if (currentCell.col > 0 && !closedList[currentCell.row][currentCell.col-1] && isValid(currentCell.row, currentCell.col-1)) {
            addToOpen(openList, &openLength, currentCell.row, currentCell.col-1, currentCell.row, currentCell.col, currentCell.distance+1);
        }
        if (currentCell.col < COLS-1 && !closedList[currentCell.row][currentCell.col+1] && isValid(currentCell.row, currentCell.col+1)) {
            addToOpen(openList, &openLength, currentCell.row, currentCell.col+1, currentCell.row, currentCell.col, currentCell.distance+1);
        }
    }
    
    // if the end cell was not found, print an error message
    printf("No path found.\n");
}

// main function
int main() {
    // find the start and end cell positions
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 'S') {
                startRow = i;
                startCol = j;
            }
            if (maze[i][j] == 'E') {
                endRow = i;
                endCol = j;
            }
        }
    }
    
    // print the initial maze
    printMaze();
    
    // find the shortest path from the start cell to the end cell
    findPath();
    
    return 0;
}