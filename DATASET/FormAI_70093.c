//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_ROADS 10

struct Car {
    int speed;
    int position;
};

struct Road {
    int length;
    int traffic_level;
    struct Car cars[MAX_CARS];
};

struct Simulation {
    struct Road roads[MAX_ROADS];
    int num_roads;
    int tick;
};

struct Car create_car(int speed) {
    struct Car car;
    car.speed = speed;
    return car;
}

struct Road create_road(int length, int traffic_level) {
    struct Road road;
    road.length = length;
    road.traffic_level = traffic_level;
    for (int i = 0; i < MAX_CARS; i++) {
        road.cars[i] = create_car(0);
    }
    return road;
}

void add_car_to_road(struct Car car, struct Road *road) {
    for (int i = 0; i < MAX_CARS; i++) {
        if (road->cars[i].speed == 0) {
            road->cars[i] = car;
            road->cars[i].position = road->length - 1;
            break;
        }
    }
}

void update_car_position(struct Car *car, int speed) {
    car->position -= speed;
}

void update_road(struct Road *road) {
    for (int i = 0; i < MAX_CARS; i++) {
        if (road->cars[i].speed > 0) {
            update_car_position(&road->cars[i], road->cars[i].speed);
        }
    }
}

void print_road(struct Road road) {
    printf("|");
    for (int i = 0; i < road.length; i++) {
        for (int j = 0; j < MAX_CARS; j++) {
            if (road.cars[j].speed > 0 && road.cars[j].position == i) {
                printf("X");
                break;
            }
            if (j == MAX_CARS - 1) {
                printf("-");
            }
        }
    }
    printf("|\n");
}

void print_simulation(struct Simulation simulation) {
    printf("Tick %d:\n", simulation.tick);
    for (int i = 0; i < simulation.num_roads; i++) {
        printf("Road %d: ", i);
        print_road(simulation.roads[i]);
    }
}

int main() {
    // Set up initial simulation state
    struct Simulation simulation;
    simulation.num_roads = 1;
    simulation.roads[0] = create_road(10, 1);
    add_car_to_road(create_car(3), &simulation.roads[0]);
    add_car_to_road(create_car(1), &simulation.roads[0]);
    add_car_to_road(create_car(2), &simulation.roads[0]);

    // Run simulation loop
    while (1) {
        // Update simulation state
        update_road(&simulation.roads[0]);
        print_simulation(simulation);
        simulation.tick++;

        // Wait a bit before running next loop
        struct timespec delay = {.tv_sec = 1, .tv_nsec = 0};
        nanosleep(&delay, NULL);
    }

    return 0;
}