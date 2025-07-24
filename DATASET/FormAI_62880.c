//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_TICKS 1000

/* Traffic light states */
enum TrafficLightState {
    RED,
    GREEN
};

/* Vehicle properties */
struct Vehicle {
    int speed;
    int braking_distance;
    int position;
};

/* Traffic light properties */
struct TrafficLight {
    enum TrafficLightState state;
    int duration;
    int remaining_ticks;
};

int main() {
    /* Seed random number generator */
    srand(time(0));

    /* Create traffic light */
    struct TrafficLight traffic_light = { RED, 10, 0 };

    /* Create vehicles */
    struct Vehicle vehicles[MAX_CARS];
    int num_cars = rand() % MAX_CARS + 1;
    for (int i = 0; i < num_cars; i++) {
        vehicles[i].speed = rand() % 10 + 1;
        vehicles[i].braking_distance = rand() % 10 + 1;
        vehicles[i].position = i * 10;
    }

    /* Simulate traffic flow */
    for (int tick = 0; tick < MAX_TICKS; tick++) {
        /* Update traffic light */
        if (traffic_light.remaining_ticks == 0) {
            traffic_light.state = (traffic_light.state == GREEN) ? RED : GREEN;
            traffic_light.remaining_ticks = traffic_light.duration;
        } else {
            traffic_light.remaining_ticks--;
        }

        /* Update vehicles */
        for (int i = 0; i < num_cars; i++) {
            if (traffic_light.state == GREEN) {
                /* Calculate distance to next vehicle */
                int distance_to_next_vehicle = 0;
                for (int j = i + 1; j < num_cars; j++) {
                    distance_to_next_vehicle = vehicles[j].position - vehicles[i].position;
                    if (distance_to_next_vehicle >= 0) {
                        break;
                    }
                }

                /* Calculate stopping distance */
                int stopping_distance = vehicles[i].speed * vehicles[i].braking_distance;

                /* Update position */
                if (distance_to_next_vehicle >= stopping_distance) {
                    vehicles[i].position += vehicles[i].speed;
                } else {
                    vehicles[i].speed = distance_to_next_vehicle / vehicles[i].braking_distance;
                    vehicles[i].position += vehicles[i].speed;
                }
            } else {
                vehicles[i].speed = 0;
            }
        }

        /* Print positions of vehicles */
        printf("Tick %d: ", tick);
        for (int i = 0; i < num_cars; i++) {
            printf("%d ", vehicles[i].position);
        }
        printf("\n");
    }

    return 0;
}