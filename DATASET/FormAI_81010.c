//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    
    int num_cars = rand() % 51 + 50; // generate random number of cars between 50 and 100
    
    int* speeds = (int*)malloc(num_cars * sizeof(int)); // dynamically allocate memory for speed values
    
    printf("Initial Speeds of Cars:\n");
    for (int i = 0; i < num_cars; i++) {
        speeds[i] = rand() % 31 + 20; // generate random speed between 20 and 50 mph
        printf("Car %d: %d mph\n", i+1, speeds[i]); // print initial speed values
    }
    printf("\n");
    
    // simulate traffic flow for 60 seconds
    for (int time = 1; time <= 60; time++) {
        printf("Traffic Simulation at Time %d seconds:\n", time);
        for (int i = 0; i < num_cars; i++) {
            // calculate new speed based on car in front
            int curr_speed = speeds[i];
            int next_speed = (i == num_cars-1) ? speeds[0] : speeds[i+1];
            int new_speed = (curr_speed + next_speed) / 2;
            
            // apply random slowdown or speedup of ±2 mph
            new_speed += rand() % 5 - 2;
            if (new_speed < 20) new_speed = 20;
            else if (new_speed > 50) new_speed = 50;
            
            speeds[i] = new_speed; // update speed value
            printf("Car %d: %d mph\n", i+1, speeds[i]); // print new speed value
        }
        printf("\n");
    }
    
    free(speeds); // free allocated memory
    
    return 0;
}