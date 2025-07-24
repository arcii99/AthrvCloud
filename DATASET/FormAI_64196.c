//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include <stdio.h>

// function to check if a position is valid or not
int isValidPosition(int maze[][4], int row, int col) {
    if (row >= 0 && row < 4 && col >= 0 && col < 4 && maze[row][col] == 1) {
        return 1;
    }
    return 0;
}

// function to print the path
void printPath(int path[][2], int pathLength) {
    printf("\nThe path to the exit is: ");
    for (int i = 0; i < pathLength; i++) {
        printf("(%d, %d) ", path[i][0], path[i][1]);
    }
    printf("\n");
}

// recursive function to find the path of maze
int findPathRecursively(int maze[][4], int row, int col, int path[][2], int pathLength) {
    // if we found the exit
    if (row == 3 && col == 3) {
        path[pathLength][0] = row;
        path[pathLength][1] = col;
        printPath(path, pathLength + 1);
        return 1;
    }
    // check the four adjacent cells
    if (isValidPosition(maze, row + 1, col)) {
        path[pathLength][0] = row;
        path[pathLength][1] = col;
        int result = findPathRecursively(maze, row + 1, col, path, pathLength + 1);
        if (result) {
            return 1;
        }
    }
    if (isValidPosition(maze, row, col + 1)) {
        path[pathLength][0] = row;
        path[pathLength][1] = col;
        int result = findPathRecursively(maze, row, col + 1, path, pathLength + 1);
        if (result) {
            return 1;
        }
    }
    if (isValidPosition(maze, row - 1, col)) {
        path[pathLength][0] = row;
        path[pathLength][1] = col;
        int result = findPathRecursively(maze, row - 1, col, path, pathLength + 1);
        if (result) {
            return 1;
        }
    }
    if (isValidPosition(maze, row, col - 1)) {
        path[pathLength][0] = row;
        path[pathLength][1] = col;
        int result = findPathRecursively(maze, row, col - 1, path, pathLength + 1);
        if (result) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // define the maze
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    // define the path array
    int path[16][2];
    // call the recursive function to find the path
    int result = findPathRecursively(maze, 0, 0, path, 0);
    if (!result) {
        printf("\nThere is no path to the exit.");
    }
    return 0;
}