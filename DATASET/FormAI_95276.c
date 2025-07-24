//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_LANES 4

typedef struct {
    int lanes[MAX_LANES];
} Road;

int main() {
    int i, j;
    Road roads[MAX_ROADS];
    int car_count = 0;
    int total_cars = 0;
    int cars_added = 0;

    srand(time(NULL)); //seed the random number generator

    printf("Starting Traffic Flow Simulation...\n\n");

    //initialize the roads
    for(i = 0; i < MAX_ROADS; i++) {
        for(j = 0; j < MAX_LANES; j++) {
            roads[i].lanes[j] = 0;
        }
    }

    //simulate traffic flow for 10 minutes
    for(i = 0; i < 600; i++) {
        //randomly add cars to roads
        if(rand() % 10 == 0 && cars_added < 50) {
            int road_num = rand() % MAX_ROADS;
            int lane_num = rand() % MAX_LANES;

            if(roads[road_num].lanes[lane_num] == 0) {
                roads[road_num].lanes[lane_num] = 1;
                car_count++;
                cars_added++;
                total_cars++;
            }
        }

        //move cars on roads
        for(j = 0; j < MAX_ROADS; j++) {
            int k;
            for(k = 0; k < MAX_LANES; k++) {
                if(roads[j].lanes[k] == 1) {
                    if(k < MAX_LANES - 1 && roads[j].lanes[k+1] == 0) {
                        //move car to next lane
                        roads[j].lanes[k] = 0;
                        roads[j].lanes[k+1] = 1;
                    } else {
                        //car has reached end of road
                        roads[j].lanes[k] = 0;
                        car_count--;
                    }
                }
            }
        }

        //print out current traffic flow
        printf("Minute %d:\n", i+1);
        for(j = 0; j < MAX_ROADS; j++) {
            printf("Road %d: ", j+1);
            int k;
            for(k = 0; k < MAX_LANES; k++) {
                if(roads[j].lanes[k] == 1) {
                    printf(" car ");
                } else {
                    printf("     ");
                }
            }
            printf("\n");
        }
        printf("Total cars on roads: %d\n\n", car_count);

        //reset car counter
        if(i % 5 == 0) {
            cars_added = 0;
        }
    }

    printf("Simulation complete!\n");
    printf("Total cars that entered the traffic flow: %d\n", total_cars);
    printf("Total cars that left the traffic flow: %d\n", total_cars - car_count);

    return 0;
}