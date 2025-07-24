//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

// Structure to represent a cell in the maze
struct Cell {
    int row, col;
};

// Function to check if the given cell is valid or not
int is_valid(int row, int col)
{
    return row>=0 && row<ROW && col>=0 && col<COL;
}

// Function to check if the given cell is not blocked by a wall
int is_free(int maze[][COL], int row, int col)
{
    return maze[row][col] == 0;
}

// Function to print the path taken to solve the maze
void print_path(int parent[][COL], struct Cell start, struct Cell end)
{
    if(start.row==end.row && start.col==end.col) {
        printf("(%d,%d) ", start.row, start.col);
        return;
    }
    struct Cell curr = {end.row, end.col};
    while(curr.row!=start.row || curr.col!=start.col) {
        printf("(%d,%d) ", curr.row, curr.col);
        curr = (struct Cell){parent[curr.row][curr.col]/10, parent[curr.row][curr.col]%10};
    }
    printf("(%d,%d) ", start.row, start.col);
}

// Breadth first search function to find the shortest path in the maze
void find_shortest_path(int maze[][COL], struct Cell start, struct Cell end)
{
    // Array to store whether we have visited the cell or not
    int visited[ROW][COL] = {0};
    // Array to store the parent of a cell in the path
    int parent[ROW][COL] = {0};
    // Array for the directions to move along
    int direction[][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}}; // up, left, down, right
    // Queue to do Breadth First Search
    struct Cell q[ROW*COL];
    int front=-1, rear=-1;
    // Start the search from the start cell
    q[++rear] = start;
    visited[start.row][start.col] = 1;
    parent[start.row][start.col] = start.row*10 + start.col;
    // Keep searching until we have visited all possible cells
    while(front!=rear) {
        struct Cell curr = q[++front];
        // If we have reached the end cell, print the path and return
        if(curr.row==end.row && curr.col==end.col) {
            print_path(parent, start, end);
            return;
        }
        // Check all possible directions to move along
        for(int i=0; i<4; i++) {
            int next_row = curr.row + direction[i][0];
            int next_col = curr.col + direction[i][1];
            // Check if the next cell is valid and free to move along
            if(is_valid(next_row, next_col) && is_free(maze, next_row, next_col) && !visited[next_row][next_col]) {
                // Update the parent and enqueue the next cell
                visited[next_row][next_col] = 1;
                parent[next_row][next_col] = curr.row*10 + curr.col;
                q[++rear] = (struct Cell){next_row, next_col};
            }
        }
    }
}

int main()
{
    // Test maze to find the shortest path
    int maze[ROW][COL] = {
        {0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };
    
    // Start and end cells of the path
    struct Cell start = {0, 0};
    struct Cell end = {ROW-1, COL-1};
    
    // Find the shortest path in the maze
    find_shortest_path(maze, start, end);
    
    return 0;
}