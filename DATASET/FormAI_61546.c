//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Define constant variables */
#define ROAD_LENGTH 10
#define TIME_STEP 1
#define MAX_SPEED 5
#define CAR_DENSITY 0.2

/* Function to randomly generate cars */
/* Returns 1 if car is present, 0 if no car */
int has_car(){
    if((float)(rand())/RAND_MAX < CAR_DENSITY){
        return 1;
    }else{
        return 0;
    }
}

/* Function to print the status of the road */
void print_road(int *road){
    printf("|");
    for(int i = 0; i < ROAD_LENGTH; i++){
        if(road[i] == 1){
            printf("C|");
        }else{
            printf("_|");
        }
    }
    printf("\n");
}

/* Function to update the position of cars on the road */
void update_road(int *road, int time, int *num_cars, int *num_cars_moved){
    /* Move the cars forward if allowed */
    for(int i = ROAD_LENGTH-1; i >= 0; i--){
        if(road[i] == 1){
            if(i + MAX_SPEED*time > ROAD_LENGTH-1){
                road[i] = 0;
            }else{
                road[i+MAX_SPEED*time] = 1;
                road[i] = 0;
                (*num_cars_moved)++;
            }
        }
    }
    /* Add new cars to the front of the road */
    if(time == 0){
        for(int i = 0; i < ROAD_LENGTH; i++){
            if(has_car() && road[i] == 0){
                road[i] = 1;
                (*num_cars)++;
            }
        }
    }
}

int main(){
    srand(time(NULL)); // Seed random number generator

    /* Initialize road */
    int road[ROAD_LENGTH];
    for(int i = 0; i < ROAD_LENGTH; i++){
        road[i] = 0;
    }

    /* Initialize variables */
    int t = 0;
    int num_cars = 0;
    int num_cars_moved = 0;

    /* Main loop */
    printf("Initial road:\n");
    print_road(road);
    while(num_cars < ROAD_LENGTH){
        printf("t = %d | ", t);
        update_road(road, t, &num_cars, &num_cars_moved);
        print_road(road);
        printf("Moved %d cars\n", num_cars_moved);
        num_cars_moved = 0;
        t += TIME_STEP;
    }

    return 0;
}