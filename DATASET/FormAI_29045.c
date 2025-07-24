//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scientific
#include<stdio.h>
#define ROW 6
#define COL 6

// Function to check if the current cell is valid or not
int is_valid(int maze[][COL], int x, int y)
{
    if(x>=0 && x<ROW && y>=0 && y<COL && maze[x][y]==1)
        return 1;
    return 0;
}

// Function to print the final solution
void print_solution(int solution[][COL])
{
    printf("The Maze Solution is: \n");
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
            printf("%d ",solution[i][j]);
        printf("\n");
    }
}

// Recursive function to find the route in maze
int find_route(int maze[][COL], int x, int y, int solution[][COL])
{
    // Base Case: If destination is reached, return 1.
    if(x==ROW-1 && y==COL-1)
    {
        solution[x][y] = 1;
        return 1;
    }
    
    // Check if the current cell is valid
    if(is_valid(maze,x,y)==1)
    {
        solution[x][y] = 1;
        
        // Move in the forward direction
        if(find_route(maze,x+1,y,solution)==1)
            return 1;
            
        // Move in the downward direction
        if(find_route(maze,x,y+1,solution)==1)
            return 1;
            
        // Backtrack: If none of the directions work, mark the cell as not part of solution and go back
        solution[x][y] = 0;
        return 0;
    }
    
    // If the current cell is not valid
    return 0;
}

// Function to start the solution
void start_solve_maze(int maze[][COL])
{
    // Create a solution maze and initialize it to 0
    int solution[ROW][COL] = {0};
    
    // If solution does not exist, print No Solution
    if(find_route(maze,0,0,solution)==0)
        printf("No Solution Exist!\n");
    else
        print_solution(solution);
}

// main function
int main()
{
    // Maze demo
    int maze[ROW][COL] = {{1,1,0,0,0,0},
                          {1,1,1,1,1,0},
                          {0,1,0,0,1,0},
                          {0,1,1,1,1,1},
                          {0,0,0,0,1,0},
                          {0,0,0,0,1,1}};
                          
    // Start solving the maze
    start_solve_maze(maze);
    
    return 0;
}