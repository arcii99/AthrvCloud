//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// Define Constants 
#define ROAD_LENGTH 50 
#define CAR_DENSITY 0.2 
#define MAX_SPEED 5 

// Define Struct for Cars 
typedef struct {
    int position;
    int speed;
    int max_speed;
    int is_moving;
} Car;

// Helper Function to Print Road 
void print_road(Car road[ROAD_LENGTH]) {
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (road[i].is_moving) {
            printf("C");
        } else {
            printf("-");
        }
    }
    printf("\n");
}

int main() {
    // Initialize Variables 
    Car road[ROAD_LENGTH];
    int time_step = 0;
    double percent_cars = 0.0;

    // Seed Random Number Generator 
    srand(time(0));

    // Generate Initial Cars 
    for (int i = 0; i < ROAD_LENGTH; i++) {
        percent_cars = (double) rand() / RAND_MAX;
        if (percent_cars < CAR_DENSITY) {
            road[i].is_moving = 1;
            road[i].max_speed = rand() % (MAX_SPEED + 1);
            road[i].speed = road[i].max_speed;
        } else {
            road[i].is_moving = 0;
        }
        road[i].position = i;
    }

    // Start Simulation Loop 
    while (time_step < 20) {
        // Update Car Speeds 
        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (road[i].is_moving) {
                if (i + road[i].speed < ROAD_LENGTH) {
                    road[i + road[i].speed] = road[i];
                    road[i].is_moving = 0;
                } else {
                    road[i].speed = 0;
                    road[i].is_moving = 0;
                }
            }
        }

        // Update Car Positions 
        for (int i = 0; i < ROAD_LENGTH; i++) {
            if (road[i].is_moving) {
                road[i].position += road[i].speed;
                if (road[i].position >= ROAD_LENGTH) {
                    road[i].is_moving = 0;
                }
            }
        }

        // Add New Cars to Road 
        percent_cars = (double) rand() / RAND_MAX;
        if (percent_cars < CAR_DENSITY) {
            road[0].is_moving = 1;
            road[0].max_speed = rand() % (MAX_SPEED + 1);
            road[0].speed = road[0].max_speed;
        }

        // Print Road State 
        printf("Time Step %d: ", time_step);
        print_road(road);

        // Increment Time Step 
        time_step++;
    }

    return 0;
}