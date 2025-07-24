//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: all-encompassing
#include <stdio.h>

//define size for 2D array
#define ROW 10
#define COL 10

//function to print the path
void printPath(int path[][COL], int row, int col) {
    printf("Path : ");
    for(int i = 0; i < row; i++) {
        printf("(%d, %d) ", path[i][0], path[i][1]);
    }
    printf("\n");
}

//function to check if the current position is valid
int isValid(int x, int y, int maze[][COL], int visited[][COL]) {
    if(x < 0 || y < 0 || x >= ROW || y >= COL || maze[x][y] == 0 || visited[x][y] != 0) {
        return 0;
    }
    return 1;
}

//main path finding function
int findPath(int maze[][COL], int visited[][COL], int path[][COL], int row, int col, int endX, int endY) {
    if(row == endX && col == endY) {
        path[0][0] = row;
        path[0][1] = col;
        printPath(path, ROW, COL);
        return 1;
    }
    if(isValid(row, col, maze, visited)) {
        visited[row][col] = 1;
        path[0][0] = row;
        path[0][1] = col;
        
        if(findPath(maze, visited, path+1, row+1, col, endX, endY) || findPath(maze, visited, path+1, row-1, col, endX, endY) || findPath(maze, visited, path+1, row, col+1, endX, endY) || findPath(maze, visited, path+1, row, col-1, endX, endY)) {
            return 1;
        }
        visited[row][col] = 0;
    }
    return 0;
}

//main function for testing pathfinding algorithm
int main() {
    int maze[ROW][COL] = 
    {
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    int visited[ROW][COL] = {0};
    int path[ROW*COL][2];
    
    int startX = 0;
    int startY = 0;
    int endX = 7;
    int endY = 7;
    
    if(findPath(maze, visited, path, startX, startY, endX, endY) == 0) {
        printf("No Path Found!!!");
    }
    
    return 0;
}