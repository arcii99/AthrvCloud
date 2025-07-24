//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100 // Maximum number of cars on the road
#define MAX_SPEED 120 // Maximum speed limit in km/h
#define MIN_DISTANCE 10 // Minimum safe distance between cars in meters
#define ROAD_LENGTH 1000 // Length of the road in meters
#define TIME_STEP 1 // Time step in seconds
#define COLOR_RED "\033[0;31m" // Color red for traffic jam
#define COLOR_RESET "\033[0m" // Reset color

// Car struct
typedef struct car {
    int id;
    int speed;
    int distance;
} car_t;

// Initialize car
void init_car(car_t* car, int id) {
    car->id = id;
    car->speed = rand() % (MAX_SPEED + 1);
    car->distance = id * MIN_DISTANCE;
}

// Update car position and speed
void update_car(car_t* car, car_t* prev_car, int time_step) {
    // Calculate safe distance
    int safe_distance = MIN_DISTANCE + car->speed * 3.6 * time_step;

    // Calculate distance to previous car
    int distance_to_prev = prev_car ? prev_car->distance - car->distance : ROAD_LENGTH - car->distance;

    // Update speed based on distance to previous car
    if (distance_to_prev < safe_distance) {
        car->speed = (int)(distance_to_prev / 3.6 / time_step) - 1;
    }

    // Calculate new distance based on speed
    car->distance = car->distance + car->speed * 3.6 * time_step;
    if (car->distance >= ROAD_LENGTH) {
        car->distance -= ROAD_LENGTH;
    }
}

// Print car on the road
void print_car(car_t* car, car_t* prev_car, int road_length) {
    if (prev_car && prev_car->distance - car->distance < MIN_DISTANCE) {
        printf(COLOR_RED);
    }

    int i;
    for (i = 0; i < car->distance; ++i) {
        printf(" ");
    }
    printf("o");
    for (i = car->distance + 1; i < prev_car ? prev_car->distance : road_length; ++i) {
        printf(" ");
    }

    printf(COLOR_RESET);
}

int main() {
    srand(time(NULL));
    car_t cars[MAX_CARS];

    // Initialize cars
    int i;
    for (i = 0; i < MAX_CARS; ++i) {
        init_car(&cars[i], i);
    }

    // Simulate traffic flow
    while (1) {
        system("clear");  // Clear console screen
        printf("Traffic Flow Simulation\n");
        printf("=======================\n\n");

        car_t* prev_car = NULL;
        for (i = 0; i < MAX_CARS; ++i) {
            update_car(&cars[i], prev_car, TIME_STEP);
            print_car(&cars[i], prev_car, ROAD_LENGTH);
            prev_car = &cars[i];
            printf("\n");
        }

        sleep(1); // Pause for 1 second before updating again
    }

    return 0;
}