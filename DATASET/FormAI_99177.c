//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the traffic light states
#define RED 1
#define YELLOW 2
#define GREEN 3

// Define the timing for each state in seconds
#define RED_TIME 10
#define YELLOW_TIME 5
#define GREEN_TIME 15

int main(){
    srand(time(NULL)); // Initialize random number generator  
    
    int state = RED; // Start with red light
    int countdown = RED_TIME; // Set the timeout
    
    while (1) { // Infinite loop
        printf("Current state: ");
        if (state == RED) {
            printf("RED\n");
        } else if (state == YELLOW) {
            printf("YELLOW\n");
        } else if (state == GREEN) {
            printf("GREEN\n");
        }
        
        printf("Countdown: %d\n", countdown);
        
        if (countdown == 0) { // Check if timeout has been reached
            // Change the state depending on the current state
            if (state == RED) {
                state = GREEN;
                countdown = GREEN_TIME;
            } else if (state == YELLOW) {
                state = RED;
                countdown = RED_TIME;
            } else if (state == GREEN) {
                state = YELLOW;
                countdown = YELLOW_TIME;
            }
        }
        
        countdown--; // Decrement the countdown
        
        // Wait for a random amount of time between 1-3 seconds
        int wait_time = rand() % 3 + 1;
        printf("Waiting for %d seconds...\n\n", wait_time);
        sleep(wait_time);
    }
    
    return 0;
}