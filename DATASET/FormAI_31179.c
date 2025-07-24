//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define ROW 7
#define COL 10

char maze[ROW][COL] = {
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
  {'.', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
  {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#'},
  {'#', '.', '.', '.', '.', '#', '#', '.', '.', '.'},
  {'#', '#', '#', '#', '.', '#', '#', '#', '#', '#'},
  {'#', '.', '.', '#', '.', '.', '.', '.', '#', '#'}
};

int visited[ROW][COL] = {0};

// Recursive backtracking function
int findPath(int row, int col)
{
    if (row < 0 || row >= ROW || col < 0 || col >= COL)
    {
        return 0; // Out of bounds
    }

    if (visited[row][col] || maze[row][col] == '#')
    {
        return 0; // Already visited or wall
    }

    if (row == ROW - 1 && col == COL - 1)
    {
        printf("Found path!\n"); // Base case
        return 1;
    }

    visited[row][col] = 1; // Mark visited

    // Try to move in all directions
    int foundPath = 0;
    foundPath |= findPath(row + 1, col);
    foundPath |= findPath(row - 1, col);
    foundPath |= findPath(row, col + 1);
    foundPath |= findPath(row, col - 1);

    if (foundPath)
    {
        printf("(%d, %d) ", row, col);
    }

    return foundPath;
}

int main()
{
    printf("Starting maze:\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%c", maze[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    if (!findPath(0, 0))
    {
        printf("No path found.\n");
    }
}