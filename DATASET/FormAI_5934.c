//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 10
#define MAX_CARS 3

// Car struct to hold information about each car
typedef struct car {
    int position;
    int speed;
} Car;

// Print the current state of the road with the cars
void print_road(Car *road) {
    printf("Current State of the Road:\n");
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (road[i].speed == 0) {
            printf("-");
        } else {
            printf("%d", road[i].speed);
        }
    }
    printf("\n");
}

// Move each car on the road
void move_cars(Car *road) {
    // Move each car forwards
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (road[i].speed > 0) {
            // Move the car forwards
            road[i+road[i].speed].speed = road[i].speed;
            road[i+road[i].speed].position = i+road[i].speed;
            road[i].speed = 0;
        }
    }

    // Slow each car down if possible
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (road[i].speed > 0) {
            // Calculate the new speed of the car
            int new_speed = road[i].speed - 1;

            // Check if there is a car in front
            for (int j = 1; j <= new_speed; j++) {
                if (i+j >= ROAD_LENGTH) {
                    break;
                }

                if (road[i+j].speed > 0) {
                    new_speed = j - 1;
                    break;
                }
            }

            // Set the new speed of the car
            road[i+new_speed].speed = new_speed;
            road[i+new_speed].position = i+new_speed;
            road[i].speed = 0;
        }
    }

    // Accelerate each car if possible
    for (int i = 0; i < ROAD_LENGTH; i++) {
        if (road[i].speed < MAX_CARS) {
            // Check if there is space in front
            int free_space = 1;
            for (int j = i+1; j <= i+road[i].speed; j++) {
                if (j >= ROAD_LENGTH) {
                    break;
                }

                if (road[j].speed > 0) {
                    free_space = 0;
                    break;
                }
            }

            // Accelerate the car if there is space
            if (free_space) {
                road[i+road[i].speed+1].speed = road[i].speed + 1;
                road[i+road[i].speed+1].position = i+road[i].speed+1;
                road[i].speed = 0;
            }
        }
    }
}

int main() {
    // Initialize the random number generator
    srand((unsigned int) time(NULL));

    // Initialize the road
    Car road[ROAD_LENGTH];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i].position = i;
        road[i].speed = 0;
    }

    // Add some cars to the road
    for (int i = 0; i < MAX_CARS; i++) {
        int pos = rand() % (ROAD_LENGTH-1);
        if (road[pos].speed == 0) {
            road[pos].speed = rand() % MAX_CARS + 1;
        } else {
            i--;
        }
    }

    // Print the initial state of the road
    print_road(road);

    // Simulate the traffic flow
    for (int i = 0; i < 10; i++) {
        move_cars(road);
        print_road(road);
    }

    return 0;
}