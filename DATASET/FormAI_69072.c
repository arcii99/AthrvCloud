//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {{0}}; // 10 x 10 maze with all elements initialized to 0

// Function to print the maze
void print_maze() {
    printf(" __ __ __ __ __ __ __ __ __ __ \n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf("|__");
            } else if (maze[i][j] == 1) {
                printf("|  ");
            } else if (maze[i][j] == 2) {
                printf("|**");
            }
        }
        printf("|\n");
    }
}

// Function to generate random obstacles in the maze
void generate_obstacles() {
    srand(time(NULL));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int r = rand() % 10 + 1;
            if (r >= 8) {
                maze[i][j] = 1;
            }
        }
    }
}

// Function to find the path using Depth First Search algorithm
void dfs(int x, int y) {
    if (x < 0 || x >= ROW || y < 0 || y >= COL) { // Check if the location is out of bounds
        return;
    }
    if (maze[x][y] == 1 || maze[x][y] == 2) { // Check if the location is an obstacle or already visited
        return;
    }
    maze[x][y] = 2; // Mark the current location as visited
    dfs(x + 1, y); // Recursively search the neighboring cells
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    generate_obstacles(); // Generate random obstacles in the maze
    print_maze(); // Print the maze before finding the path
    printf("\nFinding the path using Depth First Search algorithm...\n");
    dfs(0, 0); // Find the path using Depth First Search
    printf("\n");
    print_maze(); // Print the maze after finding the path
    return 0;
}