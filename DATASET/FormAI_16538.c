//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10

typedef struct {
    int x, y;
} coordinates;

int validMove(int row, int col, int maze[][COL], int visited[][COL]) {
    // check if position is inside the maze
    if (row >= 0 && row < ROW && col >= 0 && col < COL) {
        // check if position is not a wall and not visited before
        if (maze[row][col] == 1 && visited[row][col] == 0) {
            return 1;
        }
    }
    return 0;
}

int DFS(int maze[][COL], int visited[][COL], coordinates start, coordinates end) {
    // stack stores the path as coordinates
    coordinates stack[ROW * COL] = {start};
    int top = 0, idx = 0;
    visited[start.x][start.y] = 1;
    
    while (top >= 0) {
        int row = stack[top].x;
        int col = stack[top].y;
        
        // check if reached the end point
        if (row == end.x && col == end.y) {
            return 1;
        }
        top--;
        
        // check top move
        if (validMove(row - 1, col, maze, visited)) {
            visited[row - 1][col] = 1;
            stack[++top] = (coordinates){row - 1, col};
        }
        
        // check bottom move
        if (validMove(row + 1, col, maze, visited)) {
            visited[row + 1][col] = 1;
            stack[++top] = (coordinates){row + 1, col};
        }
        
        // check left move
        if (validMove(row, col - 1, maze, visited)) {
            visited[row][col - 1] = 1;
            stack[++top] = (coordinates){row, col - 1};
        }
        
        // check right move
        if (validMove(row, col + 1, maze, visited)) {
            visited[row][col + 1] = 1;
            stack[++top] = (coordinates){row, col + 1};
        }
    }
    return 0;
}

int main() {
    int maze[ROW][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    coordinates start = {1, 1};
    coordinates end = {8, 8};
    
    int visited[ROW][COL] = {0};
    int pathExists = DFS(maze, visited, start, end);
    
    if (pathExists) {
        printf("Path exists from (%d, %d) to (%d, %d).\n", start.x, start.y, end.x, end.y);
    } else {
        printf("Path does not exist from (%d, %d) to (%d, %d).\n", start.x, start.y, end.x, end.y);
    }
    return 0;
}