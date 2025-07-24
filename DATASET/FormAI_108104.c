//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGHT_DURATION 120
#define MAX_CARS 100

struct Car {
    int id;
    int start_time;
    int end_time;
};

int main() {
    struct Car cars[MAX_CARS];
    int num_cars = 0;
    int timer = 0;
    int light_on = 0;
    int num_cars_crossed = 0;

    while (timer <= LIGHT_DURATION) {
        // Generate new cars
        if (rand()%2 && num_cars < MAX_CARS) {
            cars[num_cars].id = num_cars+1;
            cars[num_cars].start_time = timer;
            cars[num_cars].end_time = -1;
            num_cars++;
        }

        // Check if cars crossed the intersection
        for (int i=0; i<num_cars; i++) {
            if ((timer - cars[i].start_time >= 10) && (light_on == 1)) {
                cars[i].end_time = timer;
                num_cars_crossed++;
            }
        }

        // Print current situation
        printf("Current time: %d\n", timer);
        printf("Number of cars waiting: %d\n", num_cars-num_cars_crossed);
        printf("Number of cars crossed: %d\n", num_cars_crossed);

        if (light_on) {
            printf("Traffic light: green\n");
        } else {
            printf("Traffic light: red\n");
        }

        // Switch traffic light
        if (timer % LIGHT_DURATION == 0) {
            light_on = !light_on;
        }

        printf("----------\n");

        // Increment timer
        timer++;
    }

    printf("Simulation finished\n");

    // Print results
    printf("Number of cars waiting: %d\n", num_cars-num_cars_crossed);
    printf("Number of cars crossed: %d\n", num_cars_crossed);

    for (int i=0; i<num_cars; i++) {
        printf("Car %d crossed in %d seconds\n", cars[i].id, cars[i].end_time-cars[i].start_time);
    }

    return 0;
}