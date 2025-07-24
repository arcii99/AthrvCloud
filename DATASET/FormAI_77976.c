//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#define ROWS 5 
#define COLS 5 

// Function to print the grid 
void print(int grid[ROWS][COLS], int start[2], int end[2]) 
{ 
    printf("\n"); 
    for (int i = 0; i < ROWS; i++) { 
        for (int j = 0; j < COLS; j++) { 
            if (i == start[0] && j == start[1]) 
                printf(" S "); 
            else if (i == end[0] && j == end[1]) 
                printf(" E "); 
            else if (grid[i][j]) 
                printf(" X "); 
            else
                printf(" 0 "); 
        } 
        printf("\n"); 
    } 
    printf("\n"); 
} 

// Function to check if a cell is within the grid 
int isWithinGrid(int row, int col) 
{ 
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS); 
} 

// Function to check if a cell is obstacle or not 
int isObstacle(int grid[ROWS][COLS], int row, int col) 
{ 
    return (grid[row][col] == 1); 
} 

// A function to find the shortest path between a given start and end cell using Breadth First Search 
int BFS(int grid[ROWS][COLS], int start[2], int end[2]) 
{ 
    int row[] = { -1, 0, 0, 1 }; 
    int col[] = { 0, -1, 1, 0 }; 

    // Mark the visited cells 
    int visited[ROWS][COLS]; 
    for (int i = 0; i < ROWS; i++) 
        for (int j = 0; j < COLS; j++) 
            visited[i][j] = 0; 

    // Mark the start cell as visited 
    visited[start[0]][start[1]] = 1; 

    // Initial queue for BFS 
    int queue[ROWS * COLS][2]; 
    int rear = 0, front = 0; 
    queue[rear][0] = start[0]; 
    queue[rear][1] = start[1]; 

    // BFS loop 
    while (rear >= front) { 

        // Dequeue the front cell 
        int currRow = queue[front][0]; 
        int currCol = queue[front][1]; 
        front++; 

        // If we have reached the end cell, we are done! 
        if (currRow == end[0] && currCol == end[1]) 
            return visited[currRow][currCol]; 

        // Check each neighbour of the current cell 
        for (int i = 0; i < 4; i++) { 
            int newRow = currRow + row[i]; 
            int newCol = currCol + col[i]; 

            // If the cell is within the grid and is not an obstacle and is not visited yet, mark it visited and enqueue it 
            if (isWithinGrid(newRow, newCol) && !isObstacle(grid, newRow, newCol) && !visited[newRow][newCol]) { 
                visited[newRow][newCol] = visited[currRow][currCol] + 1; 
                queue[++rear][0] = newRow; 
                queue[rear][1] = newCol; 
            } 
        } 
    } 

    // If no path exists from start to end, return -1 
    return -1; 
} 

// Driver function 
int main() 
{ 
    int grid[ROWS][COLS] = { 
        { 0, 1, 0, 0, 0 }, 
        { 0, 1, 0, 1, 0 }, 
        { 0, 1, 0, 1, 0 }, 
        { 0, 1, 0, 1, 0 }, 
        { 0, 0, 0, 1, 0 } 
    }; 

    // Define the start and end points 
    int start[2] = { 0, 0 }; 
    int end[2] = { ROWS - 1, COLS - 1 }; 

    // Print the initial grid 
    printf("Initial Grid:"); 
    print(grid, start, end); 

    // Find the shortest path 
    int shortestPath = BFS(grid, start, end); 

    // Print the final grid 
    printf("Final Grid:"); 
    print(grid, start, end); 

    // Print the shortest path, if it exists 
    if (shortestPath != -1) 
        printf("Shortest Path: %d\n", shortestPath); 
    else
        printf("No path exists from start to end.\n"); 

    return 0; 
}