//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLOORS 10
#define MAX_OCCUPANCY 5

// Function to move the elevator up
void move_up(int *current_floor) {
    printf("Elevator moving up from floor %d to floor %d\n", *current_floor, *current_floor + 1);
    *current_floor += 1;
}

// Function to move the elevator down
void move_down(int *current_floor) {
    printf("Elevator moving down from floor %d to floor %d\n", *current_floor, *current_floor - 1);
    *current_floor -= 1;
}

int main() {
    int current_floor = 1;
    int direction = 1; // 1 for up, -1 for down
    int occupants = 0;
    bool button_pressed[FLOORS] = {false};

    printf("Welcome to the Elevator Simulation!\n\n");

    while (true) {
        printf("Current floor: %d\n", current_floor);

        // Check if anyone wants to get off
        if (button_pressed[current_floor - 1]) {
            occupants -= 1;
            printf("Occupant exiting elevator on floor %d\n", current_floor);
            button_pressed[current_floor - 1] = false;
        }

        // Check if anyone wants to get on
        if (occupants < MAX_OCCUPANCY && button_pressed[current_floor - 1]) {
            occupants += 1;
            printf("Occupant entering elevator on floor %d\n", current_floor);
        }

        // Check if all destinations have been reached
        bool all_destinations_reached = true;
        for (int i = 0; i < FLOORS; i++) {
            if (button_pressed[i]) {
                all_destinations_reached = false;
            }
        }

        // If all destinations have been reached, stop simulation
        if (all_destinations_reached) {
            printf("All destinations have been reached! Simulation ending.\n");
            break;
        }

        // Change direction if at top or bottom floor
        if (current_floor == FLOORS) {
            direction = -1;
        } else if (current_floor == 1) {
            direction = 1;
        }

        // Move the elevator in the current direction
        if (direction == 1) {
            move_up(&current_floor);
        } else {
            move_down(&current_floor);
        }
    }

    return 0;
}