//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SPEED 4

int main()
{
    srand(time(NULL));
    int road_length = 10; // length of the road
    int car_density = 3; // number of cars per 10 spaces
    int car_speeds[road_length]; // speeds of each car
    int i, j, step;

    // assign initial speeds to cars randomly
    for(i = 0; i < road_length; i++) {
        if(rand() % car_density == 0) {
            car_speeds[i] = rand() % (MAX_SPEED + 1);
        }
        else {
            car_speeds[i] = -1; // no car here
        }
    }

    // run the simulation for 20 steps
    for(step = 0; step < 20; step++) {
        // display the current state of the road
        for(i = 0; i < road_length; i++) {
            if(car_speeds[i] == -1) {
                printf(".");
            }
            else {
                printf("%d", car_speeds[i]);
            }
        }
        printf("\n");

        // accelerate cars if possible
        for(i = 0; i < road_length; i++) {
            if(car_speeds[i] == -1) {
                continue;
            }
            if(car_speeds[i] < MAX_SPEED) {
                car_speeds[i]++;
            }
        }

        // move cars forward
        for(i = 0; i < road_length; i++) {
            if(car_speeds[i] == -1) {
                continue;
            }
            int distance = 0;
            for(j = i+1; j < road_length; j++) {
                if(car_speeds[j] != -1) {
                    distance = j-i;
                    break;
                }
            }
            if(distance > car_speeds[i]) {
                distance = car_speeds[i];
            }
            if(distance > 0) {
                car_speeds[i+distance] = car_speeds[i];
                car_speeds[i] = -1;
            }
        }
    }

    return 0;
}