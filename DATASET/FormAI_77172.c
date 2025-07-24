//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: random
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define constants for the size of the maze
    const int WIDTH = 20;
    const int HEIGHT = 10;

    // Define variables for the entrance and exit positions
    int entrance_x = rand() % WIDTH;
    int entrance_y = 0;
    int exit_x = rand() % WIDTH;
    int exit_y = HEIGHT - 1;

    // Define an array to hold the maze
    int maze[HEIGHT][WIDTH];

    // Initialize the maze to all walls (represented by 1s)
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[y][x] = 1;
        }
    }

    // Set the entrance and exit positions
    maze[entrance_y][entrance_x] = 0;
    maze[exit_y][exit_x] = 0;

    // Generate the maze
    int x = 2 * (rand() % (WIDTH / 2)) + 1; // Start at an odd x-coordinate
    int y = 2 * (rand() % (HEIGHT / 2)) + 1; // Start at an odd y-coordinate
    maze[y][x] = 0; // Clear the starting position

    while (1) {
        // Move in a random direction
        int move = rand() % 4;
        switch (move) {
            case 0: // Up
                if (y > 1 && maze[y-2][x] == 1) {
                    maze[y-1][x] = 0;
                    maze[y-2][x] = 0;
                    y -= 2;
                }
                break;
            case 1: // Right
                if (x < WIDTH - 2 && maze[y][x+2] == 1) {
                    maze[y][x+1] = 0;
                    maze[y][x+2] = 0;
                    x += 2;
                }
                break;
            case 2: // Down
                if (y < HEIGHT - 2 && maze[y+2][x] == 1) {
                    maze[y+1][x] = 0;
                    maze[y+2][x] = 0;
                    y += 2;
                }
                break;
            case 3: // Left
                if (x > 1 && maze[y][x-2] == 1) {
                    maze[y][x-1] = 0;
                    maze[y][x-2] = 0;
                    x -= 2;
                }
                break;
        }

        // Check if we've reached the exit
        if (x == exit_x && y == exit_y) {
            break;
        }
    }

    // Print the maze
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == entrance_x && y == entrance_y) {
                printf("E"); // Entrance
            } else if (x == exit_x && y == exit_y) {
                printf("X"); // Exit
            } else if (maze[y][x] == 0) {
                printf(" "); // Empty space
            } else {
                printf("#"); // Wall
            }
        }
        printf("\n");
    }

    return 0;
}