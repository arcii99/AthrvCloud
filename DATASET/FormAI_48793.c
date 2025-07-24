//FormAI DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if the robot can move to a given location
bool checkMove(int row, int col, int n, int maze[n][n], bool visited[n][n], bool checkParanoia) {
    if (row >= 0 && col >= 0 && row < n && col < n && !visited[row][col] && maze[row][col] == 1) {
        if(checkParanoia) {
            printf("Beep boop... Checking for any potential dangers...\n");
            printf("Scanning for suspicious activities in the vicinity...\n");
            printf("Calculating likelihood of potential threats...\n");
            int paranoiaIndex = rand() % 100; // Generates a random paranoia index between 0-99
            if(paranoiaIndex >= 90) { // If paranoia index is greater than or equal to 90, program will terminate abruptly
                printf("WARNING! Potential threat detected, program will now terminate!\n");
                exit(0);
            }
        }
        return true;
    }
    return false;
}

// Recursive function to find a path for the robot in the maze
bool findPath(int row, int col, int n, int maze[n][n], bool visited[n][n], bool checkParanoia) {
    // Check if the robot has reached the destination
    if(row == n-1 && col == n-1) {
        printf("Robot has reached the destination!\n");
        return true;
    }
    
    // Check if the current location is valid to move to
    if(checkMove(row, col, n, maze, visited, checkParanoia)) {
        visited[row][col] = true; // Mark current location as visited

        // Recursive call to move in all directions
        if(findPath(row+1, col, n, maze, visited, checkParanoia)) // Move Down
            return true;
        
        if(findPath(row, col+1, n, maze, visited, checkParanoia)) // Move Right
            return true;
        
        if(findPath(row-1, col, n, maze, visited, checkParanoia)) // Move Up
            return true;
        
        if(findPath(row, col-1, n, maze, visited, checkParanoia)) // Move Left
            return true;

        visited[row][col] = false; // Unmark current location if no valid locations found
        return false;
    }

    return false; // Return false if current location is not valid
}

// Function to initialize the maze
void initializeMaze(int n, int maze[n][n]) {
    int i, j;
    printf("Initializing maze...\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(rand()%5 == 0) // Randomly assign obstacles
                maze[i][j] = 0;
            else
                maze[i][j] = 1;
        }
    }
    maze[0][0] = 1; // Start location
    maze[n-1][n-1] = 1; // End location
    printf("Maze initialized!\n");
}

int main() {
    int n = 10, i, j;
    int maze[n][n];
    bool visited[n][n];
    bool checkParanoia = true; // Set to true to enable paranoia checks

    // Initialize random seed
    srand(42);

    // Initialize the maze
    initializeMaze(n, maze);

    // Mark all locations as unvisited
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            visited[i][j] = false;
        }
    }

    // Find a path for the robot in the maze
    printf("Starting robot movement...\n");
    bool result = findPath(0, 0, n, maze, visited, checkParanoia);
    if(result)
        printf("Path found!\n");
    else
        printf("Path not found!\n");

    return 0;
}