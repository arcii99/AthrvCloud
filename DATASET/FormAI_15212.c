//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define ROWS 15
#define COLS 30
 
#define WALL 1
#define OPEN 0
 
int maze[ROWS][COLS];
int visited[ROWS][COLS];
int solved[ROWS][COLS];
int start_x, start_y, end_x, end_y;
 
void generateMaze();
void printMaze();
void solveMaze(int x, int y);
 
int main()
{
    srand(time(NULL));
    generateMaze();
    printf("Generated Maze:\n");
    printMaze();
 
    printf("\nSolving Maze:\n");
    solveMaze(start_x, start_y);
    printMaze();
 
    return 0;
}
 
void generateMaze()
{
    int i, j;
 
    // initialize maze to all walls
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            maze[i][j] = WALL;
            visited[i][j] = 0;
            solved[i][j] = 0;
        }
    }
 
    // generate starting and ending points
    start_x = rand() % ROWS;
    start_y = rand() % COLS;
    end_x = rand() % ROWS;
    end_y = rand() % COLS;
 
    // make sure they are not on the same spot
    while (start_x == end_x && start_y == end_y)
    {
        end_x = rand() % ROWS;
        end_y = rand() % COLS;
    }
 
    // mark starting and ending points as open
    maze[start_x][start_y] = OPEN;
    maze[end_x][end_y] = OPEN;
 
    // recursively generate maze
    int new_x, new_y;
    do {
        new_x = rand() % (ROWS - 2) + 1;
        new_y = rand() % (COLS - 2) + 1;
    } while (new_x == start_x && new_y == start_y);
 
    maze[new_x][new_y] = OPEN;
    visited[new_x][new_y] = 1;
 
    generateMazeRecursive(new_x, new_y);
}
 
void generateMazeRecursive(int x, int y)
{
    int new_x, new_y, i, j, num_walls = 0;
 
    if (x == end_x && y == end_y)
    {
        return;
    }
 
    visited[x][y] = 1;
 
    // check adjacent cells
    int adj[4][2] = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
    for (i = 0; i < 4; i++)
    {
        new_x = adj[i][0];
        new_y = adj[i][1];
 
        // make sure new coordinates are in bounds
        if (new_x < 0 || new_y < 0 || new_x >= ROWS || new_y >= COLS)
        {
            continue;
        }
 
        // if visited, skip
        if (visited[new_x][new_y])
        {
            continue;
        }
 
        // count number of walls around new cell
        num_walls = 0;
        for (j = 0; j < 4; j++)
        {
            int adj_x = adj[j][0];
            int adj_y = adj[j][1];
            if (maze[adj_x][adj_y] == WALL)
            {
                num_walls++;
            }
        }
 
        // if only one wall, mark as open and continue recursion
        if (num_walls == 1)
        {
            maze[new_x][new_y] = OPEN;
            generateMazeRecursive(new_x, new_y);
        }
    }
}
 
void printMaze()
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == WALL) {
                printf("#");
            } else if (solved[i][j]) {
                printf("*");
            } else if (maze[i][j] == OPEN) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
 
void solveMaze(int x, int y)
{
    if (x == end_x && y == end_y)
    {
        solved[x][y] = 1;
        return;
    }
 
    // mark as visited
    solved[x][y] = 1;
 
    // check adjacent cells
    int adj[4][2] = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
    for (int i = 0; i < 4; i++)
    {
        int new_x = adj[i][0];
        int new_y = adj[i][1];
 
        // make sure new coordinates are in bounds
        if (new_x < 0 || new_y < 0 || new_x >= ROWS || new_y >= COLS)
        {
            continue;
        }
 
        // if visited, skip
        if (solved[new_x][new_y])
        {
            continue;
        }
 
        // if open, continue recursion
        if (maze[new_x][new_y] == OPEN)
        {
            solveMaze(new_x, new_y);
            if (solved[end_x][end_y])
            {
                return;
            }
        }
    }
 
    // mark as not on solution path
    solved[x][y] = 0;
}