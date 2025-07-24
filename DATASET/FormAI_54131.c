//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 5

//function to print the maze
void printMaze(int maze[][COL]) 
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//function to check if the position is valid
int isValid(int maze[][COL], int x, int y) 
{
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1) {
        return 1;
    }
    return 0;
}

//function to find the route
int findRoute(int maze[][COL], int x, int y, int sol[][COL]) 
{
    if (x == ROW - 1 && y == COL - 1) {
        sol[x][y] = 1;
        return 1;
    }
    if (isValid(maze, x, y) == 1) {
        sol[x][y] = 1;  
        if (findRoute(maze, x + 1, y, sol) == 1) {
            return 1;
        }
        if (findRoute(maze, x, y + 1, sol) == 1) {
            return 1;
        }
        sol[x][y] = 0;
        return 0;
    }
    return 0;
}

int main() 
{
    int maze[ROW][COL] = { 
        { 1, 0, 1, 1, 0 }, 
        { 1, 1, 1, 0, 1 }, 
        { 0, 1, 0, 1, 1 }, 
        { 1, 0, 0, 1, 0 },
        { 1, 1, 1, 1, 1 } 
    };
    int sol[ROW][COL] = {  0 };

    printf("The maze:\n");
    printMaze(maze);

    printf("The solution:\n");
    if (findRoute(maze, 0, 0, sol) == 1) {
        printMaze(sol);
    } else {
        printf("Solution does not exist.\n");
    }
    return 0;
}