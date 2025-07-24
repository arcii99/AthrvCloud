//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

int maze[ROWS][COLUMNS];

void generateMaze();

int main() {
    srand(time(NULL));
    generateMaze();
    
    // Print the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze() {
    // Initialize the maze, all cells are set to 0
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            maze[i][j] = 0;
        }
    }
    
    // Choose a random starting point
    int startX = rand() % ROWS;
    int startY = rand() % COLUMNS;
    
    // Mark the starting point as visited
    maze[startX][startY] = 1;
    
    // Generate the maze
    int x = startX;
    int y = startY;
    while (1) {
        int direction = rand() % 4;
        switch (direction) {
            case 0: // Up
                if (y > 0 && maze[x][y-1] == 0) {
                    maze[x][y-1] = maze[x][y] + 1;
                    y--;
                }
                break;
            case 1: // Down
                if (y < COLUMNS-1 && maze[x][y+1] == 0) {
                    maze[x][y+1] = maze[x][y] + 1;
                    y++;
                }
                break;
            case 2: // Left
                if (x > 0 && maze[x-1][y] == 0) {
                    maze[x-1][y] = maze[x][y] + 1;
                    x--;
                }
                break;
            case 3: // Right
                if (x < ROWS-1 && maze[x+1][y] == 0) {
                    maze[x+1][y] = maze[x][y] + 1;
                    x++;
                }
                break;
        }
        
        // If all cells are visited, break the loop
        if (maze[0][0] && maze[ROWS-1][COLUMNS-1]) {
            break;
        }
    }
}