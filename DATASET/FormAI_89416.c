//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20 // maximum number of cars on the road
#define MAX_SPEED 250 // maximum speed of a car in km/h
#define ROAD_LENGTH 1000 // length of the road in meters
#define SIMULATION_TIME 60 // simulation time in seconds
#define MAX_ACC 2.5 // maximum acceleration or deceleration of a car in m/s^2
#define MIN_DISTANCE 20 // minimum distance between two cars in meters
#define CAR_LENGTH 4 // length of a car in meters

// data structure for a car
typedef struct {
    double pos; // position of the car in meters
    double vel; // velocity of the car in m/s
    double acc; // acceleration of the car in m/s^2
} Car;

int main() {
    // initialize random number generator with current time as seed
    srand(time(NULL));
    Car cars[MAX_CARS];
    int num_cars = 5 + rand() % MAX_CARS; // randomly select number of cars
    // randomly initialize positions and velocities of cars
    for(int i = 0; i < num_cars; i++) {
        cars[i].pos = i * ROAD_LENGTH / num_cars;
        cars[i].vel = rand() % MAX_SPEED;
    }
    double time_step = 0.1; // time step in seconds
    int num_steps = SIMULATION_TIME / time_step;
    // simulate traffic flow for the specified time
    for(int step = 0; step < num_steps; step++) {
        // update acceleration of each car based on its distance to the car in front of it
        for(int i = 0; i < num_cars; i++) {
            double dist_to_next_car = ROAD_LENGTH;
            for(int j = 0; j < num_cars; j++) {
                if(j != i) {
                    double dist_to_car_j = cars[j].pos - cars[i].pos;
                    if(dist_to_car_j > 0 && dist_to_car_j < dist_to_next_car) {
                        dist_to_next_car = dist_to_car_j;
                    }
                }
            }
            double min_distance = MIN_DISTANCE + cars[i].vel * cars[i].vel / (2 * MAX_ACC);
            if(dist_to_next_car < min_distance) {
                cars[i].acc = -MAX_ACC;
            }
            else {
                double max_speed = sqrt(2 * MAX_ACC * (dist_to_next_car - min_distance) + cars[i].vel * cars[i].vel);
                if(max_speed > MAX_SPEED) {
                    max_speed = MAX_SPEED;
                }
                cars[i].acc = (max_speed - cars[i].vel) / time_step;
                if(cars[i].acc > MAX_ACC) {
                    cars[i].acc = MAX_ACC;
                }
            }
        }
        // update position and velocity of each car based on its acceleration
        for(int i = 0; i < num_cars; i++) {
            cars[i].vel += cars[i].acc * time_step;
            if(cars[i].vel < 0) {
                cars[i].vel = 0;
            }
            if(cars[i].vel > MAX_SPEED) {
                cars[i].vel = MAX_SPEED;
            }
            cars[i].pos += cars[i].vel * time_step;
            if(cars[i].pos > ROAD_LENGTH) {
                cars[i].pos = ROAD_LENGTH - (cars[i].pos - ROAD_LENGTH);
            }
        }
        // print current status of the road
        for(int i = 0; i < ROAD_LENGTH / CAR_LENGTH; i++) {
            int car_index = -1;
            for(int j = 0; j < num_cars; j++) {
                if(cars[j].pos >= i * CAR_LENGTH && cars[j].pos < (i + 1) * CAR_LENGTH) {
                    car_index = j;
                    break;
                }
            }
            if(car_index == -1) {
                printf("-");
            }
            else {
                printf("X");
            }
        }
        printf("\n");
    }
    return 0;
}