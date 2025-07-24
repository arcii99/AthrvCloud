//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the maze
#define SIZE 10

// Define the possible directions to move in
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

// Define the maximum number of steps to take before giving up
#define MAX_STEPS 50

int main() {

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create the maze as a 2D array of characters
    char maze[SIZE][SIZE];

    // Fill the maze with walls and paths
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == 0 || j == 0 || i == SIZE-1 || j == SIZE-1) {
                maze[i][j] = '#'; // The outer borders are walls
            } else if (rand() % 4 == 0) {
                maze[i][j] = '#'; // 25% of the time, randomly place walls
            } else {
                maze[i][j] = ' '; // The rest of the squares are paths
            }
        }
    }

    // Set the starting position in the maze
    int x = 1;
    int y = 1;

    // Set the current direction to move in
    int direction = UP;

    // Take steps through the maze until the end is reached or too many steps are taken
    for (int steps = 0; steps < MAX_STEPS && (x != SIZE-2 || y != SIZE-2); steps++) {

        // Set the current square to a path
        maze[x][y] = '.';

        // Look for possible directions to move in
        int possible_directions[4] = {-1, -1, -1, -1};
        int num_possible_directions = 0;
        if (maze[x-1][y] == ' ') { possible_directions[num_possible_directions++] = UP; }
        if (maze[x][y+1] == ' ') { possible_directions[num_possible_directions++] = RIGHT; }
        if (maze[x+1][y] == ' ') { possible_directions[num_possible_directions++] = DOWN; }
        if (maze[x][y-1] == ' ') { possible_directions[num_possible_directions++] = LEFT; }

        // Choose a random direction to move in
        if (num_possible_directions > 0) {
            direction = possible_directions[rand() % num_possible_directions];
        }

        // Move in the chosen direction
        switch (direction) {
            case UP:    x--; break;
            case RIGHT: y++; break;
            case DOWN:  x++; break;
            case LEFT:  y--; break;
        }
    }

    // Print out the maze
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    // Return success
    return 0;
}