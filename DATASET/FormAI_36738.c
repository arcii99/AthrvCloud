//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h>
#define MAXROW 10
#define MAXCOL 10

int maze[MAXROW][MAXCOL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
}; // initialize the maze

int solve_maze(int row, int col)
{
    if(maze[row][col] == 2) return 1; // exit found
    if(maze[row][col] == 1) return 0; // path blocked

    maze[row][col] = 3; // mark as visited
    if(row < MAXROW - 1 && solve_maze(row+1, col)) return 1; // move down
    if(col > 0 && solve_maze(row, col-1)) return 1; // move left
    if(col < MAXCOL - 1 && solve_maze(row, col+1)) return 1; // move right
    if(row > 0 && solve_maze(row-1, col)) return 1; // move up

    maze[row][col] = 0; // unmark as visited
    return 0; // dead end
}

int main()
{
    int i, j;

    // print the maze
    printf("Original Maze:\n");
    for(i = 0; i < MAXROW; i++) {
        for(j = 0; j < MAXCOL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // solve the maze
    solve_maze(1, 1);

    // print the solved maze
    printf("Solved Maze:\n");
    for(i = 0; i < MAXROW; i++) {
        for(j = 0; j < MAXCOL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}