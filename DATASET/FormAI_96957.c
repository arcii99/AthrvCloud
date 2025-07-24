//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int pathfinding_algo(int maze[ROW][COL], int visited[ROW][COL], int row, int col, int dest_row, int dest_col){
    // Check if the starting and end point are the same
    if(row == dest_row && col == dest_col){
        return 1;
    }

    // Check if the cell is unvisited and is not a wall
    if(maze[row][col] == 1 || visited[row][col]){
        return 0;
    }

    // Mark the cell as visited
    visited[row][col] = 1;

    // Try moving to the right
    if(col + 1 < COL){
        if(pathfinding_algo(maze, visited, row, col + 1, dest_row, dest_col)){
            printf("(%d, %d) ", row, col);
            return 1;
        }
    }

    // Try moving to the bottom
    if(row + 1 < ROW){
        if(pathfinding_algo(maze, visited, row + 1, col, dest_row, dest_col)){
            printf("(%d, %d) ", row, col);
            return 1;
        }
    }

    // Try moving to the left
    if(col - 1 >= 0){
        if(pathfinding_algo(maze, visited, row, col - 1, dest_row, dest_col)){
            printf("(%d, %d) ", row, col);
            return 1;
        }
    }

    // Try moving to the top
    if(row - 1 >= 0){
        if(pathfinding_algo(maze, visited, row - 1, col, dest_row, dest_col)){
            printf("(%d, %d) ", row, col);
            return 1;
        }
    }

    // If all directions have been explored and no path has been found
    return 0;
}

int main(){
    int maze[ROW][COL] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}
    };

    int visited[ROW][COL] = {0};

    int start_row = 0;
    int start_col = 0;
    int dest_row = 9;
    int dest_col = 9;

    printf("Path: ");
    // find the path using pathfinding algorithm
    int found_path = pathfinding_algo(maze, visited, start_row, start_col, dest_row, dest_col);

    if(!found_path){
        printf("Path not found.");
    }

    return 0;
}