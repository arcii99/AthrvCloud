//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 50
#define MAX_CARS 20
#define MAX_DISTANCE 1000
#define MIN_DISTANCE 100
#define GENERATE_CHANCE 10

// Struct for cars
typedef struct car {
    int speed; // car's speed in mph
    int distance; // distance from start line in ft
} car_t;

// Initialize car array with random speeds and distances
void initialize_cars(car_t *cars) {
    srand(time(NULL));
    
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i].speed = (rand() % MAX_SPEED) + 1;
        cars[i].distance = (rand() % (MAX_DISTANCE - MIN_DISTANCE + 1)) + MIN_DISTANCE;
    }
}

// Move all cars forward by 1 second
void move_cars(car_t *cars) {
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].speed > (cars[i].distance / 5280)) {
            cars[i].speed = cars[i].distance / 5280; // set speed to max
        }
        cars[i].distance += cars[i].speed * 1.46667; // convert mph to ft/s
    }
}

// Print out current positions of all cars
void print_positions(car_t *cars) {
    for (int i = 0; i < MAX_CARS; i++) {
        printf("Car #%d: Speed = %d mph, Distance = %d ft\n", i+1, cars[i].speed, cars[i].distance);
    }
}

// Generate a new car with random speed and distance
void generate_car(car_t *cars) {
    int i = 0;
    while (cars[i].speed != 0 && i < MAX_CARS) {
        i++;
    }
    if (i == MAX_CARS) { // array is full
        return;
    }
    cars[i].speed = (rand() % MAX_SPEED) + 1;
    cars[i].distance = MIN_DISTANCE;
}

int main() {
    car_t cars[MAX_CARS] = {0}; // initialize all cars to 0
    
    initialize_cars(cars);
    
    int time = 0;
    
    while (1) {
        printf("Time: %d seconds\n", time++);
        if ((rand() % 100) < GENERATE_CHANCE) {
            generate_car(cars);
        }
        move_cars(cars);
        print_positions(cars);
        printf("\n");
        if (cars[MAX_CARS-1].distance > MAX_DISTANCE) {
            printf("Race finished!\n");
            break;
        }
    }
    
    return 0;
}