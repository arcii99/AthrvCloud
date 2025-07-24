//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW 5
#define COL 5
 
// Check if row and column are valid or not
bool isValid(int row, int col, int maze[][COL], bool visited[][COL])
{
    if(row>=0 && row<ROW && col>=0 && col<COL && maze[row][col] == 1 && !visited[row][col])
        return true;
    else
        return false;
}

// Print the solution pathway
void printPath(int path[][COL], int dest_row, int dest_col)
{
    printf("Pathway found!\n");
    for(int i=0; i<=dest_row; i++) {
        for(int j=0; j<=dest_col; j++)
            printf("%d ",path[i][j]);
        printf("\n");
    }
}

// Function to find the pathway in maze
bool findPath(int maze[][COL], int row, int col, int dest_row, int dest_col, 
              int path[][COL], bool visited[][COL])
{
    // If destination is reached
    if(row == dest_row && col == dest_col) {
        path[row][col] = 1;
        printPath(path, dest_row, dest_col);
        return true;
    }

    // Verify if current cell is valid
    if(isValid(row, col, maze, visited)) {
        visited[row][col] = true;
        path[row][col] = 1;

        // Go right, left, up, down
        if(findPath(maze, row, col+1, dest_row, dest_col, path, visited))
            return true;
             
        if(findPath(maze, row, col-1, dest_row, dest_col, path, visited))
            return true;
             
        if (findPath(maze, row-1, col, dest_row, dest_col, path, visited))
            return true;
 
        if (findPath(maze, row+1, col, dest_row, dest_col, path, visited))
            return true;

        // If none of the movements specified above work then backtrack
        path[row][col] = 0;
        return false;
    }
    return false;
}

int main()
{
    int maze[ROW][COL] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1}
    };
    int path[ROW][COL];
    bool visited[ROW][COL];
    int src_row = 0, src_col = 0, dest_row = 4, dest_col = 4;

    // Initialize visited cells
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            visited[i][j] = false;

    // Initialize path matrix to 0
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            path[i][j] = 0;

    // Find and print the pathway in the maze
    if(findPath(maze, src_row, src_col, dest_row, dest_col, path, visited) == false)
        printf("Path not found.\n");

    return 0;
}