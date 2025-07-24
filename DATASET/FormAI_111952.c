//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the map size
#define MAP_WIDTH 20
#define MAP_HEIGHT 20

// Define the possible directions
typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

// Define the GPS position struct
typedef struct {
    int x;
    int y;
} GPSPosition;

// Define the GPS navigator struct
typedef struct {
    GPSPosition currentPosition;
    Direction currentDirection;
    char map[MAP_WIDTH][MAP_HEIGHT];
} GPSNavigator;

// Function to generate a random direction
Direction generateRandomDirection() {
    int randomNumber = rand() % 4;
    return (Direction)randomNumber;
}

// Function to update the GPS navigator based on the current direction
void updateGPSNavigator(GPSNavigator* navigator) {
    switch (navigator->currentDirection) {
        case NORTH:
            navigator->currentPosition.y--;
            break;
        case EAST:
            navigator->currentPosition.x++;
            break;
        case SOUTH:
            navigator->currentPosition.y++;
            break;
        case WEST:
            navigator->currentPosition.x--;
            break;
    }
}

// Function to check if the navigator has reached the destination
int hasReachedDestination(GPSNavigator* navigator, GPSPosition destination) {
    return navigator->currentPosition.x == destination.x && navigator->currentPosition.y == destination.y;
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Initialize the navigator
    GPSNavigator navigator;
    navigator.currentPosition.x = 0;
    navigator.currentPosition.y = 0;
    navigator.currentDirection = generateRandomDirection();

    // Initialize the map with random obstacles
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            int randomNumber = rand() % 10;
            if (randomNumber < 2) {
                navigator.map[i][j] = '#';
            } else {
                navigator.map[i][j] = '.';
            }
        }
    }

    // Set the destination
    GPSPosition destination;
    destination.x = rand() % MAP_WIDTH;
    destination.y = rand() % MAP_HEIGHT;
    navigator.map[destination.x][destination.y] = 'D';

    // Simulation loop
    while (!hasReachedDestination(&navigator, destination)) {
        // Update the navigator
        updateGPSNavigator(&navigator);

        // Check if the navigator has hit an obstacle
        if (navigator.map[navigator.currentPosition.x][navigator.currentPosition.y] == '#') {
            printf("ERROR: Obstacle hit!\n");
            return 1;
        }

        // Print the current map
        for (int i = 0; i < MAP_WIDTH; i++) {
            for (int j = 0; j < MAP_HEIGHT; j++) {
                if (navigator.currentPosition.x == i && navigator.currentPosition.y == j) {
                    printf("X ");
                } else {
                    printf("%c ", navigator.map[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");

        // Sleep for a short time to slow down the simulation
        sleep(1);

        // Generate a new random direction
        navigator.currentDirection = generateRandomDirection();
    }

    // Print the final map and the success message
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if (navigator.map[i][j] == '#') {
                printf("# ");
            } else if (navigator.map[i][j] == 'D') {
                printf("D ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("SUCCESS: Destination reached!\n");

    return 0;
}