//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of simulation time steps
#define SIMULATION_TIME 100

// Define the length of the road (in meters)
#define ROAD_LENGTH 1000

// Define the maximum speed limit (in km/h)
#define SPEED_LIMIT 70

// Define the length of each car (in meters)
#define CAR_LENGTH 5

// Define the maximum acceleration (in m/s^2)
#define MAX_ACCELERATION 2

// Define the maximum deceleration (in m/s^2)
#define MAX_DECELERATION 2

// Define the minimum time gap (in seconds)
#define MINIMUM_TIME_GAP 2

// Define the maximum time gap (in seconds)
#define MAXIMUM_TIME_GAP 4

// Define the number of cars on the road
#define NUM_CARS 20

// Define a car struct to store information about each car
typedef struct {
    double position;  // position of the car on the road (in meters)
    double speed;     // speed of the car (in m/s)
    double acceleration; // acceleration of the car (in m/s^2)
    double time_gap; // time gap to the car in front (in seconds)
} Car;

// Define a function to initialize the car array
void initialize_cars(Car* cars) {
    int i;
    for (i = 0; i < NUM_CARS; i++) {
        cars[i].position = (double)i * ROAD_LENGTH / NUM_CARS;
        cars[i].speed = (double)SPEED_LIMIT * 1000 / 3600;  // convert km/h to m/s
        cars[i].acceleration = 0;
        cars[i].time_gap = (double)MINIMUM_TIME_GAP +
            ((double)rand() / RAND_MAX * (MAXIMUM_TIME_GAP - MINIMUM_TIME_GAP));
    }
}

// Define a function to print the current status of all the cars
void print_current_status(Car* cars) {
    int i;
    for (i = 0; i < NUM_CARS; i++) {
        printf("Car %d: position=%lf, speed=%lf, acceleration=%lf, time_gap=%lf\n", i+1, cars[i].position, cars[i].speed, cars[i].acceleration, cars[i].time_gap);
    }
}

// Define a function to simulate one time step
void simulate_one_step(Car* cars) {
    int i;
    for (i = 0; i < NUM_CARS; i++) {
        // Calculate distance to car in front
        double distance_to_front;
        if (i == NUM_CARS - 1) {  // last car
            distance_to_front = ROAD_LENGTH - cars[i].position;
        }
        else {
            distance_to_front = cars[i+1].position - cars[i].position - CAR_LENGTH;
        }

        // Calculate desired speed based on time gap
        double desired_speed = distance_to_front / cars[i].time_gap;

        // Calculate acceleration based on desired speed
        if (cars[i].speed < desired_speed) {  // accelerate
            cars[i].acceleration = MAX_ACCELERATION;
        }
        else if (cars[i].speed > desired_speed) {  // decelerate
            cars[i].acceleration = -MAX_DECELERATION;
        }
        else {  // maintain speed
            cars[i].acceleration = 0;
        }

        // Update speed and position
        cars[i].speed = cars[i].speed + cars[i].acceleration;
        if (cars[i].speed < 0) {
            cars[i].speed = 0;
        }
        if (cars[i].speed > (double)SPEED_LIMIT * 1000 / 3600) {
            cars[i].speed = (double)SPEED_LIMIT * 1000 / 3600;
        }
        cars[i].position = cars[i].position + cars[i].speed;
        if (cars[i].position > ROAD_LENGTH) {
            cars[i].position = cars[i].position - ROAD_LENGTH;
        }
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    Car cars[NUM_CARS];
    initialize_cars(cars);
    print_current_status(cars);
    int i;
    for (i = 0; i < SIMULATION_TIME; i++) {
        simulate_one_step(cars);
        printf("Time step %d:\n", i+1);
        print_current_status(cars);
    }
    return 0;
}