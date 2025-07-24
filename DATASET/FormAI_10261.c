//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struct representing a car
typedef struct Car {
    int id; // unique identifier for car
    int speed; // speed of car (in km/hr)
    int position; // position of car (in m)
    int lane; // lane of car (1 or 2)
    int time; // time taken by car to cross the simulation area (in seconds)
} Car;

// function to generate random integer between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int time_step = 1; // time step for simulation (in seconds)
    int simulation_time = 60; // total simulation time (in seconds)

    srand(time(NULL)); // set seed for random number generator

    // initialize variables for simulation
    int arrival_time = 0;
    int car_count = 0;
    int max_speed = 80; // maximum allowed speed (in km/hr)
    int avg_speed = 40; // average speed (in km/hr)
    int distance = 1000; // distance to be covered by car (in m)

    // main simulation loop
    for (int i = 0; i < simulation_time; i += time_step) {
        // check if new car should arrive
        if (arrival_time == i) {
            car_count++; // increment car count

            // create new car with unique id
            Car new_car;
            new_car.id = car_count;

            // randomly assign lane for car
            new_car.lane = rand_int(1, 2);

            // calculate speed of car based on lane and traffic rules
            int random_modifier = rand_int(-5, 5);
            if (new_car.lane == 1) {
                new_car.speed = avg_speed + random_modifier;
                if (new_car.speed > max_speed) {
                    new_car.speed = max_speed;
                }
            } else {
                new_car.speed = avg_speed - random_modifier;
            }

            // set initial position and time for car
            new_car.position = 0;
            new_car.time = distance / new_car.speed * 3600; // in seconds

            printf("Car %d arrived in lane %d with speed %d km/hr.\n", new_car.id, new_car.lane, new_car.speed);

            // update arrival time for next car
            arrival_time += rand_int(1, 5);
        }
    }

    return 0;
}