//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#define ROWS 4
#define COLS 4

// Function to print the maze
void printMaze(int maze[ROWS][COLS]) {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check whether current cell is valid or not
int isValid(int row, int col) {
    return (row>=0 && row<ROWS && col>=0 && col<COLS);
}

// Function to check whether the current cell is destination or not
int isDestination(int row, int col, int destination[2]) {
    return (row==destination[0] && col==destination[1]);
}

// Function to check whether the current cell is blocked or not
int isBlocked(int row, int col, int maze[ROWS][COLS]) {
    return (maze[row][col]==0);
}

// Function to find the shortest path using BFS algorithm
void shortestPath(int maze[ROWS][COLS], int start[2], int destination[2]) {
    // Create a queue
    int queue[ROWS*COLS][2];
    int front=-1, rear=-1;
    int visited[ROWS][COLS] = {0};
    int parent[ROWS][COLS][2] = {0};
    int directions[4][2] = {{-1,0},{0,-1},{1,0},{0,1}}; // Up, Left, Down, Right
    
    // Enqueue the start node and mark it as visited
    queue[++rear][0] = start[0];
    queue[rear][1] = start[1];
    visited[start[0]][start[1]] = 1;
    
    // Traverse the maze using BFS algorithm
    while(front!=rear) {
        // Dequeue a node from the queue
        int currentRow = queue[++front][0];
        int currentCol = queue[front][1];
        
        // Check if the current cell is the destination
        if(isDestination(currentRow,currentCol,destination)) {
            printf("Shortest path found!\n");
            
            // Set the shortest path in the maze using the parent array
            int row = destination[0];
            int col = destination[1];
            maze[row][col] = 2;
            while(row!=start[0] || col!=start[1]) {
                int tempRow = row;
                int tempCol = col;
                row = parent[tempRow][tempCol][0];
                col = parent[tempRow][tempCol][1];
                maze[row][col] = 2;
            }
            maze[start[0]][start[1]] = 2;
            
            // Print the maze with shortest path
            printMaze(maze);
            return;
        }
        
        // Traverse all the adjacent cells
        for(int i=0;i<4;i++) {
            int newRow = currentRow + directions[i][0];
            int newCol = currentCol + directions[i][1];
            
            // Check if the adjacent cell is valid and not blocked and not already visited
            if(isValid(newRow,newCol) && !isBlocked(newRow,newCol,maze) && !visited[newRow][newCol]) {
                // Enqueue the adjacent cell and mark it as visited
                queue[++rear][0] = newRow;
                queue[rear][1] = newCol;
                visited[newRow][newCol] = 1;
                
                // Set the parent of the adjacent cell
                parent[newRow][newCol][0] = currentRow;
                parent[newRow][newCol][1] = currentCol;
            }
        }
    }
    
    printf("Shortest path not found!\n");
}

int main() {
    int maze[ROWS][COLS] = {
        {1,0,1,1},
        {1,1,0,1},
        {1,0,1,1},
        {1,1,1,1}
    };
    int start[2] = {0,0};
    int destination[2] = {3,2};
    printf("Maze:\n");
    printMaze(maze);
    printf("Finding shortest path...\n");
    shortestPath(maze,start,destination);
    return 0;
}