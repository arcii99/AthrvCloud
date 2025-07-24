//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 50

// car struct
typedef struct Car {
    int id;
    int speed;
    int position;
} Car;

// function declarations
void update_car_position(Car *car);
void print_traffic_flow(Car *cars, int num_cars, int time);

int main() {
    srand(time(NULL));
    
    // generate random number of cars between 1 and MAX_CARS
    int num_cars = rand() % MAX_CARS + 1;
    
    // initialize cars array with random speed between 1 and MAX_SPEED
    Car cars[num_cars];
    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i + 1;
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].position = i + 1;
    }
    
    int time = 0;
    while (time < 10) { // simulate traffic flow for 10 time units
        print_traffic_flow(cars, num_cars, time);
        for (int i = 0; i < num_cars; i++) {
            update_car_position(&cars[i]);
        }
        time++;
    }
    
    return 0;
}

// update car position function
void update_car_position(Car *car) {
    car->position += car->speed;
}

// print traffic flow function
void print_traffic_flow(Car *cars, int num_cars, int time) {
    printf("Time: %d\n", time);
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d is at position %d\n", cars[i].id, cars[i].position);
    }
    printf("\n");
}