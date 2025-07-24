//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MAX_TURNS 20
#define MAX_DISTANCE 1000

int main() {
    int speed, direction, distance, turns;
    
    srand(time(NULL));
    
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Your vehicle is ready for action. Let's begin!\n\n");
    
    for (turns = 1; turns <= MAX_TURNS; turns++) {
        
        speed = rand() % MAX_SPEED;
        direction = (rand() % 2 == 0) ? 1 : -1; // Randomize direction
        distance = rand() % MAX_DISTANCE;
        
        printf("TURN %d\n", turns);
        printf("Speed: %d\n", speed);
        printf("Direction: %s\n", (direction == 1) ? "FORWARD" : "BACKWARD");
        printf("Distance: %d\n", distance);
        
        // Simulate movement
        for (int i = 1; i <= distance; i++) {
            printf("Vehicle has moved %d meters.\n", i);
        }
        
        printf("Vehicle has reached destination.\n");
        printf("--------------------------------\n");
    }
    
    printf("Simulation complete. Thanks for participating!\n");
    
    return 0;
}