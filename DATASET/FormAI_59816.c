//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int red_light = 1;
    int green_light = 0;
    int amber_light = 0;
    int cars_waiting = 0;
    int cars_passed = 0;
    int time_left = 0;
    srand((unsigned) time(NULL));

    // Welcome message
    printf("Welcome to the Verona Traffic Flow Simulation, where love and traffic never stop!\n\n");

    // Main loop
    for (int i = 1; i <= 24; i++) {
        printf("Hour %d\n", i);
        printf("--------\n");

        // Determine traffic flow and adjust lights accordingly
        int traffic_flow = rand() % 100 + 1;
        if (traffic_flow <= 40) {
            red_light = 1;
            green_light = 0;
            amber_light = 0;
            cars_waiting = 0;
            cars_passed = 0;
            printf("There is little traffic today, so the traffic lights are all red.\n");
        } else if (traffic_flow <= 70) {
            green_light = 1;
            red_light = 0;
            amber_light = 0;
            cars_waiting = rand() % 10 + 1;
            printf("Looks like it's a normal day, green light is on for %d seconds.\n", cars_waiting * 10);
        } else {
            amber_light = 1;
            green_light = 0;
            red_light = 0;
            cars_waiting = rand() % 20 + 1;
            printf("Oh no, it's rush hour! Amber light is on, %d cars are waiting.\n", cars_waiting);
        }

        // Traffic simulation loop
        while (cars_waiting > 0) {
            if (green_light) {
                time_left = cars_waiting * 10;
                for (int j = 1; j <= time_left; j++) {
                    cars_passed += rand() % 2;
                    if (cars_passed == cars_waiting) break;
                }
                cars_waiting -= cars_passed;
            } else {
                printf("Red light is on, please wait...\n");
                time_left = rand() % 5 + 1;
                for (int j = 1; j <= time_left; j++) {
                    printf(".");
                    fflush(stdout);
                    sleep(1);
                }
                printf("\nRed light is off, green light is on!\n");
            }
        }

        // Display results
        printf("At the end of hour %d, %d cars passed through the intersection.\n\n", i, cars_passed);
    }

    // Conclusion message
    printf("Thank you for using the Verona Traffic Flow Simulation, where love and traffic never stop!\n");

    return 0;
}