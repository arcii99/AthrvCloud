//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void generateMaze(int maze[][SIZE], int x, int y);
void printMaze(int maze[][SIZE]);

int main() {
    int maze[SIZE][SIZE];
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the maze
    generateMaze(maze, 0,0);
    
    // Print the maze
    printMaze(maze);
    
    return 0;
}

// Recursively generate the maze
void generateMaze(int maze[][SIZE], int x, int y) {
    // Set the current cell to visited
    maze[x][y] = 1;
    
    // Create an array to shuffle the directions
    int directions[4] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++) {
        int randIndex = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[randIndex];
        directions[randIndex] = temp;
    }
    
    // Loop through the directions and call the function recursively
    for(int i = 0; i < 4; i++) {
        int nextX = x;
        int nextY = y;
        switch(directions[i]) {
            case 0: // Up
                nextY--;
                break;
            case 1: // Right
                nextX++;
                break;
            case 2: // Down
                nextY++;
                break;
            case 3: // Left
                nextX--;
                break;
        }
        
        // Check if next cell is within bounds and unvisited
        if(nextX >= 0 && nextX < SIZE && nextY >= 0 && nextY < SIZE && maze[nextX][nextY] == 0) {
            // Knock down the wall between the current and next cell
            if(directions[i] == 0) {
                maze[x][y] &= ~(1 << 0); // Clear the north bit
                maze[nextX][nextY] &= ~(1 << 2); // Clear the south bit
            }
            else if(directions[i] == 1) {
                maze[x][y] &= ~(1 << 1); // Clear the east bit
                maze[nextX][nextY] &= ~(1 << 3); // Clear the west bit
            }
            else if(directions[i] == 2) {
                maze[x][y] &= ~(1 << 2); // Clear the south bit
                maze[nextX][nextY] &= ~(1 << 0); // Clear the north bit
            }
            else {
                maze[x][y] &= ~(1 << 3); // Clear the west bit
                maze[nextX][nextY] &= ~(1 << 1); // Clear the east bit
            }
            generateMaze(maze, nextX, nextY);
        }
    }
}

// Print the maze
void printMaze(int maze[][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("+");
            printf((maze[i][j] & (1 << 0)) ? "---" : "   ");
        }
        printf("+\n");
        for(int j = 0; j < SIZE; j++) {
            printf((maze[i][j] & (1 << 3)) ? "|" : " ");
            printf("   ");
        }
        printf("|\n");
    }
    for(int j = 0; j < SIZE; j++) {
        printf("+---");
    }
    printf("+\n");
}