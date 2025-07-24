//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

// initializing the maze with '.' (dots) representing empty paths
char maze[ROW][COL] = 

{
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '.', '#', '#', '#', '.', '#', '#', '.'},
    {'.', '#', '.', '.', '.', '#', '.', '.', '.', '.'},
    {'.', '#', '.', '#', '.', '.', '.', '#', '#', '.'},
    {'.', '#', '.', '#', '#', '.', '#', '#', '.', '.'},
    {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
    {'.', '#', '.', '.', '.', '.', '#', '.', '#', '.'},
    {'.', '#', '.', '#', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '.', '.', '.', '#', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '#', '.', '#', '.', '.'},
};

// output function to display the maze
void print_maze()
{
    for (int i=0; i<ROW; i++)
    {
        for (int j=0; j<COL; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// recursive function to find the exit
int find_exit(int row, int col)
{
    // if we have reached the end of the maze
    if (row == ROW-1 && col == COL-1)
    {
        maze[row][col] = '*';
        return 1;
    }
    
    // if we are still in the maze
    if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == '.')
    {
        // mark the path with a '-'
        maze[row][col] = '-';
        
        // check the four neighbours for an exit
        if (find_exit(row+1, col) || find_exit(row, col+1) || find_exit(row-1, col) || find_exit(row, col-1))
        {
            // if an exit is found, mark it with an '*'
            maze[row][col] = '*';
            return 1;
        }
    }
    
    return 0;
}

int main()
{
    printf("MAZE ROUTE FINDER PROGRAM\n");
    
    printf("\nOriginal Maze\n");
    print_maze();
    
    // starting from the top left corner of the maze
    if (find_exit(0, 0))
    {
        printf("\nExit Found!\n");
        print_maze();
    }
    else
    {
        printf("\nNo Exit Found!\n");
    }
    
    return 0;
}