//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the size of the road and the number of vehicles
#define ROAD_SIZE 50
#define NUM_VEHICLES 10

// define the speed limit
#define SPEED_LIMIT 50

// define the probability of a vehicle moving forward
#define FORWARD_PROBABILITY 0.7

// define the maximum speed a vehicle can travel at
#define MAX_SPEED 5

// define the maximum time a vehicle can wait at a red light
#define MAX_WAIT_TIME 5

// define the duration of a traffic light cycle
#define LIGHT_CYCLE 10

// define the number of cycles to simulate
#define NUM_CYCLES 100

// structure to store information about a vehicle
typedef struct Vehicle {
    int position;
    int speed;
    int wait_time;
} Vehicle;

// initialize the vehicles on the road
void init_vehicles(Vehicle* vehicles) {
    int i;

    for (i = 0; i < NUM_VEHICLES; i++) {
        vehicles[i].position = i * ROAD_SIZE / NUM_VEHICLES;
        vehicles[i].speed = 0;
        vehicles[i].wait_time = 0;
    }
}

// compute the new position of a vehicle
int compute_new_position(Vehicle* vehicle) {
    int new_position = vehicle->position + vehicle->speed;

    if (new_position >= ROAD_SIZE) {
        new_position = 0;
    }

    return new_position;
}

// update the speed of a vehicle
void update_speed(Vehicle* vehicle, int distance) {
    if (distance <= vehicle->speed) {
        vehicle->speed = distance - 1;
    } else if (distance < SPEED_LIMIT) {
        vehicle->speed = distance - 1;
    } else {
        vehicle->speed = SPEED_LIMIT;
    }
}

// update the position and speed of a vehicle based on the surrounding traffic
void update_vehicle(Vehicle* vehicle, Vehicle* prev_vehicle, int light_status) {
    int distance;

    if (light_status == 0 && vehicle->wait_time == 0) {  // green light
        distance = prev_vehicle->position - vehicle->position;

        if (distance < 0) {
            distance += ROAD_SIZE;
        }

        update_speed(vehicle, distance);

        if (vehicle->speed > 0 && (double) rand() / RAND_MAX < FORWARD_PROBABILITY) {
            vehicle->position = compute_new_position(vehicle);
        }
    } else {  // red light or waiting at a red light
        vehicle->speed = 0;

        if (light_status == 1) {
            vehicle->wait_time++;

            if (vehicle->wait_time > MAX_WAIT_TIME) {
                vehicle->wait_time = 0;
            }
        }
    }
}

// print the current state of the road and vehicles
void print_state(Vehicle* vehicles, int light_status) {
    int i, j;
    char road[ROAD_SIZE];

    for (i = 0; i < ROAD_SIZE; i++) {
        road[i] = '-';
    }

    for (i = 0; i < NUM_VEHICLES; i++) {
        road[vehicles[i].position] = 'a' + i;
    }

    printf("\n");

    for (i = 0; i < ROAD_SIZE; i++) {
        printf("%c", road[i]);
    }

    printf(" %d\n", light_status);
}

// simulate one cycle of the traffic flow
void simulate_cycle(Vehicle* vehicles, int* light_status) {
    int i;

    print_state(vehicles, *light_status);

    for (i = 0; i < NUM_VEHICLES; i++) {
        update_vehicle(&vehicles[i], &vehicles[(i - 1 + NUM_VEHICLES) % NUM_VEHICLES], *light_status);
    }

    if (*light_status == 0) {
        if (vehicles[NUM_VEHICLES - 1].position == ROAD_SIZE - 1 && vehicles[NUM_VEHICLES - 1].speed == 0) {
            *light_status = LIGHT_CYCLE - 1;
        }
    } else {
        *light_status = *light_status - 1;
    }
}

// main function
int main() {
    Vehicle vehicles[NUM_VEHICLES];
    int light_status = 0;
    int i;

    srand(time(NULL));

    init_vehicles(vehicles);

    for (i = 0; i < NUM_CYCLES; i++) {
        simulate_cycle(vehicles, &light_status);
    }

    return 0;
}