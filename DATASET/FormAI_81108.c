//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define traffic light colors
#define GREEN 1
#define YELLOW 2
#define RED 3

// Define traffic light states
#define EAST_WEST_GREEN 1
#define EAST_WEST_YELLOW 2
#define NORTH_SOUTH_GREEN 3
#define NORTH_SOUTH_YELLOW 4

int main() {
    srand(time(NULL)); // Seed random number generator
    
    int currentState = EAST_WEST_GREEN; // Start with east-west green
    
    while(1) { // Loop forever
        
        // Print current state
        printf("\n====================\n");
        printf("    TRAFFIC LIGHT\n");
        printf("--------------------\n");
        printf("Current state: ");
        switch(currentState) {
            case EAST_WEST_GREEN:
                printf("East-West green\n");
                break;
            case EAST_WEST_YELLOW:
                printf("East-West yellow\n");
                break;
            case NORTH_SOUTH_GREEN:
                printf("North-South green\n");
                break;
            case NORTH_SOUTH_YELLOW:
                printf("North-South yellow\n");
                break;
        }
        
        // Wait some time before transitioning to next state
        int waitTime = rand() % 10 + 1; // Random number between 1 and 10
        printf("Waiting %d seconds...\n", waitTime);
        sleep(waitTime);
        
        // Transition to next state based on current state
        switch(currentState) {
            case EAST_WEST_GREEN:
                currentState = EAST_WEST_YELLOW;
                break;
            case EAST_WEST_YELLOW:
                currentState = NORTH_SOUTH_GREEN;
                break;
            case NORTH_SOUTH_GREEN:
                currentState = NORTH_SOUTH_YELLOW;
                break;
            case NORTH_SOUTH_YELLOW:
                currentState = EAST_WEST_GREEN;
                break;
        }
    }
    
    return 0;
}