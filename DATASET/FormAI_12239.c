//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define GRID_SIZE 20
#define MAX_VEHICLES 5
#define NUM_MOVES 4
#define MOVE_RANGE 5

// Directions
enum Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

// Vehicle struct
typedef struct {
    int x;
    int y;
    enum Direction direction;
} Vehicle;

// Function prototypes
void seedRandom();
int getRandomInt(int max);
void initVehicles(Vehicle *vehicles);
void printGrid(Vehicle *vehicles, int playerX, int playerY);
int getVehicleIndex(Vehicle *vehicles, int x, int y);
void move(Vehicle *vehicle, int distance);
void moveLeft(Vehicle *vehicle, int distance);
void moveRight(Vehicle *vehicle, int distance);
void moveUp(Vehicle *vehicle, int distance);
void moveDown(Vehicle *vehicle, int distance);

// Main function
int main() {
    seedRandom();

    // Initialize player position
    int playerX = getRandomInt(GRID_SIZE);
    int playerY = getRandomInt(GRID_SIZE);

    // Initialize vehicle positions
    Vehicle vehicles[MAX_VEHICLES];
    initVehicles(vehicles);

    // Game loop
    while (1) {
        // Print grid with player and vehicles
        printGrid(vehicles, playerX, playerY);

        // Get user input
        int input;
        printf("Enter a direction to move (0 for north, 1 for south, 2 for east, 3 for west): ");
        scanf("%d", &input);

        // Move player in chosen direction
        switch (input) {
            case 0:
                moveUp(&playerY, 1);
                break;
            case 1:
                moveDown(&playerY, 1);
                break;
            case 2:
                moveRight(&playerX, 1);
                break;
            case 3:
                moveLeft(&playerX, 1);
                break;
            default:
                printf("Invalid input!\n");
                continue;
        }

        // Check if player has collided with a vehicle
        int vehicleIndex = getVehicleIndex(vehicles, playerX, playerY);
        if (vehicleIndex != -1) {
            printf("You crashed into a vehicle!\n");
            break;
        }

        // Move all vehicles in random directions
        for (int i = 0; i < MAX_VEHICLES; i++) {
            Vehicle *vehicle = &vehicles[i];
            int moveDirection = getRandomInt(NUM_MOVES);
            int moveDistance = getRandomInt(MOVE_RANGE) + 1;
            switch (moveDirection) {
                case 0:
                    moveUp(vehicle, moveDistance);
                    break;
                case 1:
                    moveDown(vehicle, moveDistance);
                    break;
                case 2:
                    moveRight(vehicle, moveDistance);
                    break;
                case 3:
                    moveLeft(vehicle, moveDistance);
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}

// Seed random number generator with current time
void seedRandom() {
    srand(time(NULL));
}

// Get a random integer between 0 (inclusive) and max (exclusive)
int getRandomInt(int max) {
    return rand() % max;
}

// Initialize vehicle positions with random coordinates and directions
void initVehicles(Vehicle *vehicles) {
    for (int i = 0; i < MAX_VEHICLES; i++) {
        vehicles[i].x = getRandomInt(GRID_SIZE);
        vehicles[i].y = getRandomInt(GRID_SIZE);
        vehicles[i].direction = getRandomInt(NUM_MOVES);
    }
}

// Print grid with player and vehicle positions
void printGrid(Vehicle *vehicles, int playerX, int playerY) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (x == playerX && y == playerY) {
                printf("@ ");
            } else if (getVehicleIndex(vehicles, x, y) != -1) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Get the index of the vehicle that is at the given coordinates, or -1 if there is no vehicle there
int getVehicleIndex(Vehicle *vehicles, int x, int y) {
    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (vehicles[i].x == x && vehicles[i].y == y) {
            return i;
        }
    }
    return -1;
}

// Move the given vehicle up by the given distance
void moveUp(Vehicle *vehicle, int distance) {
    move(vehicle, -distance);
}

// Move the given vehicle down by the given distance
void moveDown(Vehicle *vehicle, int distance) {
    move(vehicle, distance);
}

// Move the given vehicle right by the given distance
void moveRight(Vehicle *vehicle, int distance) {
    vehicle->direction = EAST;
    move(vehicle, distance);
}

// Move the given vehicle left by the given distance
void moveLeft(Vehicle *vehicle, int distance) {
    vehicle->direction = WEST;
    move(vehicle, -distance);
}

// Move the given vehicle in its current direction by the given distance
void move(Vehicle *vehicle, int distance) {
    switch (vehicle->direction) {
        case NORTH:
            vehicle->y += distance;
            break;
        case SOUTH:
            vehicle->y -= distance;
            break;
        case EAST:
            vehicle->x += distance;
            break;
        case WEST:
            vehicle->x -= distance;
            break;
        default:
            break;
    }
}