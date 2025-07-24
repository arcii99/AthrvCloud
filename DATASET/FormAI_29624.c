//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum acceleration rate and the maximum speed of the vehicle
#define MAX_ACCELERATION 10
#define MAX_SPEED 100

// Define the size of the arena in which the vehicle will move
#define ARENA_WIDTH 50
#define ARENA_HEIGHT 30

// Define the symbols to represent different parts of the arena
#define EMPTY_CELL '.'
#define VEHICLE_CELL 'X'

// Define the possible commands that the user can send to the vehicle
#define COMMAND_FORWARD 'F'
#define COMMAND_BACKWARD 'B'
#define COMMAND_LEFT 'L'
#define COMMAND_RIGHT 'R'

// Define the structure of the vehicle
struct Vehicle {
    int x, y;   // current coordinates
    int vx, vy; // current velocity
};

// Define the function to print the arena
void printArena(char arena[][ARENA_WIDTH]) {
    for (int y = 0; y < ARENA_HEIGHT; y++) {
        for (int x = 0; x < ARENA_WIDTH; x++) {
            printf("%c", arena[y][x]);
        }
        printf("\n");
    }
}

// Define the function to move the vehicle according to the given command
void moveVehicle(struct Vehicle* vehicle, char command) {
    switch (command) {
        case COMMAND_FORWARD:
            vehicle->vx += rand() % MAX_ACCELERATION;
            vehicle->vy += rand() % MAX_ACCELERATION;
            break;
        case COMMAND_BACKWARD:
            vehicle->vx -= rand() % MAX_ACCELERATION;
            vehicle->vy -= rand() % MAX_ACCELERATION;
            break;
        case COMMAND_LEFT:
            vehicle->vx -= rand() % MAX_SPEED;
            break;
        case COMMAND_RIGHT:
            vehicle->vx += rand() % MAX_SPEED;
            break;
        default:
            printf("Invalid command: %c\n", command);
    }
}

int main() {
    // Create a new vehicle
    struct Vehicle vehicle = {
        .x = rand() % ARENA_WIDTH,
        .y = rand() % ARENA_HEIGHT,
        .vx = 0,
        .vy = 0
    };

    // Create the arena and initialize it to empty cells
    char arena[ARENA_HEIGHT][ARENA_WIDTH];
    memset(arena, EMPTY_CELL, ARENA_HEIGHT * ARENA_WIDTH);

    // Set the cell where the vehicle is located to the vehicle symbol
    arena[vehicle.y][vehicle.x] = VEHICLE_CELL;

    // Print the initial state of the arena and the vehicle
    printArena(arena);
    printf("Vehicle is at (%d, %d) with velocity (%d, %d)\n", vehicle.x, vehicle.y, vehicle.vx, vehicle.vy);

    // Loop to receive and execute commands from the user
    while (1) {
        char command;
        printf("Enter a command: ");
        scanf(" %c", &command);

        moveVehicle(&vehicle, command);

        // Update the vehicle's position according to its velocity
        vehicle.x += vehicle.vx;
        vehicle.y += vehicle.vy;

        // Check if the vehicle hit the boundaries of the arena
        if (vehicle.x < 0) {
            vehicle.x = 0;
            vehicle.vx = -vehicle.vx;
        } else if (vehicle.x >= ARENA_WIDTH) {
            vehicle.x = ARENA_WIDTH - 1;
            vehicle.vx = -vehicle.vx;
        }
        if (vehicle.y < 0) {
            vehicle.y = 0;
            vehicle.vy = -vehicle.vy;
        } else if (vehicle.y >= ARENA_HEIGHT) {
            vehicle.y = ARENA_HEIGHT - 1;
            vehicle.vy = -vehicle.vy;
        }

        // Update the arena to reflect the new position of the vehicle
        memset(arena, EMPTY_CELL, ARENA_HEIGHT * ARENA_WIDTH);
        arena[vehicle.y][vehicle.x] = VEHICLE_CELL;

        // Print the updated state of the arena and the vehicle
        printArena(arena);
        printf("Vehicle is at (%d, %d) with velocity (%d, %d)\n", vehicle.x, vehicle.y, vehicle.vx, vehicle.vy);
    }

    return 0;
}