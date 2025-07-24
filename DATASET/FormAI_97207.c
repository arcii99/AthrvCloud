//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: shocked
#include <stdio.h>

#define ROW 6
#define COL 6

// Function to check if cell (i,j) is valid or not
int is_valid(int i, int j) 
{
    // Checking boundaries of the maze
    if (i >= 0 && i < ROW && j >= 0 && j < COL)
        return 1;

    return 0;
}

//Function to find route through maze using DFS algorithm
int maze_route_finder(int maze[][COL], int visited[][COL], int i, int j) 
{
    // Returns 1 if we reach end point
    if (i == ROW-1 && j == COL-1 && maze[i][j] == 1) 
    {
        visited[i][j] = 1;
        return 1;
    }
    
    // Check if the current cell is valid and unvisited and is free to move
    if (is_valid(i, j) && maze[i][j] == 1 && !visited[i][j]) 
    {
        // Mark the current cell as visited 
        visited[i][j] = 1;
        
        // Check for all possible movements
        if (maze_route_finder(maze, visited, i-1, j)) // Move North
            return 1;
            
        if (maze_route_finder(maze, visited, i+1, j)) // Move South
            return 1;
            
        if (maze_route_finder(maze, visited, i, j-1)) // Move West
            return 1;
            
        if (maze_route_finder(maze, visited, i, j+1)) // Move East
            return 1;
            
        // If the cell does not lead to end point, mark it as unvisited
        visited[i][j] = 0;
        return 0;
    }
    
    return 0; // Return 0 if cell is not valid or not free to move
}

int main() 
{
    // Maze blueprint
    int maze[ROW][COL] = {
        {1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1}
        };

    // The matrix to keep track of visited cells
    int visited[ROW][COL] = {{0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0}
                        };
                        
    // Calling the maze route finder function
    if (maze_route_finder(maze, visited, 0, 0)) 
    {
        printf("Route Found!\n");
        
        // Printing the path
        for (int i = 0; i < ROW; i++) 
        {
            for (int j = 0; j < COL; j++) 
            {
                if (visited[i][j] == 1)
                    printf("->[%d][%d] ", i, j);
            }
        }
        
        printf("->[%d][%d]\n", ROW-1, COL-1);
    } 
    
    else 
    {
        printf("No Route Found!\n");
    }
    
    return 0;    
}