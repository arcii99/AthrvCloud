//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

// Function to check if a cell is valid or not
bool isValid(int row, int col, bool visited[][COL], int maze[][COL]) {
    if (row < 0 || row >= ROW || col < 0 || col >= COL || !maze[row][col] || visited[row][col]) {
        return false;
    }
    return true;
}

// Function to print the path from source to destination
void printPath(int path[][2], int startIndex, int goalIndex) {
    printf("Found a path!\n");
    for (int i = startIndex; i <= goalIndex; i++) {
        printf("(%d, %d) ", path[i][0], path[i][1]);
    }
    printf("\n");
}

// Recursive function to find the path
bool findPath(int row, int col, int path[][2], int* index, bool visited[][COL], int maze[][COL], int goalRow, int goalCol) {         
    // Set the current cell as visited
    visited[row][col] = true;
    path[*index][0] = row;
    path[*index][1] = col;

    // If the current cell is the goal cell, print the path and return true
    if (row == goalRow && col == goalCol) {
        printPath(path, 0, *index);
        return true;
    }

    (*index)++;

    // Check if the cell to the right can be visited
    if (isValid(row, col + 1, visited, maze)) {
        if (findPath(row, col + 1, path, index, visited, maze, goalRow, goalCol)) {
            return true;
        }
    }

    // Check if the cell to the bottom can be visited
    if (isValid(row + 1, col, visited, maze)) {
        if (findPath(row + 1, col, path, index, visited, maze, goalRow, goalCol)) {
            return true;
        }
    }

    // Check if the cell to the left can be visited
    if (isValid(row, col - 1, visited, maze)) {
        if (findPath(row, col - 1, path, index, visited, maze, goalRow, goalCol)) {
            return true;
        }
    }

    // Check if the cell to the top can be visited
    if (isValid(row - 1, col, visited, maze)) {
        if (findPath(row - 1, col, path, index, visited, maze, goalRow, goalCol)) {
            return true;
        }
    }

    // If none of the adjacent cells lead to the goal, backtrack
    (*index)--;
    visited[row][col] = false;

    return false;
}

int main() {
    int maze[ROW][COL] = {
        {1, 0, 1, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1}
    };
    int path[ROW * COL][2];
    bool visited[ROW][COL];
    int startIndex = 0;
    int goalIndex = 0;

    // Initialize visited array to false
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }

    // Find the start and goal indices
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 1 && (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)) {
                if (startIndex == 0) {
                    startIndex = 1;
                    path[0][0] = i;
                    path[0][1] = j;
                } else {
                    goalIndex = 1;
                    path[1][0] = i;
                    path[1][1] = j;
                }
            }
        }
    }

    // If there is no path, print an error message
    if (!findPath(path[0][0], path[0][1], path, &startIndex, visited, maze, path[1][0], path[1][1])) {
        printf("No path found!\n");
    }

    return 0;
}