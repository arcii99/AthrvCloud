//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some constants
#define MAX_DISTANCE 1000 // Maximum distance traveled
#define TURN_SMOOTHNESS 30 // How smooth turns are

int main()
{
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize variables
    int current_distance = 0;
    int current_direction = 0; // 0=north, 90=east, 180=south, 270=west
    
    // Loop until we've traveled the maximum distance
    while (current_distance < MAX_DISTANCE) {
        // Determine how far we'll travel this turn
        int distance_to_travel = rand() % 100;
        printf("Traveling %d meters...\n", distance_to_travel);
        
        // Determine if we'll turn left, right, or keep going straight
        int turn_direction = rand() % 3; // 0=left, 1=straight, 2=right
        if (turn_direction == 0) {
            printf("Turning left...\n");
            current_direction -= TURN_SMOOTHNESS;
            if (current_direction < 0) {
                current_direction += 360;
            }
        } else if (turn_direction == 2) {
            printf("Turning right...\n");
            current_direction += TURN_SMOOTHNESS;
            if (current_direction >= 360) {
                current_direction -= 360;
            }
        } else {
            printf("Going straight...\n");
        }
        
        // Update current distance traveled and direction
        current_distance += distance_to_travel;
        printf("Current distance: %d meters\n", current_distance);
        printf("Current direction: %d degrees\n", current_direction);
    }
    
    // Print final message
    printf("You have arrived at your destination!\n");
    
    return 0;
}