//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 1000   // Maximum number of cars on the road
#define SECONDS_PER_TICK 1  // Number of seconds that elapse in each tick of the simulation
#define TICKS_PER_HOUR 3600 / SECONDS_PER_TICK  // Number of ticks that represent one hour

// Traffic flow constants
#define FREE_FLOW_SPEED 70  // km/h
#define CONGESTION_SPEED 10  // km/h
#define MAX_DENSITY 150  // cars/km (maximum density of cars on the road)

// Car structure
struct Car {
    int speed;  // km/h
    float position;  // km
};

// Road structure
struct Road {
    float length;  // km
    int max_cars;  // Maximum number of cars that can fit on the road
    float density;  // cars/km (current density of cars on the road)
    int num_cars;  // Number of cars currently on the road
    struct Car cars[MAX_CARS];  // Array of cars on the road
};

// Function prototypes
void init_road(struct Road* road);
void add_car(struct Road* road);
void move_cars(struct Road* road);
int calculate_speed(float density);

int main() {
    struct Road road;
    int ticks = 0;

    srand(time(0));  // Seed the random number generator with the current time

    init_road(&road);

    while (1) {
        if (ticks % TICKS_PER_HOUR == 0) {
            printf("Hour %d: %d cars on the road\n", ticks / TICKS_PER_HOUR, road.num_cars);
        }

        if (rand() % 100 < 10) {
            add_car(&road);
        }

        move_cars(&road);

        if (road.num_cars == 0) {
            printf("All cars have left the road after %d hours.\n", ticks / TICKS_PER_HOUR);
            break;
        }

        ticks++;
    }

    return 0;
}

// Initializes the road structure
void init_road(struct Road* road) {
    road->length = 10;
    road->max_cars = MAX_CARS;
    road->density = 0;
    road->num_cars = 0;
}

// Adds a car to the road
void add_car(struct Road* road) {
    if (road->num_cars == road->max_cars) {
        return;
    }

    struct Car car;
    car.speed = FREE_FLOW_SPEED;
    car.position = 0;

    road->cars[road->num_cars] = car;

    road->num_cars++;
    road->density = (float) road->num_cars / road->length;
}

// Moves the cars on the road
void move_cars(struct Road* road) {
    int i;

    // Update the speed of each car based on its position and the density of cars on the road
    for (i = 0; i < road->num_cars; i++) {
        road->cars[i].speed = calculate_speed(road->density);
    }

    // Move each car forward based on its speed
    for (i = 0; i < road->num_cars; i++) {
        road->cars[i].position += road->cars[i].speed * SECONDS_PER_TICK / 3600;

        if (road->cars[i].position > road->length) {
            road->cars[i].position = road->length;
        }
    }

    // Remove any cars that have left the road
    for (i = 0; i < road->num_cars; i++) {
        if (road->cars[i].position == road->length) {
            int j;

            for (j = i; j < road->num_cars - 1; j++) {
                road->cars[j] = road->cars[j + 1];
            }

            road->num_cars--;
            road->density = (float) road->num_cars / road->length;

            i--;  // Move back one step so that we don't skip a car
        }
    }
}

// Calculates the speed of a car based on the density of cars on the road
int calculate_speed(float density) {
    if (density < 0.3 * MAX_DENSITY) {
        return FREE_FLOW_SPEED;
    } else if (density > 0.9 * MAX_DENSITY) {
        return CONGESTION_SPEED;
    } else {
        return FREE_FLOW_SPEED * (1 - (density - 0.3 * MAX_DENSITY) / (0.6 * MAX_DENSITY));
    }
}