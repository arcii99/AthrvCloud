//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define states for the traffic lights
typedef enum { RED, YELLOW, GREEN } state_t;

// Define the maximum value for the counter used for timing
#define MAX_TICKS 10

// Define a struct for the traffic light
typedef struct {
    state_t state;  // current state of the light
    int counter;    // counter for timing the state
} light_t;

// Function to change the state of the traffic light
void change_state(light_t* light, state_t state) {
    light->state = state;
    light->counter = 0;
}

int main() {
    // Initialize the traffic lights
    light_t north_south, east_west;
    north_south.state = RED;
    east_west.state = GREEN;
    north_south.counter = 0;
    east_west.counter = 0;

    // Loop forever
    while (1) {
        // Print the current state of the traffic lights
        printf("North-South: ");
        switch (north_south.state) {
            case RED:
                printf("RED\n");
                break;
            case YELLOW:
                printf("YELLOW\n");
                break;
            case GREEN:
                printf("GREEN\n");
                break;
        }
        printf("East-West: ");
        switch (east_west.state) {
            case RED:
                printf("RED\n");
                break;
            case YELLOW:
                printf("YELLOW\n");
                break;
            case GREEN:
                printf("GREEN\n");
                break;
        }

        // Update the traffic lights based on their current state and counter
        switch (north_south.state) {
            case RED:
                if (north_south.counter == MAX_TICKS) {
                    change_state(&north_south, GREEN);
                } else {
                    north_south.counter++;
                }
                break;
            case YELLOW:
                if (north_south.counter == MAX_TICKS) {
                    change_state(&north_south, RED);
                    change_state(&east_west, GREEN);
                } else {
                    north_south.counter++;
                }
                break;
            case GREEN:
                if (north_south.counter == MAX_TICKS) {
                    change_state(&north_south, YELLOW);
                } else {
                    north_south.counter++;
                }
                break;
        }
        switch (east_west.state) {
            case RED:
                if (east_west.counter == MAX_TICKS) {
                    change_state(&east_west, GREEN);
                } else {
                    east_west.counter++;
                }
                break;
            case YELLOW:
                if (east_west.counter == MAX_TICKS) {
                    change_state(&east_west, RED);
                    change_state(&north_south, GREEN);
                } else {
                    east_west.counter++;
                }
                break;
            case GREEN:
                if (east_west.counter == MAX_TICKS) {
                    change_state(&east_west, YELLOW);
                } else {
                    east_west.counter++;
                }
                break;
        }

        // Wait for one second before updating again
        sleep(1);
    }

    return 0;
}