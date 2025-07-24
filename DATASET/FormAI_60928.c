//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: random
/*
 * Maze Route Finder Program
 * Author: Random Coder
 * Date: 22nd September, 2021
 */

#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 10
#define COL_SIZE 10

void printMaze(int maze[][COL_SIZE], int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int maze[][COL_SIZE], int row, int col, int visited[][COL_SIZE]) {
    return (row>=0 && row<ROW_SIZE && col>=0 && col<COL_SIZE && (maze[row][col]==1) && visited[row][col]==0);
}

int findRoute(int maze[][COL_SIZE], int row, int col, int visited[][COL_SIZE]) {
    if(row==ROW_SIZE-1 && col==COL_SIZE-1) {
        visited[row][col] = 1;
        return 1;
    }

    if(isSafe(maze, row, col, visited)) {
        visited[row][col] = 1;
        if(findRoute(maze, row+1, col, visited)) {
            return 1;
        }
        if(findRoute(maze, row, col+1, visited)) {
            return 1;
        }
        if(findRoute(maze, row-1, col, visited)) {
            return 1;
        }
        if(findRoute(maze, row, col-1, visited)) {
            return 1;
        }
        visited[row][col] = 0;
        return 0;
    }
    return 0;
}

int main() {
    int maze[ROW_SIZE][COL_SIZE] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                                    {1, 1, 1, 0, 0, 0, 0, 1, 0, 0},
                                    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                                    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                                    {1, 0, 1, 1, 0, 1, 1, 1, 0, 0},
                                    {1, 0, 1, 0, 0, 1, 0, 1, 1, 0},
                                    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                                    {1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
                                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    int visited[ROW_SIZE][COL_SIZE];
    for(int i=0; i<ROW_SIZE; i++) {
        for(int j=0; j<COL_SIZE; j++) {
            visited[i][j] = 0;
        }
    }

    printf("The Maze:\n");
    
    // Print the maze
    printMaze(maze, ROW_SIZE, COL_SIZE);
    
    printf("\n");

    printf("The Solution:\n");
    // Find the route and print the solution
    if(findRoute(maze, 0, 0, visited)) {
        for(int i=0; i<ROW_SIZE; i++) {
            for(int j=0; j<COL_SIZE; j++) {
                if(visited[i][j] == 1) {
                    printf("(%d, %d) -> ", i, j);
                }
            }
        }
        printf("Exit\n");
    }
    else {
        printf("No solution found!\n");   
    }

    return 0;
}