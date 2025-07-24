//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int isValid(int row, int col, int maze[][COL], int visited[][COL]){
    if (row < 0 || col < 0 || row >= ROW || col >= COL || maze[row][col] == 0 || visited[row][col] == 1){
        return 0;
    }
    return 1;
}

int pathfinder(int maze[][COL], int visited[][COL], int row, int col, int endRow, int endCol){
    if (row == endRow && col == endCol){
        visited[row][col] = 1;
        return 1;
    }
    if (isValid(row, col, maze, visited)){
        visited[row][col] = 1;
        if (pathfinder(maze, visited, row-1, col, endRow, endCol)){
            return 1;
        }
        if (pathfinder(maze, visited, row, col+1, endRow, endCol)){
            return 1;
        }
        if (pathfinder(maze, visited, row+1, col, endRow, endCol)){
            return 1;
        }
        if (pathfinder(maze, visited, row, col-1, endRow, endCol)){
            return 1;
        }
        visited[row][col] = 0;
    return 0;
    }
}

int main(){
    int maze[ROW][COL] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
                          {1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                          {1, 0, 1, 0, 0, 0, 0, 1, 0, 0},
                          {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
                          {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
                          {1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
                          {0, 0, 0, 1, 1, 1, 0, 1, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    int visited[ROW][COL] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    int startRow = 0;
    int startCol = 0;
    int endRow = 9;
    int endCol = 9;

    if (pathfinder(maze, visited, startRow, startCol, endRow, endCol)){
        printf("Path found\n");
    }
    else{
        printf("No path found\n");
    }

    return 0;
}