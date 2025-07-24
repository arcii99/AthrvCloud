//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

// Function to randomly generate a traffic light state
int generate_random_state() {
    int state;
    time_t t;
    srand((unsigned) time(&t));
    state = rand() % 3; // Generate random number between 0 and 2 inclusive
    return state;
}

int main() {
    int current_state, next_state, time_elapsed, remaining_time;
    current_state = generate_random_state(); // Set initial state to random value
    time_elapsed = 0; // Set initial time elapsed to 0
    
    // Display current state of traffic light
    if (current_state == RED) {
        printf("Traffic light is currently red.\n");
    } else if (current_state == YELLOW) {
        printf("Traffic light is currently yellow.\n");
    } else {
        printf("Traffic light is currently green.\n");
    }
    
    // Start simulation loop
    while (true) {
        if (time_elapsed == 0) {
            next_state = generate_random_state(); // Generate next random state
            if (next_state == current_state) {
                // If random state is the same as current state, keep same state for another cycle
                remaining_time = 5;
            } else if (current_state == RED && next_state == YELLOW) {
                // If current state is red and next state is yellow, set remaining time to 2
                remaining_time = 2;
            } else {
                // For all other state transitions, set remaining time to 5
                remaining_time = 5;
            }
        }
        
        // Display remaining time and update time elapsed
        printf("Time remaining: %d seconds\n", remaining_time - time_elapsed);
        time_elapsed++;
        
        // Wait for 1 second
        sleep(1);
        
        if (time_elapsed == remaining_time) {
            // Time elapsed equals remaining time, transition to next state
            current_state = next_state;
            time_elapsed = 0;
            if (current_state == RED) {
                printf("Traffic light is now red.\n");
            } else if (current_state == YELLOW) {
                printf("Traffic light is now yellow.\n");
            } else {
                printf("Traffic light is now green.\n");
            }
        }
    }
    
    return 0;
}