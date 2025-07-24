//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LEN 20
#define NUM_CARS 4
#define MAX_SPEED 5
#define PROB_SLOWDOWN 0.3

int get_rand(int max) {
    return rand() % max;
}

void print_road(int road[], int cars) {
    printf("  ");
    for(int i=0; i<ROAD_LEN; i++) {
        printf("-");
    }
    printf("\n|");
    for(int i=0; i<ROAD_LEN; i++) {
        if(road[i] == -1) {
            printf(" ");
        } else {
            printf("%d",road[i]);
        }
    }
    printf("|\n  ");
    for(int i=0; i<ROAD_LEN; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    printf("Starting Traffic Flow Simulation...\n");
    // initialize road
    int road[ROAD_LEN];
    for(int i=0; i<ROAD_LEN; i++) {
        road[i] = -1;
    }
    // initialize cars
    for(int i=0; i<NUM_CARS; i++) {
        road[i] = get_rand(MAX_SPEED) + 1;
    }
    printf("Initial State:\n");
    print_road(road, NUM_CARS);
    int time = 0;
    while(true) {
        printf("Time: %d\n", time);
        bool has_moved[NUM_CARS] = {false};
        // move cars
        for(int i=0; i<ROAD_LEN; i++) {
            if(road[i] != -1) {
                int speed = road[i];
                // check if car will slow down
                if(i+speed < ROAD_LEN && road[i+speed] != -1) {
                    double rand_num = (double)get_rand(100) / 100;
                    if(rand_num < PROB_SLOWDOWN) {
                        speed--;
                    }
                }
                // move car
                if(i+speed >= ROAD_LEN) {
                    road[i] = -1;
                } else {
                    road[i+speed] = road[i];
                    road[i] = -1;
                    has_moved[i] = true;
                }
            }
        }
        print_road(road, NUM_CARS);
        // check if all cars have moved off the road
        bool all_off = true;
        for(int i=0; i<NUM_CARS; i++) {
            if(has_moved[i]) {
                all_off = false;
            }
        }
        if(all_off) {
            printf("All cars have moved off the road.\n");
            break;
        }
        time++;
        printf("\n");
    }
    printf("Total time: %d\n", time);
    printf("Exiting Traffic Flow Simulation...\n");
    return 0;
}