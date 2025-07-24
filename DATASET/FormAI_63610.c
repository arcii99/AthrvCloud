//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARS 10
#define SECONDS_IN_HOUR 3600
#define SIMULATION_TIME 1200

void sleep(unsigned int seconds) {
    clock_t goal = seconds * CLOCKS_PER_SEC + clock();
    while (goal > clock());
}

struct Car {
    int speed;
    int distance_from_intersection;
    int time_until_arrival;
};

void get_traffic_info(struct Car traffic[]) {
    for (int i = 0; i < CARS; i++) {
        traffic[i].distance_from_intersection = rand() % 1000 + 1; // generate random distance between 1 and 1000 meters
        traffic[i].time_until_arrival = rand() % 3600 + 1; // generate random time between 1 and 3600 seconds
        traffic[i].speed = traffic[i].distance_from_intersection / traffic[i].time_until_arrival; // calculate speed
    }
}

void simulate_traffic_flow(struct Car traffic[]) {
    int seconds_elapsed = 0;
    
    while (seconds_elapsed < SIMULATION_TIME) {
        printf("Time: %d seconds\n", seconds_elapsed);
        
        for (int i = 0; i < CARS; i++) {
            if (traffic[i].distance_from_intersection > 0) {
                traffic[i].distance_from_intersection -= traffic[i].speed; // update position of car based on speed
                printf("Car %d position: %d\n", i+1, traffic[i].distance_from_intersection);
                
                if (traffic[i].distance_from_intersection <= 0) {
                    printf("Car %d has passed the intersection.\n", i+1);
                }
            }
        }
        
        printf("\n");
        sleep(1);
        seconds_elapsed++;
    }
}

int main() {
    srand(time(NULL));
    struct Car traffic[CARS];
    
    get_traffic_info(traffic);
    simulate_traffic_flow(traffic);
    
    return 0;
}