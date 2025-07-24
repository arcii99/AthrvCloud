//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>

#define ROW 10
#define COL 10

void generateMaze(int maze[ROW][COL])
{
    // generate maze randomly
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if( i==0 || j==0 || i==ROW-1 || j==COL-1 )
            {
                maze[i][j] = -1;
            }
            else
            {
                maze[i][j] = rand()%2;
            }
        }
    }
}

void printMaze(int maze[ROW][COL])
{
    printf("Maze:\n");
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(maze[i][j] == -1)
            {
                printf("# ");
            }
            else if(maze[i][j] == 1)
            {
                printf("  ");
            }
            else if(maze[i][j] == 0)
            {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void findRoute(int maze[ROW][COL], int row, int col, int endRow, int endCol)
{
    if(row==endRow && col==endCol)
    {
        // destination reached
        maze[row][col] = 2;
        return;
    }
    if(maze[row][col] == -1 || maze[row][col] == 2)
    {
        // this cell is blocked or already visited
        return;
    }
    // mark current cell as visited
    maze[row][col] = 2;
    // try all possible paths
    findRoute(maze, row+1, col, endRow, endCol); // down
    findRoute(maze, row, col+1, endRow, endCol); // right
    findRoute(maze, row-1, col, endRow, endCol); // up
    findRoute(maze, row, col-1, endRow, endCol); // left
    // mark current cell as visited
    maze[row][col] = 1;
}

int main()
{
    int maze[ROW][COL];
    int startRow = 1, startCol = 1;
    int endRow = ROW-2, endCol = COL-2;
    generateMaze(maze);
    printMaze(maze);
    printf("Finding route from (%d, %d) to (%d, %d)...\n", startRow, startCol, endRow, endCol);
    findRoute(maze, startRow, startCol, endRow, endCol);
    printf("Route found!\n");
    printMaze(maze);
    return 0;
}