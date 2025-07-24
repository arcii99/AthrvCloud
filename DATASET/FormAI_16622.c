//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define constants for the time delays
#define RED_TIME 10
#define YELLOW_TIME 3
#define GREEN_TIME 15

int main() {
    // Initialize variables for the current signal state and remaining signal time
    int signal_state = RED;
    int remaining_time = RED_TIME;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Print welcome message
    printf("Welcome to the Traffic Light Controller!\n");
    
    // Loop indefinitely
    while (1) {
        // Display the current signal state
        switch (signal_state) {
            case RED:
                printf("RED LIGHT\n");
                break;
            case YELLOW:
                printf("YELLOW LIGHT\n");
                break;
            case GREEN:
                printf("GREEN LIGHT\n");
                break;
        }
        
        // Wait for 1 second
        printf("...\n");
        sleep(1);
        
        // Decrement the remaining time
        remaining_time--;
        
        // Check if the signal time has expired
        if (remaining_time == 0) {
            // Switch to the next signal state
            switch (signal_state) {
                case RED:
                    signal_state = GREEN;
                    remaining_time = GREEN_TIME;
                    break;
                case YELLOW:
                    if (rand() % 2 == 0) {
                        signal_state = RED;
                        remaining_time = RED_TIME;
                    } else {
                        signal_state = GREEN;
                        remaining_time = GREEN_TIME;
                    }
                    break;
                case GREEN:
                    signal_state = YELLOW;
                    remaining_time = YELLOW_TIME;
                    break;
            }
        }
    }

    return 0;
}