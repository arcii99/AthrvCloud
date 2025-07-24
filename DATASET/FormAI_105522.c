//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

#define MAX_CYCLES 10   // Number of times the traffic lights should cycle
#define GREEN_DURATION 5    // Duration of green light in seconds
#define YELLOW_DURATION 2   // Duration of yellow light in seconds
#define RED_DURATION 5  // Duration of red light in seconds

// Function to simulate the traffic light colors
void simulate_traffic_light(int color, int duration) {
    switch (color) {
        case 0:
            printf("\nGreen Light\n");
            sleep(duration);
            break;
        case 1:
            printf("\nYellow Light\n");
            sleep(duration);
            break;
        case 2:
            printf("\nRed Light\n");
            sleep(duration);
            break;
    }
}

int main() {
    int current_cycle = 1;
    uint8_t current_color = 0;  // Index of the current color, 0-Green, 1-Yellow, 2-Red.

    srand(time(0));    // Seed the random generator

    printf("Traffic Light Controller\n");

    // Main loop to run the traffic light controller
    while (current_cycle <= MAX_CYCLES) {
        printf("Cycle: %d\n", current_cycle);

        // Simulate green light
        simulate_traffic_light(current_color % 3, GREEN_DURATION);

        // Simulate yellow light
        current_color++;
        simulate_traffic_light(current_color % 3, YELLOW_DURATION);

        // Simulate red light
        current_color++;
        simulate_traffic_light(current_color % 3, RED_DURATION);

        current_color++;    // Move to the next color for the next cycle
        current_cycle++;    // Increment cycle count
    }

    printf("End of simulation\n");

    return 0;
}