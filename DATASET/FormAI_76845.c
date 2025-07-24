//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// The structure to represent a cell in a maze
struct Cell {
    int row;
    int col;
};

// Function to check if a cell is valid or not
bool isValidCell(int row, int col, char maze[][COL], bool visited[][COL]) {
    // Check if the cell is within the maze bounds
    if (row >= 0 && row < ROW && col >= 0 && col < COL) {
        // Check if the cell is not a wall and not yet visited
        if (maze[row][col] != '#' && visited[row][col] == false) {
            return true;
        }
    }
    return false;
}

// Function to find the shortest path using Breadth First Search algorithm
void findShortestPath(int startRow, int startCol, int endRow, int endCol, char maze[][COL]) {
    // 2D array to mark visited cells
    bool visited[ROW][COL] = {false};
    visited[startRow][startCol] = true;
    
    // Queue to store cells and its distance from the start cell
    struct Cell queue[ROW*COL];
    int front = 0, rear = 0;
    queue[rear++] = (struct Cell) {startRow, startCol};
    
    // Array to store parent cell of each cell
    struct Cell parent[ROW][COL];
    parent[startRow][startCol] = (struct Cell) {-1, -1};
    
    // Variables to keep track of the current cell and its distance from start cell
    int currentRow, currentCol, distance = 0;
    
    // Arrays to represent the four possible moves from a cell
    int rowMoves[] = {0, 1, 0, -1};
    int colMoves[] = {1, 0, -1, 0};
    
    // Loop until the queue is empty or end cell is found
    while (front < rear) {
        // Dequeue the front cell and check if it's the end cell
        struct Cell current = queue[front++];
        currentRow = current.row;
        currentCol = current.col;
        if (currentRow == endRow && currentCol == endCol) {
            // End cell is found, print the shortest path
            printf("Shortest path from start to end:\n");
            int row = endRow, col = endCol;
            printf("(%d, %d)", row, col);
            while (parent[row][col].row != -1 && parent[row][col].col != -1) {
                struct Cell temp = parent[row][col];
                row = temp.row;
                col = temp.col;
                printf(" -> (%d, %d)", row, col);
            }
            printf("\nDistance: %d\n", distance);
            return;
        }
        // Explore the four possible moves from the current cell
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + rowMoves[i];
            int newCol = currentCol + colMoves[i];
            if (isValidCell(newRow, newCol, maze, visited)) {
                visited[newRow][newCol] = true;
                queue[rear++] = (struct Cell) {newRow, newCol};
                parent[newRow][newCol] = current;
            }
        }
        distance++;
    }
    // End cell is not reachable
    printf("End cell is not reachable from the start cell.\n");
}

int main() {
    char maze[ROW][COL] = {
        {'S', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
        {'.', '#', '.', '.', '.', '.', '.', '#', '.', '.'},
        {'.', '.', '.', '.', '#', '.', '.', '#', '.', '.'},
        {'.', '#', '#', '#', '#', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '#', '.', '.', '.', '#', '.'},
        {'.', '.', '#', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '#', '.', '#', '.', '.', '.', '.', '#', '.'},
        {'.', '#', '.', '.', '.', '#', '.', '#', '.', '.'},
        {'.', '#', '#', '#', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '#', '.', '.', '.', '.', 'E'}
    };
    int startRow = 0, startCol = 0, endRow = 9, endCol = 9;
    printf("Maze:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
            if (maze[i][j] == 'S') {
                startRow = i;
                startCol = j;
            } else if (maze[i][j] == 'E') {
                endRow = i;
                endCol = j;
            }
        }
        printf("\n");
    }
    findShortestPath(startRow, startCol, endRow, endCol, maze);
    return 0;
}