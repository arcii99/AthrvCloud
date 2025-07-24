//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>

// Defining the recursive function for remote control vehicle simulation
void rcVehicleSimulation(int position, int direction, int moveCount) {
    // Base case
    if (moveCount == 0) {
        printf("\nSimulation Over!\n");
        return;
    }
    
    // Recursive cases
    
    // Move forward
    if (direction == 0) {
        position++;
        printf("Moved Forward to position %d\n", position);
    }
    // Move backward
    else if (direction == 1) {
        position--;
        printf("Moved Backward to position %d\n", position);
    }
    
    // Change direction after every 5 moves
    if (moveCount % 5 == 0) {
        direction = (direction + 1) % 2;
        printf("Changed Direction, now facing %s\n", (direction == 0) ? "East" : "West");
    }
    
    // Recursive call
    rcVehicleSimulation(position, direction, moveCount - 1);
}

int main() {
    int position = 0; // Initial position of the vehicle
    int direction = 0; // Initial direction of the vehicle (0 for East, 1 for West)
    int moveCount = 10; // Number of moves for simulation
    
    printf("Starting Remote Control Vehicle Simulation\n");
    printf("Initial Position: %d\n", position);
    printf("Initial Direction: %s\n", (direction == 0) ? "East" : "West");
    rcVehicleSimulation(position, direction, moveCount); // Calling the recursive function
    return 0;
}