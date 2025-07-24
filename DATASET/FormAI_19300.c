//FormAI DATASET v1.0 Category: Robot movement control ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for moving directions
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Define the boundaries of the map
#define MAP_TOP 0
#define MAP_BOTTOM 9
#define MAP_LEFT 0
#define MAP_RIGHT 9

// Define the initial position of the robot
#define INIT_POS_ROW 5
#define INIT_POS_COL 5

// Define the symbol used to represent the robot on the map
#define ROBOT_SYMBOL 'R'

// Define the symbol used to represent empty spaces on the map
#define EMPTY_SYMBOL ' '

void print_map(char map[][MAP_RIGHT+1], int robot_row, int robot_col) {
    int i, j;
    for (i = MAP_TOP; i <= MAP_BOTTOM; i++) {
        for (j = MAP_LEFT; j <= MAP_RIGHT; j++) {
            if (i == robot_row && j == robot_col) {
                printf("%c", ROBOT_SYMBOL);
            } else {
                printf("%c", map[i][j]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main(void) {
    char map[MAP_BOTTOM+1][MAP_RIGHT+1]; // Declare the map array
    int current_row = INIT_POS_ROW; // Set the initial row of the robot
    int current_col = INIT_POS_COL; // Set the initial column of the robot
    int direction; // Variable to store the direction of movement
    int steps; // Variable to store the number of steps to move
    int i, j;

    // Initialize the map with empty spaces
    for (i = MAP_TOP; i <= MAP_BOTTOM; i++) {
        for (j = MAP_LEFT; j <= MAP_RIGHT; j++) {
            map[i][j] = EMPTY_SYMBOL;
        }
    }

    // Set the initial position of the robot on the map
    map[current_row][current_col] = ROBOT_SYMBOL;

    // Print the initial map
    printf("INITIAL MAP:\n");
    print_map(map, current_row, current_col);

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop to move the robot randomly
    for (i = 0; i < 10; i++) {
        // Generate a random direction of movement
        direction = rand() % 4 + 1;

        // Generate a random number of steps to move
        steps = rand() % 3 + 1;

        // Move the robot in the chosen direction
        switch (direction) {
            case UP:
                if (current_row - steps >= MAP_TOP) {
                    current_row -= steps;
                } else {
                    current_row = MAP_TOP;
                }
                break;
            case DOWN:
                if (current_row + steps <= MAP_BOTTOM) {
                    current_row += steps;
                } else {
                    current_row = MAP_BOTTOM;
                }
                break;
            case LEFT:
                if (current_col - steps >= MAP_LEFT) {
                    current_col -= steps;
                } else {
                    current_col = MAP_LEFT;
                }
                break;
            case RIGHT:
                if (current_col + steps <= MAP_RIGHT) {
                    current_col += steps;
                } else {
                    current_col = MAP_RIGHT;
                }
                break;
        }

        // Update the position of the robot on the map
        map[current_row][current_col] = ROBOT_SYMBOL;

        // Print the updated map
        printf("MAP AFTER %dth MOVE:\n", i+1);
        print_map(map, current_row, current_col);

        // Reset the previous position of the robot on the map to an empty space
        map[current_row][current_col] = EMPTY_SYMBOL;
    }

    return 0;
}