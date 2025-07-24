//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>

// Define the size of the grid (X by Y)
#define GRID_X 50
#define GRID_Y 20

// Define the symbol to represent the remote control vehicle
#define RC_VEHICLE_SYMBOL 'X'

// Define the symbol to represent an empty cell on the grid
#define EMPTY_CELL_SYMBOL ' '

// Define the symbol to represent the border of the grid
#define BORDER_SYMBOL '#'

// Define the structure that holds the state of the remote control vehicle
typedef struct {
    int x; // current X position
    int y; // current Y position
} rc_vehicle_t;

// Define the function to draw the grid
void draw_grid(rc_vehicle_t rc_vehicle) {
    int x, y;
    for (y = 0; y < GRID_Y; y++) {
        for (x = 0; x < GRID_X; x++) {
            if (y == 0 || y == GRID_Y-1 || x == 0 || x == GRID_X-1) {
                printf("%c", BORDER_SYMBOL);
            } else if (x == rc_vehicle.x && y == rc_vehicle.y) {
                printf("%c", RC_VEHICLE_SYMBOL);
            } else {
                printf("%c", EMPTY_CELL_SYMBOL);
            }
        }
        printf("\n");
    }
}

// Define the function to update the state of the remote control vehicle based on user input
void update_vehicle_state(char input, rc_vehicle_t* rc_vehicle) {
    switch (input) {
        case 'w':
            rc_vehicle->y--;
            break;
        case 'a':
            rc_vehicle->x--;
            break;
        case 's':
            rc_vehicle->y++;
            break;
        case 'd':
            rc_vehicle->x++;
            break;
        default:
            break;
    }
}

int main() {
    // Initialize the state of the remote control vehicle
    rc_vehicle_t rc_vehicle;
    rc_vehicle.x = GRID_X / 2;
    rc_vehicle.y = GRID_Y / 2;

    // Main game loop
    char input;
    do {
        // Clear the terminal
        printf("\033[2J\033[H");

        // Draw the grid
        draw_grid(rc_vehicle);

        // Get user input
        printf("Use WASD keys to move the remote control vehicle\n");
        scanf(" %c", &input);

        // Update the state of the remote control vehicle based on user input
        update_vehicle_state(input, &rc_vehicle);

    } while (1);

    return 0;
}