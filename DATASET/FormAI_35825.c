//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CARS 100
#define SIMULATION_TIME 3600

typedef struct {
    int car_id;
    int arrival_time;
    int entry_time;
    int exit_time;
} Car;

int main() {
    Car cars[MAX_CARS];
    int num_cars, car_counter = 0;
    int current_time = 0, total_cars_passed = 0;
    int average_wait_time = 0, total_wait_time = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random number of cars
    num_cars = rand() % MAX_CARS + 1;

    // Simulate for SIMULATION_TIME seconds
    while (current_time < SIMULATION_TIME) {
        // Check if a car has arrived at the traffic light
        int r = rand() % 101; // Generate a random number between 0-100
        if (r < 30) { // 30% probability of a car arriving
            if (car_counter < num_cars) { // If there is space for the car
                cars[car_counter].car_id = car_counter + 1;
                cars[car_counter].arrival_time = current_time;
                car_counter++;
            }
        }

        // Check if a car can pass through the traffic light
        if (cars[0].entry_time == 0 && car_counter > 0) {
            cars[0].entry_time = current_time;
            total_cars_passed++;
            total_wait_time += current_time - cars[0].arrival_time;
            average_wait_time = total_wait_time / total_cars_passed;
            for (int i = 0; i < car_counter; i++) {
                cars[i] = cars[i + 1];
            }
            car_counter--;
        }

        // Increment time
        current_time++;
    }

    // Print simulation results
    printf("Simulation Results\n");
    printf("Total number of cars: %d\n", num_cars);
    printf("Total cars passed through: %d\n", total_cars_passed);
    printf("Average wait time: %d seconds\n", average_wait_time);

    return 0;
}