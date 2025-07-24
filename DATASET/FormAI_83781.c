//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define GREEN 1

int main() {
    int total_cars = 0, total_time = 0;
    int north_south = GREEN, east_west = RED;
    int num_cars_ns = 0, num_cars_ew = 0;
    int time_ns = 0, time_ew = 0;
    int i, j;

    srand(time(0));

    printf("Welcome to Traffic Flow Simulation\n");

    for (i = 0; i < 5; i++) { // simulation runs for 5 minutes

        printf("\nSimulation time: %d minute(s)\n", i + 1);

        // Generate random cars
        num_cars_ns += (rand() % 6); // maximum of 5 cars per minute
        num_cars_ew += (rand() % 6);

        printf("%d cars arrive from North-South direction\n", num_cars_ns);
        printf("%d cars arrive from East-West direction\n", num_cars_ew);

        // Calculate waiting time
        if (north_south == GREEN) {
            time_ns += (num_cars_ns * 2); // each car takes 2 minutes to pass
            num_cars_ns = 0;
        } else {
            time_ew += (num_cars_ew * 2);
            num_cars_ew = 0;
        }

        // Switch traffic lights
        if ((i + 1) % 3 == 0) { // switch every 3 minutes
            north_south = !north_south;
            east_west = !east_west;
            printf("Traffic lights switched\n");
        }

        // Display current status
        printf("North-South lights: %s\n", (north_south == GREEN) ? "GREEN" : "RED");
        printf("East-West lights: %s\n", (east_west == GREEN) ? "GREEN" : "RED");

        // Display waiting time and total cars passed
        printf("North-South waiting time: %d minute(s)\n", time_ns);
        printf("East-West waiting time: %d minute(s)\n", time_ew);
        total_cars += (time_ns / 2) + (time_ew / 2); // each half minute counts as 1 car
        printf("Total cars passed: %d\n", total_cars);
        total_time = i + 1;
    }

    // Display final results
    printf("\nSimulation finished after %d minute(s)\n", total_time);
    printf("Total cars passed: %d\n", total_cars);
    printf("North-South waiting time: %d minute(s)\n", time_ns);
    printf("East-West waiting time: %d minute(s)\n", time_ew);

    return 0;
}