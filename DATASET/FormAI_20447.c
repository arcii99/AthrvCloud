//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: visionary
#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 15

// Function to print the maze
void printMaze(char maze[][COL]){
    for (int i=0; i<ROW; i++)
    {
        for (int j=0; j<COL; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a given position is valid or not
bool isValid(int row, int col, char maze[][COL], bool visited[][COL]){

    // Check if row and column are within limits
    if (row >= 0 && row < ROW && col >= 0 && col < COL)

        // Check if the cell is not visited and is not a wall
        if (maze[row][col] != '#' && !visited[row][col])
            return true;

    return false;
}

// Recursive function to find the path through the maze
bool findPathUtil(int row, int col, char maze[][COL], bool visited[][COL])
{
    // If the destination is reached, mark it as visited and return true
    if (maze[row][col] == 'D'){
        visited[row][col] = true;
        return true;
    }

    // Check if the current position is valid or not
    if (isValid(row, col, maze, visited))
    {
        // Mark the current cell as visited
        visited[row][col] = true;

        // Check in all 4 directions
        if (findPathUtil(row+1, col, maze, visited))
            return true;

        if (findPathUtil(row-1, col, maze, visited))
            return true;

        if (findPathUtil(row, col+1, maze, visited))
            return true;

        if (findPathUtil(row, col-1, maze, visited))
            return true;

        // If none of the directions work, backtrack and mark the current cell as unvisited
        visited[row][col] = false;
        return false;
    }

    return false;
}

// Function to find the path through the maze
void findPath(char maze[][COL])
{
    // Initialize the visited array with false
    bool visited[ROW][COL];
    for (int i=0; i<ROW; i++)
        for (int j=0; j<COL; j++)
            visited[i][j] = false;

    // Find the starting position
    int start_row, start_col;
    for (int i=0; i<ROW; i++)
        for (int j=0; j<COL; j++)
            if (maze[i][j] == 'S'){
                start_row = i;
                start_col = j;
            }

    // Find the path through the maze
    if (findPathUtil(start_row, start_col, maze, visited))
        printf("Path Found!\n");
    else
        printf("No Path Found!\n");

    // Print the maze with the path marked
    for (int i=0; i<ROW; i++)
    {
        for (int j=0; j<COL; j++)
        {
            if (maze[i][j] != '#' && visited[i][j])
                printf(".");
            else
                printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main(){

    // Define the maze
    char maze[ROW][COL] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', 'D', '#'},
    };

    // Print the initial maze
    printf("Initial Maze:\n");
    printMaze(maze);

    // Find the path through the maze
    findPath(maze);

    return 0;
}