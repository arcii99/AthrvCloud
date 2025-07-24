//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10 // Width of the maze
#define HEIGHT 10 // Height of the maze

int maze[WIDTH][HEIGHT]; // Maze array

// Function to generate the maze
void generateMaze(int x, int y)
{
    maze[x][y] = 1; // Set current cell as visited
    int directions[] = {0, 1, 2, 3}; // Array of possible directions
    int temp;

    // Shuffle the directions
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    // Loop through the directions and try to move in each
    for (int i = 0; i < 4; i++) {
        switch(directions[i]) {
            case 0: // Up
                if (y - 1 > 0 && maze[x][y-1] == 0) {
                    maze[x][y-1] = 1;
                    generateMaze(x, y-1);
                }
                break;
            case 1: // Right
                if (x + 1 < WIDTH && maze[x+1][y] == 0) {
                    maze[x+1][y] = 1;
                    generateMaze(x+1, y);
                }
                break;
            case 2: // Down
                if (y + 1 < HEIGHT && maze[x][y+1] == 0) {
                    maze[x][y+1] = 1;
                    generateMaze(x, y+1);
                }
                break;
            case 3: // Left
                if (x - 1 > 0 && maze[x-1][y] == 0) {
                    maze[x-1][y] = 1;
                    generateMaze(x-1, y);
                }
                break;
        }
    }
}

int main()
{
    srand(time(NULL)); // Seed the random number generator

    // Initialize the maze to all 0s
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[x][y] = 0;
        }
    }

    // Generate the maze
    generateMaze(0, 0);

    // Print the maze
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[x][y] == 0) {
                printf("##");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}