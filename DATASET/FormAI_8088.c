//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>

// Define the constant variables
#define MAX_FLOOR 10
#define ELEVATOR_SPEED 500
#define DOOR_DELAY 1000

// Recursive function for the elevator simulation
void run_elevator(int current_floor, int target_floor) {
    // Base case: if the current floor is the target floor
    if (current_floor == target_floor) {
        printf("Elevator has arrived at floor %d\n", current_floor);
        printf("Doors opening...\n");
        // Wait for door open delay
        usleep(DOOR_DELAY * 1000);
        printf("Doors closing...\n");
        // Wait for door close delay
        usleep(DOOR_DELAY * 1000);
        printf("Elevator has departed from floor %d\n", current_floor);
        return;
    }
    // Recursion: move the elevator up or down to get to the desired floor
    if (current_floor < target_floor) {
        printf("Elevator is moving up to floor %d\n", current_floor + 1);
        // Wait for elevator speed delay
        usleep(ELEVATOR_SPEED * 1000);
        run_elevator(current_floor + 1, target_floor);
    } else {
        printf("Elevator is moving down to floor %d\n", current_floor - 1);
        // Wait for elevator speed delay
        usleep(ELEVATOR_SPEED * 1000);
        run_elevator(current_floor - 1, target_floor);
    }
}

int main() {
    int current_floor = 5; // Starting floor of the elevator
    int target_floor = 9; // Target floor of the elevator
    
    printf("Elevator is starting at floor %d\n", current_floor);
    
    // Run the elevator simulation
    run_elevator(current_floor, target_floor);
    
    return 0;
}