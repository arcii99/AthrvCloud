//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10 //Maximum amount of cars on the road
#define MAX_SPEED 5 //Maximum speed of cars
#define LIGHT_CYCLE 5 //Traffic light cycle time

typedef struct {
    int position;
    int speed;
} car;

int main(void) {
    car traffic[MAX_CARS]; //Array of cars on the road
    int light_counter = 0; //Counter for traffic light cycle
    int i, j;

    //Initialize random number generator
    srand(time(NULL));

    //Set initial positions and speeds for each car
    for (i = 0; i < MAX_CARS; i++) {
        traffic[i].position = rand() % 100;
        traffic[i].speed = rand() % MAX_SPEED + 1;
    }

    //Simulate traffic flow for 50 seconds
    for (i = 0; i < 50; i++) {
        //Print current state of traffic
        printf("Second %d:\n", i);
        for (j = 0; j < MAX_CARS; j++) {
            printf("Car %d position: %d, speed: %d\n", j+1, traffic[j].position, traffic[j].speed);
        }

        //Update position of each car
        for (j = 0; j < MAX_CARS; j++) {
            traffic[j].position += traffic[j].speed;

            //Check for collisions
            if (traffic[j].position >= 100) {
                printf("Car %d crashed!\n", j+1);
                return 0;
            }

            //Check for traffic light
            if (light_counter >= LIGHT_CYCLE/2 && light_counter < LIGHT_CYCLE) {
                traffic[j].speed = 0;
            } else {
                traffic[j].speed = rand() % MAX_SPEED + 1;
            }
        }

        //Update traffic light cycle
        light_counter++;
        if (light_counter == LIGHT_CYCLE) {
            light_counter = 0;
        }
    }

    printf("No accidents occurred.\n");

    return 0;
}