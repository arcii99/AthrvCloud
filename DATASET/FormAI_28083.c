//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Start the simulation loop
    while (1) {
        // Generate a random number between 1 and 4
        int light = rand() % 4 + 1;
        
        // Set the traffic lights based on the random number
        switch (light) {
            case 1:
                printf("North-South traffic light is green.\n");
                printf("East-West traffic light is red.\n");
                break;
            case 2:
                printf("North-South traffic light is red.\n");
                printf("East-West traffic light is green.\n");
                break;
            case 3:
                printf("North-South traffic light is yellow.\n");
                printf("East-West traffic light is red.\n");
                break;
            case 4:
                printf("North-South traffic light is red.\n");
                printf("East-West traffic light is yellow.\n");
                break;
        }
        
        // Pause for a few seconds before repeating the loop
        sleep(3);
    }
    
    return 0;
}