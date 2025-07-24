//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define states for traffic light
typedef enum {
    RED, 
    YELLOW, 
    GREEN
} traffic_state;

// Function to print traffic light state
void print_traffic_light(traffic_state state) {
    printf("\n*************\n");
    switch (state) {
        case RED:
            printf("RED LIGHT ON\n");
            break;
        case YELLOW:
            printf("YELLOW LIGHT ON\n");
            break;
        case GREEN:
            printf("GREEN LIGHT ON\n");
            break;
        default:
            printf("INVALID STATE\n");
            break;
    }
    printf("*************\n");
}

int main() {
    // Initiate traffic light state as red
    traffic_state state = RED;
    
    // Initiate timer for random state change
    time_t t;
    srand((unsigned) time(&t));
    int rand_time;
    
    // Main loop to process traffic light
    while (true) {
        // Print current state and wait for some time
        print_traffic_light(state);
        rand_time = rand() % 10 + 3;  // Random wait time between 3-12 seconds
        printf("Next state in %d seconds...\n", rand_time);
        sleep(rand_time);
        
        // Change state based on current state
        switch (state) {
            case RED:
                state = GREEN;
                break;
            case YELLOW:
                state = RED;
                break;
            case GREEN:
                state = YELLOW;
                break;
            default:
                printf("INVALID STATE\n");
                return 1;
        }
    }
    
    return 0;
}