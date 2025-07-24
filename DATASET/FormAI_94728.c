//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main()
{
    srand(time(NULL)); // Seed random number generator
    
    int counter = 0;    // Initialize counter to 0
    int lightState = rand() % 3; // Initialize light state to a random value
    
    printf("Traffic Light Controller\n");
    printf("------------------------\n");
    
    while(counter < 10) // Run for 10 cycles
    {
        // Display current light state
        if(lightState == RED)
            printf("RED\n");
        else if(lightState == YELLOW)
            printf("YELLOW\n");
        else if(lightState == GREEN)
            printf("GREEN\n");
        
        // Wait for a random amount of time between 1 and 3 seconds
        int delay = (rand() % 3) + 1;
        printf("Wait for %d seconds\n", delay);
        sleep(delay);
        
        // Update light state
        if(lightState == RED)
            lightState = GREEN;
        else if(lightState == YELLOW)
            lightState = RED;
        else if(lightState == GREEN)
            lightState = YELLOW;
        
        // Increment counter
        counter++;
        
        printf("------------------------\n");
    }
    
    return 0;
}