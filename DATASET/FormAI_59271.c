//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

// maze matrix
int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// function to print the maze
void printMaze()
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
}

// function to find a path through the maze
int findPath(int x, int y)
{
    // if we reach the exit, return true
    if (x == ROW - 1 && y == COL - 1) {
        maze[x][y] = 2;
        return 1;
    }

    // if current cell is blocked or already visited, return false
    if (maze[x][y] == 1 || maze[x][y] == 2)
        return 0;

    // mark current cell as visited
    maze[x][y] = 2;

    // explore all directions one by one
    if (findPath(x + 1, y) == 1) // go down
        return 1;
    if (findPath(x, y + 1) == 1) // go right
        return 1;
    if (findPath(x - 1, y) == 1) // go up
        return 1;
    if (findPath(x, y - 1) == 1) // go left
        return 1;

    // if no path is found, mark the cell as a dead end and return false
    maze[x][y] = 1;
    return 0;
}

// main function
int main()
{
    printf("Labryinth Maze Route Finder\n\n");

    // print initial maze
    printf("Initial maze:\n");
    printMaze();
    printf("\n");

    // find a path through the maze
    if (findPath(1, 0) == 1) {
        printf("Path found:\n");
        printMaze();
    } else {
        printf("No path found.\n");
    }

    return 0;
}