//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants for vehicle size and movement
#define VEHICLE_WIDTH 4
#define VEHICLE_HEIGHT 2
#define MAX_SPEED 10

// Struct to represent the vehicle
typedef struct {
    int x, y; // Position
    int speed; // Current speed
    int direction; // Current direction (0-3, corresponding to north, east, south, west)
} Vehicle;

// Function to draw the vehicle at its current position
void drawVehicle(Vehicle v) {
    printf("\033[%d;%dH", v.y, v.x); // Move cursor to vehicle position
    printf("  /\\\n"); // Draw vehicle
    printf(" /  \\\n");
}

// Function to move the vehicle based on its current speed and direction
void moveVehicle(Vehicle *v) {
    switch (v->direction) {
        case 0: // North
            v->y -= v->speed;
            break;
        case 1: // East
            v->x += v->speed;
            break;
        case 2: // South
            v->y += v->speed;
            break;
        case 3: // West
            v->x -= v->speed;
            break;
    }
}

int main() {
    // Initialize vehicle at center of screen
    Vehicle vehicle = {
        .x = 40 - (VEHICLE_WIDTH / 2),
        .y = 12 - (VEHICLE_HEIGHT / 2),
        .speed = 0,
        .direction = 0
    };

    // Main game loop
    while (true) {
        // Process user input
        char input = getchar();
        switch (input) {
            case 'w': // Increase speed
                if (vehicle.speed < MAX_SPEED) {
                    vehicle.speed++;
                }
                break;
            case 's': // Decrease speed
                if (vehicle.speed > 0) {
                    vehicle.speed--;
                }
                break;
            case 'a': // Turn left
                vehicle.direction--;
                if (vehicle.direction < 0) {
                    vehicle.direction = 3;
                }
                break;
            case 'd': // Turn right
                vehicle.direction++;
                if (vehicle.direction > 3) {
                    vehicle.direction = 0;
                }
                break;
        }

        // Move vehicle based on speed and direction
        moveVehicle(&vehicle);

        // Clear screen and draw vehicle
        printf("\033[2J"); // ANSI escape code to clear screen
        drawVehicle(vehicle);
        fflush(stdout); // Flush output buffer to ensure screen clears before next frame

        // Wait a short amount of time to control frame rate
        usleep(100000); // Sleep for 100,000 microseconds (0.1 seconds)
    }

    return 0;
}