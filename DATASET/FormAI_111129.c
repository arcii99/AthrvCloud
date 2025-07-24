//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

// Define struct for each cell in the maze grid
typedef struct {
    int north_wall;
    int east_wall;
    int south_wall;
    int west_wall;
    int visited;
} Cell;

// Function to generate a random integer between min and max (inclusive)
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Recursive function to generate the maze
void generate_maze(Cell maze[MAZE_SIZE][MAZE_SIZE], int row, int col) {
    // Mark the current cell as visited
    maze[row][col].visited = 1;
    
    // Generate an array of random directions to travel
    int directions[4] = {0, 1, 2, 3};
    for (int i = 3; i > 0; i--) {
        int j = random_int(0, i);
        int temp = directions[j];
        directions[j] = directions[i];
        directions[i] = temp;
    }
    
    // Loop through the randomized directions
    for (int i = 0; i < 4; i++) {
        switch (directions[i]) {
            case 0: // North
                if (row > 0 && !maze[row-1][col].visited) {
                    maze[row][col].north_wall = 0;
                    maze[row-1][col].south_wall = 0;
                    generate_maze(maze, row-1, col);
                }
                break;
            case 1: // East
                if (col < MAZE_SIZE-1 && !maze[row][col+1].visited) {
                    maze[row][col].east_wall = 0;
                    maze[row][col+1].west_wall = 0;
                    generate_maze(maze, row, col+1);
                }
                break;
            case 2: // South
                if (row < MAZE_SIZE-1 && !maze[row+1][col].visited) {
                    maze[row][col].south_wall = 0;
                    maze[row+1][col].north_wall = 0;
                    generate_maze(maze, row+1, col);
                }
                break;
            case 3: // West
                if (col > 0 && !maze[row][col-1].visited) {
                    maze[row][col].west_wall = 0;
                    maze[row][col-1].east_wall = 0;
                    generate_maze(maze, row, col-1);
                }
                break;
        }
    }
}

// Function to print the maze
void print_maze(Cell maze[MAZE_SIZE][MAZE_SIZE]) {
    // Print top wall
    for (int i = 0; i < MAZE_SIZE; i++) {
        printf(" _");
    }
    printf("\n");
    
    // Loop through each row
    for (int i = 0; i < MAZE_SIZE; i++) {
        // Print west wall of current cell
        printf("|");
        
        // Loop through each cell in the row
        for (int j = 0; j < MAZE_SIZE; j++) {
            // Print bottom wall of current cell
            if (maze[i][j].south_wall) {
                printf("_");
            } else {
                printf(" ");
            }
            
            // Print east wall of current cell
            if (maze[i][j].east_wall) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    printf("Generating maze...\n");
    
    // Initialize maze
    Cell maze[MAZE_SIZE][MAZE_SIZE] = {0};
    
    // Generate maze
    generate_maze(maze, 0, 0);
    
    printf("Maze generated:\n");
    print_maze(maze);
    
    return 0;
}