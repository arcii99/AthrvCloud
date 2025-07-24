//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: protected
#include <stdio.h>

// Define size of maze
#define ROW 5
#define COL 5

// Function to check whether the given cell is valid or not
int isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Function to check whether the given cell is blocked or not
int isBlocked(int maze[][COL], int row, int col) {
    return maze[row][col] == 1;
}

// Function to check whether the destination has been reached or not
int isDestination(int row, int col, int destRow, int destCol) {
    return row == destRow && col == destCol;
}

// Function to find the minimum distance between the source cell and destination cell
int findMinDistance(int maze[][COL], int srcRow, int srcCol, int destRow, int destCol) {
    // Array to store whether a cell has been visited or not
    int visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = 0;
        }
    }
    
    // Define arrays for row and column directions
    int rowDirection[] = {-1, 0, 1, 0};
    int colDirection[] = {0, 1, 0, -1};
    
    // Create a queue for BFS
    int queue[ROW * COL][2];
    int head = 0, tail = 0;
    
    // Put the source cell in the queue and mark it as visited
    queue[tail][0] = srcRow;
    queue[tail][1] = srcCol;
    visited[srcRow][srcCol] = 1;
    tail++;
    
    // Loop until the queue becomes empty
    while (head != tail) {
        // Get the next cell from the queue
        int currRow = queue[head][0];
        int currCol = queue[head][1];
        head++;
        
        // Check if we have reached the destination cell
        if (isDestination(currRow, currCol, destRow, destCol)) {
            return visited[currRow][currCol] - 1;
        }
        
        // Explore all the adjacent cells
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + rowDirection[i];
            int newCol = currCol + colDirection[i];
            
            // Check if the adjacent cell is valid, not blocked, and not visited yet
            if (isValid(newRow, newCol) && !isBlocked(maze, newRow, newCol) && !visited[newRow][newCol]) {
                // Mark the adjacent cell as visited and add it to the queue
                visited[newRow][newCol] = visited[currRow][currCol] + 1;
                queue[tail][0] = newRow;
                queue[tail][1] = newCol;
                tail++;
            }
        }
    }
    
    // If we reach here, it means that the destination cell cannot be reached from the source cell
    return -1;
}

int main() {
    int maze[ROW][COL] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    
    int srcRow = 0, srcCol = 0;
    int destRow = 4, destCol = 4;
    
    int minDistance = findMinDistance(maze, srcRow, srcCol, destRow, destCol);
    if (minDistance != -1) {
        printf("The minimum distance between the source cell and the destination cell is %d.\n", minDistance);
    } else {
        printf("The destination cell cannot be reached from the source cell.\n");
    }
    
    return 0;
}