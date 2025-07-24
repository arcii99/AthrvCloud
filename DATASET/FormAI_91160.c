//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the generated maze
#define WIDTH 10
#define HEIGHT 10

// Define the wall and path characters
#define WALL '#'
#define PATH ' '

// Matrix to store the maze
char maze[WIDTH][HEIGHT];

// Function to randomly generate the maze
void generateMaze(int x, int y) {
    // Set the current cell as PATH
    maze[x][y] = PATH;

    // Define the possible directions to move
    char directions[] = {'N', 'S', 'E', 'W'};

    // Shuffle the directions array randomly
    int i, j;
    for (i = 0; i < 4; i++) {
        j = rand() % 4;
        char temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    // Move in each direction
    for (i = 0; i < 4; i++) {
        char direction = directions[i];

        // Determine the new cell coordinates
        int newX = x, newY = y;
        if (direction == 'N' && y > 0) {
            newY--;
        } else if (direction == 'S' && y < HEIGHT - 1) {
            newY++;
        } else if (direction == 'W' && x > 0) {
            newX--;
        } else if (direction == 'E' && x < WIDTH - 1) {
            newX++;
        }

        // Check if the new cell is a WALL
        if (maze[newX][newY] == WALL) {
            // Carve a PATH and recur
            if (direction == 'N') {
                maze[x][y - 1] = PATH;
            } else if (direction == 'S') {
                maze[x][y + 1] = PATH;
            } else if (direction == 'W') {
                maze[x - 1][y] = PATH;
            } else if (direction == 'E') {
                maze[x + 1][y] = PATH;
            }

            generateMaze(newX, newY);
        }
    }
}

int main() {
    // Initialize the maze with WALLs
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            maze[i][j] = WALL;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze starting from cell (0,0)
    generateMaze(0, 0);

    // Print the maze
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}