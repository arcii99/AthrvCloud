//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define macros for traffic light states
#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

// Declare function for displaying current traffic light state
void display_traffic_light(int current_state);

int main()
{
    // Define variables and initialize them
    int current_state = RED_LIGHT;
    int next_state;
    
    // Define variable to keep track of the time elapsed
    int elapsed_time = 0;
    int max_time = 60; // max time in seconds
    
    // Simulate the traffic light for max_time seconds
    while (elapsed_time < max_time)
    {
        // Display current traffic light state
        display_traffic_light(current_state);
        
        // Determine the next traffic light state
        switch (current_state)
        {
            case RED_LIGHT:
                next_state = GREEN_LIGHT;
                break;
            case YELLOW_LIGHT:
                next_state = RED_LIGHT;
                break;
            case GREEN_LIGHT:
                next_state = YELLOW_LIGHT;
                break;
            default:
                printf("Error: invalid state\n");
                exit(1);
        }
        
        // Wait for the appropriate amount of time to switch to the next state
        switch (current_state)
        {
            case RED_LIGHT:
                sleep(10); // wait for 10 seconds before switching to green
                break;
            case YELLOW_LIGHT:
                sleep(2); // wait for 2 seconds before switching to red
                break;
            case GREEN_LIGHT:
                sleep(15); // wait for 15 seconds before switching to yellow
                break;
            default:
                printf("Error: invalid state\n");
                exit(1);
        }
        
        // Update the current state and elapsed time
        current_state = next_state;
        elapsed_time += (current_state == YELLOW_LIGHT) ? 2 : 15; // update elapsed time depending on the state
    }
    
    // Display the final state before exiting
    display_traffic_light(current_state);
    
    return 0;
}

void display_traffic_light(int current_state)
{
    // Display the appropriate traffic light image depending on the current state
    switch (current_state)
    {
        case RED_LIGHT:
            printf("  __  \n");
            printf(" /  \\ \n");
            printf("|    |\n");
            printf("|  X |\n");
            printf("|____|\n");
            break;
        case YELLOW_LIGHT:
            printf("  __  \n");
            printf(" /  \\ \n");
            printf("|    |\n");
            printf("| /\\ |\n");
            printf("|/__\\|\n");
            break;
        case GREEN_LIGHT:
            printf("  __  \n");
            printf(" /  \\ \n");
            printf("|    |\n");
            printf("|  O |\n");
            printf("|____|\n");
            break;
        default:
            printf("Error: invalid state\n");
            exit(1);
    }
}