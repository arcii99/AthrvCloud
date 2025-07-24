//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define constants for vehicle movements
#define MOVE_FORWARD 1
#define MOVE_BACKWARD -1
#define TURN_LEFT -1
#define TURN_RIGHT 1

int main() {
    srand(time(NULL)); // Initialize random seed
    int distance = 0; // Initialize distance traveled
    int battery = 100; // Initialize battery level
    int direction = MOVE_FORWARD; // Start by moving forward
    int steering = 0; // Initialize steering angle

    // Print startup message and initial status
    printf("Initializing Remote Control Vehicle Simulation in Cyberpunks World...\n");
    printf("Distance traveled: %d meters\nBattery level: %d%%\nDirection: Forward\nSteering angle: %d degrees\n",
           distance, battery, steering);
    
    // Main game loop
    while(battery > 0) {
        // Simulate vehicle movements
        int move_distance = rand() % 10 + 5;
        distance += direction * move_distance;
        battery -= move_distance;

        // Simulate steering angle changes
        int steer_change = rand() % 15 - 7;
        if(abs(steering + steer_change) <= 45) {
            steering += steer_change;
        }
        
        // Print updated status
        printf("Moving %d meters %s, Steering angle changed to %d degrees\n", move_distance,
               direction == MOVE_FORWARD ? "forward" : "backward", steering);
        printf("Distance traveled: %d meters\nBattery level: %d%%\nDirection: %s\nSteering angle: %d degrees\n",
               distance, battery, direction == MOVE_FORWARD ? "Forward" : "Backward", steering);
        
        // Simulate turning around
        if(distance >= 100 && direction == MOVE_FORWARD) {
            printf("Reached 100 meters! Turning around...\n");
            direction = MOVE_BACKWARD;
            sleep(2); // Pause for dramatic effect
        }
        
        // Simulate running out of battery
        if(battery <= 0) {
            printf("Battery depleted! Game over.\n");
        }
        
        // Simulate collision
        if(distance >= 150 && rand() % 2 == 0) {
            printf("Collision detected! Game over.\n");
            break;
        }
    }
    
    return 0;
}