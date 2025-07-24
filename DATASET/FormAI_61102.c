//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototypes */
void init_map(char map[][10], int row, int col);
void print_map(char map[][10], int row, int col);
int move_vehicle(char map[][10], int row, int col, int* x, int* y, char direction);

int main()
{
    char map[10][10]; // Game map
    int x = 0; // x-coordinate of vehicle
    int y = 0; // y-coordinate of vehicle
    char direction = 'N'; // Current direction of vehicle
    int row = 10; // Number of rows in map
    int col = 10; // Number of columns in map
    int moves = 0; // Number of moves made by the vehicle

    srand(time(NULL)); // Seed random number generator

    init_map(map, row, col); // Initialize map
    print_map(map, row, col); // Print starting map

    while (moves < 20) { // While vehicle has not made 20 moves
        int result = move_vehicle(map, row, col, &x, &y, direction); // Move vehicle
        if (result == 0) { // If vehicle is blocked
            printf("Vehicle is blocked.\n");
            break; // Exit loop
        }
        else if (result == -1) { // If vehicle is out of bounds
            printf("Vehicle is out of bounds.\n");
            break; // Exit loop
        }
        moves++; // Increment move counter
        print_map(map, row, col); // Print updated map
    }

    printf("Vehicle made %d moves.\n", moves); // Print number of moves made

    return 0;
}

/**
 * Initializes the game map with obstacles and the vehicle.
 *
 * @param map The 2D array representing the game map.
 * @param row The number of rows in the game map.
 * @param col The number of columns in the game map.
 */
void init_map(char map[][10], int row, int col)
{
    for (int i = 0; i < row; i++) { // For each row
        for (int j = 0; j < col; j++) { // For each column
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                map[i][j] = '#'; // Set border of map to #
            }
            else if (rand() % 10 < 5) {
                map[i][j] = '*'; // Set random obstacles
            }
            else {
                map[i][j] = ' '; // Set empty space
            }
        }
    }

    int x = rand() % (row - 2) + 1; // Random x-coordinate for vehicle
    int y = rand() % (col - 2) + 1; // Random y-coordinate for vehicle
    map[x][y] = 'V'; // Place vehicle on map
}

/**
 * Prints the game map.
 *
 * @param map The 2D array representing the game map.
 * @param row The number of rows in the game map.
 * @param col The number of columns in the game map.
 */
void print_map(char map[][10], int row, int col)
{
    printf("\n");

    for (int i = 0; i < row; i++) { // For each row
        for (int j = 0; j < col; j++) { // For each column
            printf("%c ", map[i][j]); // Print map value
        }
        printf("\n"); // Move to next row
    }

    printf("\n");
}

/**
 * Moves the vehicle in the specified direction.
 *
 * @param map The 2D array representing the game map.
 * @param row The number of rows in the game map.
 * @param col The number of columns in the game map.
 * @param x A pointer to the x-coordinate of the vehicle.
 * @param y A pointer to the y-coordinate of the vehicle.
 * @param direction The direction to move the vehicle: 'N' for north, 'S' for south, 'E' for east, 'W' for west.
 *
 * @return 1 if the vehicle successfully moved, 0 if it is blocked, -1 if it is out of bounds.
 */
int move_vehicle(char map[][10], int row, int col, int* x, int* y, char direction)
{
    int new_x = *x; // New x-coordinate after move
    int new_y = *y; // New y-coordinate after move

    switch (direction) { // Determine new coordinates based on direction
        case 'N': new_x = *x - 1; break;
        case 'S': new_x = *x + 1; break;
        case 'E': new_y = *y + 1; break;
        case 'W': new_y = *y - 1; break;
    }

    if (new_x < 0 || new_x >= row || new_y < 0 || new_y >= col) {
        return -1; // Vehicle is out of bounds
    }

    if (map[new_x][new_y] == '*') {
        return 0; // Vehicle is blocked
    }

    map[*x][*y] = ' '; // Clear current spot
    map[new_x][new_y] = 'V'; // Move vehicle to new spot
    *x = new_x; // Update x-coordinate
    *y = new_y; // Update y-coordinate

    return 1; // Move successful
}