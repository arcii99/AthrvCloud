//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 9
#define COL 10

// Struct to represent a point in the maze
typedef struct point
{
    int x, y;
} point;

// Maze matrix
char maze[ROW][COL] =
    {
        "+---------+",
        "|         |",
        "| +-------+",
        "| |       |",
        "| | +---+ |",
        "| | |   | |",
        "| | |   | |",
        "| | |   | |",
        "| +-+   | |",
        "+-------- +"};

// Function to check if a given point is valid or not
bool is_valid_point(int x, int y)
{
    // Check if the point is inside the maze bounds and is not an obstacle
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] != '+')
        return true;

    return false;
}

// Function to check if the destination has been reached
bool is_destination(int x, int y, point dest)
{
    if (x == dest.x && y == dest.y)
        return true;
    else
        return false;
}

// Function to print the maze
void print_maze()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to perform depth first search to find the path to destination
bool dfs(point current, point dest)
{
    // Mark the current point as visited
    maze[current.x][current.y] = 'X';

    // Check if the current point is the destination
    if (is_destination(current.x, current.y, dest))
        return true;

    // Check for all possible directions
    if (is_valid_point(current.x + 1, current.y) && dfs((point){current.x + 1, current.y}, dest))
        return true;

    if (is_valid_point(current.x - 1, current.y) && dfs((point){current.x - 1, current.y}, dest))
        return true;

    if (is_valid_point(current.x, current.y + 1) && dfs((point){current.x, current.y + 1}, dest))
        return true;

    if (is_valid_point(current.x, current.y - 1) && dfs((point){current.x, current.y - 1}, dest))
        return true;

    // Mark the current point as unvisited
    maze[current.x][current.y] = ' ';

    return false;
}

int main()
{
    // Initialize the start and end points
    point start = {1, 1};
    point dest = {7, 8};

    printf("The Maze:\n");
    print_maze();

    // Perform depth first search to find the path
    bool path_found = dfs(start, dest);

    printf("\nThe Path:\n");
    // Print the maze with the solution
    if (path_found)
        print_maze();
    else
        printf("Path not found!");

    return 0;
}