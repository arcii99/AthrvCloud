//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to generate random maze
void generateMaze(int maze[][COLS]) {
    int i, j;
    srand(time(NULL)); // Seed for random number generator
    
    // Initialize maze with walls
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Generate path through maze
    int x = 0;
    int y = 0;
    maze[x][y] = 0; // Start at top left corner
    
    while(x!=ROWS-1 || y!=COLS-1) {
        int direction = rand() % 4; // Randomly choose direction
        
        switch(direction) {
            case 0: // Up
                if(x>0 && maze[x-1][y]==1) { // Check if space is available
                    maze[x-1][y] = 0;
                    x--;
                }
                break;
                
            case 1: // Down
                if(x<ROWS-1 && maze[x+1][y]==1) { // Check if space is available
                    maze[x+1][y] = 0;
                    x++;
                }
                break;
                
            case 2: // Left
                if(y>0 && maze[x][y-1]==1) { // Check if space is available
                    maze[x][y-1] = 0;
                    y--;
                }
                break;
                
            case 3: // Right
                if(y<COLS-1 && maze[x][y+1]==1) { // Check if space is available
                    maze[x][y+1] = 0;
                    y++;
                }
                break;
        }   
    }
}

// Function to print maze
void printMaze(int maze[][COLS]) {
    int i, j;
    printf("Maze:\n");
    
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to find route through maze
void findRoute(int maze[][COLS], int x, int y, int steps) {
    maze[x][y] = steps;
    
    if(x == ROWS-1 && y == COLS-1) { // Base case: reached bottom right corner
        printf("Found exit in %d steps\n", steps);
        return;
    }
    
    if(x>0 && maze[x-1][y]==0) { // Check if up direction is available
        findRoute(maze, x-1, y, steps+1);
    }
    if(x<ROWS-1 && maze[x+1][y]==0) { // Check if down direction is available
        findRoute(maze, x+1, y, steps+1);
    }
    if(y>0 && maze[x][y-1]==0) { // Check if left direction is available
        findRoute(maze, x, y-1, steps+1);
    }
    if(y<COLS-1 && maze[x][y+1]==0) { // Check if right direction is available
        findRoute(maze, x, y+1, steps+1);
    }
}

int main() {
    int maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    
    printf("Finding route...\n");
    findRoute(maze, 0, 0, 0);
    
    return 0;
}