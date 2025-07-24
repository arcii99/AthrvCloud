//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 15

void generateMaze(int maze[HEIGHT][WIDTH]) {
    srand(time(NULL));
    
    // Initialize all cells to be walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Randomly select a starting cell
    int currentRow = rand() % HEIGHT;
    int currentCol = rand() % WIDTH;
    maze[currentRow][currentCol] = 0; // Set the starting cell to be a path
    
    // Keep track of the visited cells
    int visited[HEIGHT][WIDTH] = {0};
    visited[currentRow][currentCol] = 1;
    
    // Create a stack to keep track of the visited cells
    int stack[HEIGHT*WIDTH][2];
    int top = 0;
    stack[top][0] = currentRow;
    stack[top][1] = currentCol;
    
    // Start generating the maze
    while (top >= 0) {
        // Pop the current cell from the stack
        currentRow = stack[top][0];
        currentCol = stack[top][1];
        top--;
        
        // Check all four adjacent cells
        int neighbors[4][2] = {{currentRow-1, currentCol}, {currentRow+1, currentCol}, 
                               {currentRow, currentCol-1}, {currentRow, currentCol+1}};
        for (int i = 0; i < 4; i++) {
            int row = neighbors[i][0];
            int col = neighbors[i][1];
            
            // Check if the adjacent cell is inside the maze
            if (row < 0 || row >= HEIGHT || col < 0 || col >= WIDTH) {
                continue;
            }
            
            // Check if the adjacent cell has not been visited
            if (visited[row][col]) {
                continue;
            }
            
            // Add the current cell to the stack and remove the wall between the two cells
            top++;
            stack[top][0] = currentRow;
            stack[top][1] = currentCol;
            
            // Remove the wall between the two cells
            if (row == currentRow-1) { // Top cell
                maze[currentRow][currentCol] &= ~1; // Remove the top wall from the current cell
                maze[row][col] &= ~4; // Remove the bottom wall from the adjacent cell
            } else if (row == currentRow+1) { // Bottom cell
                maze[currentRow][currentCol] &= ~4; // Remove the bottom wall from the current cell
                maze[row][col] &= ~1; // Remove the top wall from the adjacent cell
            } else if (col == currentCol-1) { // Left cell
                maze[currentRow][currentCol] &= ~8;  // Remove the left wall from the current cell
                maze[row][col] &= ~2; // Remove the right wall from the adjacent cell
            } else if (col == currentCol+1) { // Right cell
                maze[currentRow][currentCol] &= ~2; // Remove the right wall from the current cell
                maze[row][col] &= ~8; // Remove the left wall from the adjacent cell
            }
            
            // Visit the adjacent cell and add it to the stack
            visited[row][col] = 1;
            currentRow = row;
            currentCol = col;
            maze[currentRow][currentCol] = 0; // Set the adjacent cell to be a path
            break;
        }
    }
}

int main() {
    int maze[HEIGHT][WIDTH];
    generateMaze(maze);
    
    // Print the maze
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("#"); // Wall
            } else {
                printf(" "); // Path
            }
        }
        printf("\n");
    }
    
    return 0;
}