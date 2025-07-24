//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: single-threaded
#include <stdio.h>

#define ROW 10
#define COL 10

// Function to check if cell is valid or not
int isValidCell(int row, int col, int maze[][COL], int visited[][COL]) {
    // Checking if cell is within maze and not a wall and is not visited
    if(row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1 && visited[row][col] == 0)
        return 1;

    return 0;
}

// Function to print the solution path
void printSolutionPath(int path[][COL], int row, int col) {
    printf("\n\nSolution Path:\n");
    for(int i=0; i<=row; i++) {
        for(int j=0; j<=col; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

// Function to find the path to reach the destination
int findPath(int row, int col, int destRow, int destCol, int maze[][COL], int visited[][COL], int path[][COL], int count) {
    // Checking if destination is reached
    if(row == destRow && col == destCol) {
        path[row][col] = 1;
        printSolutionPath(path, destRow, destCol);
        return 1;
    }

    if(isValidCell(row, col, maze, visited)) {
        visited[row][col] = 1; // Marking cell as visited
        path[row][col] = count++; // Adding it to the path

        // Checking for all possible movements
        if(findPath(row+1, col, destRow, destCol, maze, visited, path, count) == 1)
            return 1;

        if(findPath(row, col+1, destRow, destCol, maze, visited, path, count) == 1)
            return 1;

        if(findPath(row-1, col, destRow, destCol, maze, visited, path, count) == 1)
            return 1;

        if(findPath(row, col-1, destRow, destCol, maze, visited, path, count) == 1)
            return 1;

        path[row][col] = 0; // Backtracking
    }

    return 0;
}

int main() {
    int maze[ROW][COL] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1, 1, 0, 0, 1, 1},
        {0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0, 1, 1}
    };

    int visited[ROW][COL] = {0};
    int path[ROW][COL] = {0};

    int srcRow = 0, srcCol = 0, destRow = ROW-1, destCol = COL-1;

    if(findPath(srcRow, srcCol, destRow, destCol, maze, visited, path, 1) == 0) {
        printf("\nNo Path Found!");
    }

    return 0;
}