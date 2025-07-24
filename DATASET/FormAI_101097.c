//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 80
#define MAX_CARS 40
#define MAX_CARS_PER_LANE 10

typedef struct Car {
    int speed;
    int distance_traveled;
} Car;

Car traffic_lanes[3][MAX_CARS_PER_LANE];
int num_cars_in_lane[3];

void move_cars() {
    int lane, car;

    // Move cars forward
    for (lane = 0; lane < 3; lane++) {
        for (car = 0; car < num_cars_in_lane[lane]; car++) {
            if (car == 0) {
                // The first car in the lane is at the front and can go as fast as it wants
                traffic_lanes[lane][car].speed = MAX_SPEED;
            } else {
                int distance_to_front = traffic_lanes[lane][car-1].distance_traveled - traffic_lanes[lane][car].distance_traveled;

                // If the car in front is too close, adjust the speed accordingly
                if (distance_to_front < traffic_lanes[lane][car].speed) {
                    traffic_lanes[lane][car].speed = distance_to_front;
                } else {
                    traffic_lanes[lane][car].speed = MAX_SPEED;    
                }
            }

            // Move the car forward based on its speed
            traffic_lanes[lane][car].distance_traveled += traffic_lanes[lane][car].speed;
        }
    }
}

void add_car(int lane) {
    if (num_cars_in_lane[lane] < MAX_CARS_PER_LANE) {
        Car new_car;
        new_car.speed = rand() % (MAX_SPEED + 1);
        new_car.distance_traveled = 0;

        traffic_lanes[lane][num_cars_in_lane[lane]] = new_car;
        num_cars_in_lane[lane]++;
    }
}

int main() {
    int time_step, lane;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the traffic lanes with random cars
    for (lane = 0; lane < 3; lane++) {
        int num_cars = rand() % (MAX_CARS_PER_LANE + 1);
        int car;

        for (car = 0; car < num_cars; car++) {
            Car new_car;
            new_car.speed = rand() % (MAX_SPEED + 1);
            new_car.distance_traveled = rand() % (1000 + 1);

            traffic_lanes[lane][car] = new_car;
        }

        num_cars_in_lane[lane] = num_cars;
    }

    // Simulate the traffic flow for 10 minutes (600 time steps)
    for (time_step = 0; time_step < 600; time_step++) {
        int lane;

        // Add a new car to a random lane with probability 0.1
        if (rand() % 10 == 0) {
            int lane_to_add_car = rand() % 3;
            add_car(lane_to_add_car);
        }

        // Move all the cars forward
        move_cars();

        // Print the position of each car in each lane
        printf("Time step %d:\n", time_step);
        for (lane = 0; lane < 3; lane++) {
            printf("Lane %d: ", lane);
            int car;
            for (car = 0; car < num_cars_in_lane[lane]; car++) {
                printf("%d ", traffic_lanes[lane][car].distance_traveled);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}