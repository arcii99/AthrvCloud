//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define INTERVAL 10 // The duration of each light phase in seconds

int main()
{
    // Initialize random seed
    srand(time(NULL));
    
    int state = GREEN;
    int remaining_time = INTERVAL;
    
    while(1) // Loop infinitely
    {
        // Display current state
        switch(state)
        {
            case RED:
                printf("RED light is ON for %d seconds.\n", remaining_time);
                break;
            case YELLOW:
                printf("YELLOW light is ON for %d seconds.\n", remaining_time);
                break;
            case GREEN:
                printf("GREEN light is ON for %d seconds.\n", remaining_time);
                break;
        }
        
        // Check if the current phase has ended
        if(remaining_time <= 0)
        {
            // Switch to the next phase
            switch(state)
            {
                case RED:
                    state = GREEN;
                    break;
                case YELLOW:
                    state = RED;
                    break;
                case GREEN:
                    state = YELLOW;
                    break;
            }
            
            // Reset remaining time for new phase
            remaining_time = INTERVAL;
        }
        
        // Sleep for one second
        sleep(1);
        
        // Decrement remaining time
        remaining_time--;
        
        // Randomly generate a car every 10 seconds when green light is on
        if(state == GREEN && remaining_time == 0 && rand() % 2 == 0)
        {
            printf("A car is passing through the intersection.\n");
        }
    }
    
    return 0;
}