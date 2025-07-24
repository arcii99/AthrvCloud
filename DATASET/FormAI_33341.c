//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SIM_TIME 60

int cars_on_road = 0;
int total_cars_counted = 0;
int total_cars_passed = 0;
int total_cars_stopped = 0;

double arrival_rate = 0.5;
double percent_cars_south = 0.5;
double south_to_north_flow_rate = 0.2;
double north_to_south_flow_rate = 0.2;

// Function to randomly generate a car's direction
int get_car_direction() {
    double probability = (double) rand() / (double) RAND_MAX;
    if (probability <= percent_cars_south) {
        return 0; // car goes North to South (0)
    } else {
        return 1; // car goes South to North (1)
    }
}

// Function to calculate whether a car stops or passes
bool car_passes() {
    double probability = (double) rand() / (double) RAND_MAX;
    if (probability <= south_to_north_flow_rate && cars_on_road > 0) {
        return false; // car stops
    } else if (probability <= north_to_south_flow_rate && cars_on_road <= MAX_CARS) {
        return true; // car passes
    } else {
        return false; // car stops
    }
}

// Function to update total counts
void update_counts(int direction, bool passed) {
    total_cars_counted++;
    if (direction == 0) { // car goes North to South
        if (passed) {
            total_cars_passed++;
        } else {
            total_cars_stopped++;
        }
    } else { // car goes South to North
        if (passed) {
            total_cars_passed++;
        } else {
            total_cars_stopped++;
        }
    }
}

// Function to simulate a car passing or stopping at the intersection
void simulate_car_passing(int direction) {
    if (car_passes()) {
        cars_on_road++;
        update_counts(direction, true);
    } else {
        update_counts(direction, false);
    }
}

// Function to simulate car arrivals at the intersection
void simulate_cars_arrival() {
    int direction;
    for (int i = 0; i < MAX_CARS; i++) {
        direction = get_car_direction();
        simulate_car_passing(direction);
    }
}

// Function to simulate one minute of traffic flow
void simulate_one_minute() {
    cars_on_road = 0;
    simulate_cars_arrival();
}

int main() {
    srand(time(NULL));
    printf("Starting Traffic Flow Simulation for %d minutes...\n", MAX_SIM_TIME);
    printf("--------------------------------------------------------\n");
    for (int i = 1; i <= MAX_SIM_TIME; i++) {
        printf("\nMinute %d:\n", i);
        simulate_one_minute();
        printf("Total cars counted: %d\n", total_cars_counted);
        printf("Total cars passed: %d\n", total_cars_passed);
        printf("Total cars stopped: %d\n", total_cars_stopped);
        printf("Cars on road at the end of the minute: %d\n", cars_on_road);
    }
    printf("--------------------------------------------------------\n");
    printf("Simulation Completed\n");
    printf("Total cars counted: %d\n", total_cars_counted);
    printf("Total cars passed: %d\n", total_cars_passed);
    printf("Total cars stopped: %d\n", total_cars_stopped);
    printf("Final cars on road: %d\n", cars_on_road);
    return 0;
}