//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20 /* Length of the road */
#define CAR_FREQUENCY 0.5 /* Probability of a car appearing on the road */
#define SIMULATION_TIME 100 /* Simulation Time */

/* Recursive function that simulates traffic flow */
void simulate_traffic_flow(int time_elapsed, int road[ROAD_LENGTH], int car_count) {
    /* Base case */
    if (time_elapsed == SIMULATION_TIME) {
        printf("Simulation completed.\n");
        return;
    }
    
    /* Update road */
    for (int i = 0; i < ROAD_LENGTH - 1; i++) {
        if (road[i] == 1 && road[i+1] == 0) {
            road[i] = 0;
            road[i+1] = 1;
        }
    }
    
    /* Add new cars */
    srand(time(NULL));
    int spawn = rand() % 10; /* Generates a random number between 0 and 9 */
    if (spawn < CAR_FREQUENCY * 10) {
        road[0] = 1;
        car_count++;
    }
    
    /* Output current status of the road */
    printf("Time Elapsed: %d | Cars: %d | Road: ", time_elapsed, car_count);
    for (int i = 0; i < ROAD_LENGTH; i++) {
        printf("%d ", road[i]);
    }
    printf("\n");
    
    /* Recursive call */
    simulate_traffic_flow(time_elapsed+1, road, car_count);
}

int main() {
    int road[ROAD_LENGTH] = {0}; /* Initializes road to empty */
    int car_count = 0; /* Number of cars currently on the road */
    
    /* Output initial status of the road */
    printf("Time Elapsed: 0 | Cars: %d | Road: ", car_count);
    for (int i = 0; i < ROAD_LENGTH; i++) {
        printf("%d ", road[i]);
    }
    printf("\n\n");
    
    /* Start simulation */
    simulate_traffic_flow(1, road, car_count);
    
    return 0;
}