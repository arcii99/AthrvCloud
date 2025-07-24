//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_SECONDS 60
#define MAX_CARS 20
#define MAX_SPEED 80
#define MIN_DISTANCE 30
#define SIMULATION_TICK 5

struct Car {
    int distance;
    int speed;
};

void simulation_tick(void);
void display_cars(void);

struct Car cars[MAX_CARS];
int seconds_elapsed = 0;

int main(void)
{
    srand(time(NULL));

    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].distance = rand() % MAX_SPEED;
        cars[i].speed = rand() % MAX_SPEED;
    }

    while (seconds_elapsed < TOTAL_SECONDS) {
        printf("Second %d:\n", seconds_elapsed);
        display_cars();
        simulation_tick();
        seconds_elapsed += SIMULATION_TICK;
    }

    return 0;
}

void simulation_tick(void)
{
    for (int i = 0; i < MAX_CARS; i++) {
        for (int j = 0; j < i; j++) {
            // Check if the distance between the cars is less than the minimum distance
            int distance_between_cars = cars[j].distance - cars[i].distance;
            if (distance_between_cars < MIN_DISTANCE) {
                // Adjust the speed of both cars
                int avg_speed = (cars[i].speed + cars[j].speed) / 2;
                cars[i].speed = avg_speed;
                cars[j].speed = avg_speed;
                // Update the position of the cars based on their speed and distance
                cars[i].distance -= cars[i].speed * SIMULATION_TICK;
                cars[j].distance += cars[j].speed * SIMULATION_TICK;
            }
        }
        // Update the position of the car based on its speed
        cars[i].distance += cars[i].speed * SIMULATION_TICK;
    }
}

void display_cars(void)
{
    for (int i = 0; i < MAX_CARS; i++) {
        printf("Car %d: position = %d, speed = %d\n", i, cars[i].distance, cars[i].speed);
    }
}