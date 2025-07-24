//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define macros for the maximum values of the X and Y coordinates
#define MAX_X 100
#define MAX_Y 100

// Define a struct for the vehicle
typedef struct {
    int x;
    int y;
} Vehicle;

int main() {
    // Initialize the vehicle's starting position to the center of the screen
    Vehicle vehicle = {MAX_X / 2, MAX_Y / 2};
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Start the simulation loop
    while (1) {
        // Generate a random number between -1 and 1 for the X and Y values
        float xMovement = (float) (rand() % 3) - 1; // -1, 0, 1
        float yMovement = (float) (rand() % 3) - 1; // -1, 0, 1
        
        // Update the vehicle's position based on the random movement
        vehicle.x += xMovement;
        vehicle.y += yMovement;
        
        // Constrain the vehicle's position to the screen bounds
        if (vehicle.x < 0) {
            vehicle.x = 0;
        } else if (vehicle.x > MAX_X) {
            vehicle.x = MAX_X;
        }
        if (vehicle.y < 0) {
            vehicle.y = 0;
        } else if (vehicle.y > MAX_Y) {
            vehicle.y = MAX_Y;
        }
        
        // Print the vehicle's current position to the console
        printf("Vehicle Position: (%d, %d)\n", vehicle.x, vehicle.y);
        
        // Wait 1 second before updating the position again
        sleep(1);
    }
    
    return 0;
}