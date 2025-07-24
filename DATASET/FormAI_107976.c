//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#define ROW 10
#define COL 10

// Function to print the maze
void print_maze(int maze[][COL], int n, int m)
{
    printf("\n"); // print a new line for aesthetics
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            printf("%d ", maze[i][j]); // print the element in the maze
        printf("\n"); // print a new line for each row
    }
}

// Function to check if the path is valid
int is_valid(int maze[][COL], int x, int y, int n, int m)
{
    if (x>=0 && x<n && y>=0 && y<m && maze[x][y]==1)
        return 1;
    return 0;
}

// Function to find the path
int find_path(int maze[][COL], int x, int y, int n, int m)
{
    if (x==n-1 && y==m-1) // we have reached the end
    {
        maze[x][y] = 2; // mark the end
        return 1;
    }
    if (is_valid(maze, x, y, n, m))
    {
        maze[x][y] = 2; // mark the path we have taken
        if (find_path(maze, x+1, y, n, m)==1) // go down
            return 1;
        if (find_path(maze, x, y+1, n, m)==1) // go right
            return 1;
        maze[x][y] = 1; // mark the path as unexplored
        return 0;
    }
    return 0;
}

int main()
{
    int maze[ROW][COL] = {{1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                          {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
                          {1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
                          {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
                          {1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
                          {1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                          {1, 0, 1, 1, 1, 1, 1, 1, 0, 0},
                          {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}; // define the maze

    printf("The maze is:\n");
    print_maze(maze, ROW, COL); // print the maze


    printf("\nFinding the path in the maze...\n");

    if (find_path(maze, 0, 0, ROW, COL)) // if a path is found, print it
        print_maze(maze, ROW, COL);
    else // if no path is found, print a message
        printf("No path found in the maze.\n");

    return 0; // exit the program
}