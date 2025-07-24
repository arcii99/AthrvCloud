//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 15

void generateMaze(int maze[HEIGHT][WIDTH]);
void printMaze(int maze[HEIGHT][WIDTH]);

int main() {
    int maze[HEIGHT][WIDTH];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}

void generateMaze(int maze[HEIGHT][WIDTH]) {
    srand(time(NULL));
    
    // Fill the maze with walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Set the start and end points
    maze[0][1] = 0;
    maze[HEIGHT - 1][WIDTH - 2] = 0;
    
    // Generate the maze
    int currentX = 1;
    int currentY = 0;
    maze[currentY][currentX] = 0;
    
    while (currentX != WIDTH - 2 || currentY != HEIGHT - 1) {
        int direction = rand() % 4;
        
        switch (direction) {
            case 0: // Move up
                if (currentY > 0 && maze[currentY - 1][currentX] == 1) {
                    maze[currentY - 1][currentX] = 0;
                    currentY--;
                }
                break;
                
            case 1: // Move down
                if (currentY < HEIGHT - 1 && maze[currentY + 1][currentX] == 1) {
                    maze[currentY + 1][currentX] = 0;
                    currentY++;
                }
                break;
                
            case 2: // Move left
                if (currentX > 0 && maze[currentY][currentX - 1] == 1) {
                    maze[currentY][currentX - 1] = 0;
                    currentX--;
                }
                break;
                
            case 3: // Move right
                if (currentX < WIDTH - 1 && maze[currentY][currentX + 1] == 1) {
                    maze[currentY][currentX + 1] = 0;
                    currentX++;
                }
                break;
        }
    }
}

void printMaze(int maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("###");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}