//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: artistic
#include <stdio.h>

// The Maze
char maze[10][10] = {
    {' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', ' '},
    {'X', 'X', 'X', ' ', 'X', 'X', ' ', 'X', 'X', ' '},
    {' ', ' ', ' ', ' ', 'X', ' ', ' ', 'X', ' ', 'X'},
    {' ', 'X', 'X', 'X', 'X', 'X', ' ', 'X', ' ', 'X'},
    {' ', ' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X'},
    {'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', ' ', 'X'},
    {'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', ' ', 'X'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},
    {'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X', 'X', ' '}
};

// The start and end positions
int startRow = 0, startCol = 0;
int endRow = 9, endCol = 9;

// The stack for storing the path
int path[100][2];
int top = -1;

// The visited array to keep track of visited squares
int visited[10][10];

// Function to check if a square is valid
int isValid(int row, int col) {
    return row >= 0 && col >= 0 && row < 10 && col < 10 && maze[row][col] != 'X' && !visited[row][col];
}

// Function to perform DFS
int DFS(int row, int col) {
    // If we have reached the end position, return true
    if(row == endRow && col == endCol) {
        path[++top][0] = row;
        path[top][1] = col;
        return 1;
    }

    // Mark the current square as visited
    visited[row][col] = 1;

    if(isValid(row+1, col) && DFS(row+1, col)) {  // try moving down
        path[++top][0] = row;
        path[top][1] = col;
        return 1;
    }
    if(isValid(row, col+1) && DFS(row, col+1)) {  // try moving right
        path[++top][0] = row;
        path[top][1] = col;
        return 1;
    }
    if(isValid(row-1, col) && DFS(row-1, col)) {  // try moving up
        path[++top][0] = row;
        path[top][1] = col;
        return 1;
    }
    if(isValid(row, col-1) && DFS(row, col-1)) {  // try moving left
        path[++top][0] = row;
        path[top][1] = col;
        return 1;
    }

    // If no move worked, backtrack
    return 0;
}

// Function to print the maze and the path
void print() {
    int row, col;
    for(row = 0; row < 10; row++) {
        for(col = 0; col < 10; col++) {
            if(row == startRow && col == startCol) {  // print start position
                printf("S ");
            } else if(row == endRow && col == endCol) {  // print end position
                printf("E ");
            } else if(visited[row][col]) {  // print path
                printf(". ");
            } else {  // print maze
                printf("%c ", maze[row][col]);
            }
        }
        printf("\n");
    }
}

int main() {
    // Perform the DFS
    DFS(startRow, startCol);

    // Print the maze and the path
    print();

    return 0;
}