//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int maze[10][10] = {
    { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    { 1, 0, 1, 1, 1, 0, 1, 0, 1, 0},
    { 1, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    { 1, 0, 1, 1, 1, 1, 1, 0, 1, 0},
    { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 0},
    { 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Function to check if the cell is valid for traversal
int isSafe(int x, int y)
{
    if (x >= 0 && x < 10 && y >= 0 && y < 10 && maze[x][y] == 1)
        return 1;
    return 0;
}

// Recursive function to find the path from start to end
int findPath(int x, int y)
{
    if (x == 9 && y == 9)
    {
        maze[x][y] = 4; // Marks the end point
        return 1;
    }

    if (isSafe(x, y))
    {
        maze[x][y] = 3; // Marks the path being taken
        if (findPath(x + 1, y))
            return 1;
        if (findPath(x, y + 1))
            return 1;
        if (findPath(x - 1, y))
            return 1;
        if (findPath(x, y - 1))
            return 1;
        maze[x][y] = 1; // Marks the path as not being taken
    }
    return 0;
}

int main()
{
    printf("Welcome to the Maze Route Finder!\n\n");
    printf("You find yourself at the starting point of a maze.\n");
    printf("Your goal is to make it to the other end without getting lost.\n");
    printf("The maze is represented by a 10x10 grid of cells. You are currently at (0, 0).\n");
    printf("The numbers in the grid indicate the type of cell:\n");
    printf("0 = Wall\n");
    printf("1 = Path\n");
    printf("2 = Start\n");
    printf("3 = Path being taken\n");
    printf("4 = End\n\n");
    printf("Press enter to begin.\n");

    getchar();

    system("clear");

    maze[0][0] = 2; // Marks the starting point

    if (findPath(0, 0))
    {
        printf("Congratulations! You have successfully navigated the maze.\n\n");
    }
    else
    {
        printf("Unfortunately, you got lost in the maze.\n\n");
    }

    // Prints the final maze
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    printf("\nPress enter to exit.\n");

    getchar();

    return 0;
}