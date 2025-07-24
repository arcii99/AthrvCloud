//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROW 15
#define COL 20

void generateMaze(int maze[ROW][COL]);
void printMaze(int maze[ROW][COL]);

int main() {
    int maze[ROW][COL];
    srand(time(NULL)); // Seed random number generator
    
    generateMaze(maze);
    printMaze(maze);
    
    return 0;
}

void generateMaze(int maze[ROW][COL]) {
    // Initialize maze to all walls
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            maze[i][j] = 1;
        }
    }
    
    int x = rand() % ROW;
    int y = rand() % COL;
    maze[x][y] = 0; // Set starting position
    
    int dx[4] = {0, 1, 0, -1}; // Array of moves in x direction
    int dy[4] = {1, 0, -1, 0}; // Array of moves in y direction
    int dirs[4] = {0, 1, 2, 3}; // Array of direction options
    
    // Shuffle direction options
    for (int i = 0; i < 4; i++) {
        int temp = dirs[i];
        int randIndex = rand() % 4;
        dirs[i] = dirs[randIndex];
        dirs[randIndex] = temp;
    }
    
    // Build maze
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[dirs[i]];
        int newY = y + dy[dirs[i]];
        
        if (newX >= 0 && newX < ROW && newY >= 0 && newY < COL && maze[newX][newY] == 1) {
            maze[x + dx[dirs[i]] / 2][y + dy[dirs[i]] / 2] = 0;
            maze[newX][newY] = 0;
            x = newX;
            y = newY;
            generateMaze(maze); // Recursive call to generate rest of maze
        }
    }
}

void printMaze(int maze[ROW][COL]) {
    printf(" ");
    
    // Print the top border
    for (int i = 0; i < COL; i++) {
        printf("_");
    }
    
    printf("\n");
    
    for (int i = 0; i < ROW; i++) {
        printf("|"); // Print left border for each row
        
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        
        printf("|\n"); // Print right border for each row
    }
    
    printf(" ");
    
    // Print the bottom border
    for (int i = 0; i < COL; i++) {
        printf("_");
    }
    
    printf("\n");
}