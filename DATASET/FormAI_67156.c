//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20
#define CAR_LENGTH 2
#define MAX_CARS 10

// function to print the road
void print_road(int road[]);

int main()
{
    int road[ROAD_LENGTH] = {0}; // initialize the road with 0s (empty road)
    int num_cars = 0; // initialize the number of cars on the road to 0

    srand(time(NULL)); // seed the random number generator with the current time

    // loop through the simulation for 50 steps
    for(int i = 0; i < 50; i++) {
        // add a new car with 50% probability if there is space on the road
        if(num_cars < MAX_CARS && road[0] == 0 && rand() % 2 == 0) {
            road[0] = CAR_LENGTH;
            num_cars++;
        }

        // move all cars forward by 1 if there is space in front of them
        for(int j = ROAD_LENGTH - 1; j >= 0; j--) {
            if(road[j] == CAR_LENGTH && j < ROAD_LENGTH - 1 && road[j+1] == 0) {
                road[j] = 0;
                road[j+1] = CAR_LENGTH;
            }
        }

        // randomly slow down cars with a probability of 10%
        for(int j = ROAD_LENGTH - 1; j >= 0; j--) {
            if(road[j] == CAR_LENGTH && j < ROAD_LENGTH - 1 && road[j+1] > 0 && rand() % 10 == 0) {
                road[j] = 0;
                road[j+1] = CAR_LENGTH;
            }
        }

        // print the state of the road
        print_road(road);
    }

    return 0;
}

void print_road(int road[])
{
    for(int i = 0; i < ROAD_LENGTH; i++) {
        if(road[i] == 0) {
            printf("-");
        } else {
            printf("X");
        }
    }
    printf("\n");
}