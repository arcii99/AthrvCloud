//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator

    // Define variables for simulation
    int num_cars = rand() % 101; // Randomly generate number of cars between 0 and 100
    int num_lanes = rand() % 4 + 2; //Randomly generate number of lanes between 2 and 5
    int num_minutes = rand() % 31 + 30; //Randomly generate number of minutes between 30 and 60
    
    // Define arrays for each lane and initialize to 0
    int lanes[num_lanes][num_minutes];
    for(int i = 0; i < num_lanes; i++) {
        for(int j = 0; j < num_minutes; j++) {
            lanes[i][j] = 0; 
        }
    }

    // Simulate cars entering the lanes
    int total_cars = num_cars;
    while(total_cars > 0) {
        int lane_choice = rand() % num_lanes; // Randomly choose a lane for the car to enter
        if(lanes[lane_choice][0] == 0) { // Check if the first minute in the lane is empty
            lanes[lane_choice][0] = 1; // Add car to lane
            total_cars--; // Reduce number of remaining cars
        }
    }
    
    // Simulate traffic flow for each minute
    printf("Time |");
    for(int i = 0; i < num_lanes; i++) {
        printf(" Lane %d |", i+1);
    }
    printf("\n");
    for(int i = 0; i < num_minutes; i++) {
        printf("%4d |", i+1);
        for(int j = 0; j < num_lanes; j++) {
            int car_count = 0;
            if(lanes[j][i] == 1) {
                car_count++; // Count the car in the current minute
            }
            if(i > 0 && lanes[j][i-1] == 1) {
                lanes[j][i-1] = 0; // Remove the car from the previous minute
            }
            if(i < num_minutes-1 && lanes[j][i+1] == 0 && rand() % 2 == 0 && car_count == 1) {
                // Move the car to the next minute and next lane with 50% probability if the next minute is empty and there is only 1 car in this minute
                lanes[j][i] = 0;
                lanes[j][i+1] = 1;
                j++; // Skip the next lane since the car moved to it
            }
            printf("%7d |", car_count);
        }
        printf("\n");
    }
    
    return 0;
}