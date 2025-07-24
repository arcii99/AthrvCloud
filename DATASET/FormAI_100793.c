//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COLUMN 10

char maze[ROW][COLUMN] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#'},
    {'#', '#', ' ', '#', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', ' ', '#', '#'},
    {'#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', '#'},
    {'#', '#', ' ', ' ', ' ', '#', ' ', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#', '#', '#', 'E', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

bool isValidMove(int row, int col, bool visited[ROW][COLUMN])
{
    // Check if the move is inside the maze and the cell is not already visited
    return (row >= 0 && row < ROW) && (col >= 0 && col < COLUMN) && (maze[row][col] != '#') && !visited[row][col];
}

bool findPath(int row, int col, bool visited[ROW][COLUMN])
{
    // Mark the current cell as visited
    visited[row][col] = true;

    // Check if we have reached the end of the maze
    if (maze[row][col] == 'E') {
        return true;
    }

    // Check for all valid moves
    if (isValidMove(row + 1, col, visited) && findPath(row + 1, col, visited)) { // Move down
        return true;
    }
    if (isValidMove(row, col + 1, visited) && findPath(row, col + 1, visited)) { // Move right
        return true;
    }
    if (isValidMove(row - 1, col, visited) && findPath(row - 1, col, visited)) { // Move up
        return true;
    }
    if (isValidMove(row, col - 1, visited) && findPath(row, col - 1, visited)) { // Move left
        return true;
    }

    // If no valid moves found, backtrack
    visited[row][col] = false;
    return false;
}

int main()
{
    int startRow = 1, startCol = 1;
    bool visited[ROW][COLUMN] = { false };

    // Find the path from the starting point (marked 'S') to the end point (marked 'E')
    if (findPath(startRow, startCol, visited)) {
        // Print the final maze with the path marked as '.'
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COLUMN; j++) {
                if (maze[i][j] == ' ') {
                    printf(".");
                }
                else {
                    printf("%c", maze[i][j]);
                }
            }
            printf("\n");
        }
    }
    else {
        printf("No path found\n");
    }

    return 0;
}