//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int find_path(int row, int col)
{
    if(row == ROW-1 && col == COL-1)
    {
        maze[row][col] = 2;
        return 1;
    }
    
    if(maze[row][col] == 0)
    {
        maze[row][col] = 2;
        
        if(find_path(row+1, col))
            return 1;
        if(find_path(row-1, col))
            return 1;
        if(find_path(row, col+1))
            return 1;
        if(find_path(row, col-1))
            return 1;
        
        maze[row][col] = 0;
    }
    
    return 0;
}

int main()
{
    printf("Maze Before Finding the Path:\n");
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
    
    if(find_path(1, 1))
    {
        printf("\nMaze After Finding the Path:\n");
        for(int i=0; i<ROW; i++)
        {
            for(int j=0; j<COL; j++)
                printf("%d ", maze[i][j]);
            printf("\n");
        }
    }
    else
        printf("\nNo Path Found\n");
    
    return 0;
}