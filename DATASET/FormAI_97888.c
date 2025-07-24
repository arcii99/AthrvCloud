//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 20
#define MAX_COLS 20

char maze[MAX_ROWS][MAX_COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

const int ROWS = 9, COLS = 10;
int startRow, startCol, endRow, endCol;

bool findPath(int row, int col);
void printPath();

int main() {
    printf("Maze Route Finder Program\n");
    
    // Find start and end positions
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (maze[i][j] == 'S') {
                startRow = i;
                startCol = j;
            } else if (maze[i][j] == 'E') {
                endRow = i;
                endCol = j;
            }
        }
    }
    
    // Find path
    if (findPath(startRow, startCol)) {
        printf("\nPath found!\n");
        printPath();
    } else {
        printf("\nPath not found.\n");
    }
    
    return 0;
}

bool findPath(int row, int col) {
    // Base cases
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false; // out of bounds
    }
    if (maze[row][col] == '#') {
        return false; // hit a wall
    }
    if (maze[row][col] == 'X') {
        return false; // already visited
    }
    if (maze[row][col] == 'E') {
        return true; // found the end
    }
    
    // Mark as visited
    maze[row][col] = 'X';
    
    // Recurse in all directions
    if (findPath(row-1, col)) { // up
        return true;
    }
    if (findPath(row+1, col)) { // down
        return true;
    }
    if (findPath(row, col-1)) { // left
        return true;
    }
    if (findPath(row, col+1)) { // right
        return true;
    }
    
    // Unmark if no path found
    maze[row][col] = ' ';
    
    return false;
}

void printPath() {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (maze[i][j] == 'X') {
                printf(".");
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
}