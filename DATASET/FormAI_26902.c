//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: scalable
#include <stdio.h>
#define ROW 10
#define COL 10

int grid[ROW][COL] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                       {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
                       {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
                       {0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
                       {0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
                       {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
                       {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

int visited[ROW][COL];
int path[ROW * COL];
int pathIndex = 0;

int is_valid(int row, int col)
{
    // Check if the row and column are within the bounds of the grid and if the cell is not blocked
    return ((row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (grid[row][col] == 1) && (visited[row][col] == 0));
}

int dfs(int row, int col)
{
    visited[row][col] = 1;
    if ((row == ROW - 1) && (col == COL - 1))
    {
        // Found the goal cell
        return 1;
    }
    if (is_valid(row + 1, col))
    {
        // Move down
        path[pathIndex++] = 1; // 1 denotes moving down
        if (dfs(row + 1, col))
        {
            return 1;
        }
        pathIndex--;
    }
    if (is_valid(row, col + 1))
    {
        // Move right
        path[pathIndex++] = 2; // 2 denotes moving right
        if (dfs(row, col + 1))
        {
            return 1;
        }
        pathIndex--;
    }
    if (is_valid(row - 1, col))
    {
        // Move up
        path[pathIndex++] = 3; // 3 denotes moving up
        if (dfs(row - 1, col))
        {
            return 1;
        }
        pathIndex--;
    }
    if (is_valid(row, col - 1))
    {
        // Move left
        path[pathIndex++] = 4; // 4 denotes moving left
        if (dfs(row, col - 1))
        {
            return 1;
        }
        pathIndex--;
    }
    return 0;
}

int main()
{
    int i, j;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            visited[i][j] = 0;
        }
    }
    if (dfs(0, 0))
    {
        printf("Path found:\n");
        for (i = 0; i < pathIndex; i++)
        {
            switch (path[i])
            {
                case 1:
                    printf("Down\n");
                    break;
                case 2:
                    printf("Right\n");
                    break;
                case 3:
                    printf("Up\n");
                    break;
                case 4:
                    printf("Left\n");
                    break;
            }
        }
    }
    else
    {
        printf("Path not found\n");
    }
    return 0;
}